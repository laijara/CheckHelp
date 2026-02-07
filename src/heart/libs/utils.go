package libs

import (
	"fmt"
	"os"
	"os/exec"
	"runtime"
	"syscall"
	"unsafe"
)

// --- Блок Windows API для очистки без мерцания ---
var (
	kernel32                 = syscall.NewLazyDLL("kernel32.dll")
	procGetStdHandleFunc     = kernel32.NewProc("GetStdHandle")
	procGetConsoleScreenBuf  = kernel32.NewProc("GetConsoleScreenBufferInfo")
	procSetConsoleCursorPos  = kernel32.NewProc("SetConsoleCursorPosition")
	procFillConsoleOutputCh  = kernel32.NewProc("FillConsoleOutputCharacterW")
	procFillConsoleOutputAtt = kernel32.NewProc("FillConsoleOutputAttribute")
	procSetConsoleTitle      = kernel32.NewProc("SetConsoleTitleW")
)

const (
	stdOutputHandle = uint32(0xFFFFFFF5) // -11
)

type coord struct {
	X, Y int16
}

type smallRect struct {
	Left, Top, Right, Bottom int16
}

type consoleScreenBufferInfo struct {
	Size              coord
	CursorPosition    coord
	Attributes        uint16
	Window            smallRect
	MaximumWindowSize coord
}

// Запуск системных команд
func runCommand(command string, args ...string) {
	cmd := exec.Command(command, args...)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.Stdin = os.Stdin

	err := cmd.Run()
	if err != nil {
		fmt.Printf("Ошибка выполнения: %v\n", err)
	}
}

// Установка заголовка окна
func setConsoleTitle(title string) {
	if runtime.GOOS == "windows" {
		ptr, _ := syscall.UTF16PtrFromString(title)
		procSetConsoleTitle.Call(uintptr(unsafe.Pointer(ptr)))
	}
}

// Очистка консоли через Windows API (БЕЗ МЕРЦАНИЯ)
func clearConsole() {
	if runtime.GOOS != "windows" {
		fmt.Print("\033[H\033[2J")
		return
	}

	hConsole, _, _ := procGetStdHandleFunc.Call(uintptr(stdOutputHandle))
	if hConsole == 0 {
		// Если не удалось получить доступ к консоли, просто делаем отступы
		fmt.Println("\n\n\n\n\n")
		return
	}

	var csbi consoleScreenBufferInfo
	ret, _, _ := procGetConsoleScreenBuf.Call(hConsole, uintptr(unsafe.Pointer(&csbi)))
	if ret == 0 {
		return
	}

	conSize := uint32(csbi.Size.X) * uint32(csbi.Size.Y)
	var charsWritten uint32

	// Заполняем символами пробела
	procFillConsoleOutputCh.Call(hConsole, uintptr(' '), uintptr(conSize), 0, uintptr(unsafe.Pointer(&charsWritten)))
	// Сбрасываем цвета
	procFillConsoleOutputAtt.Call(hConsole, uintptr(csbi.Attributes), uintptr(conSize), 0, uintptr(unsafe.Pointer(&charsWritten)))
	// Ставим курсор в 0,0
	procSetConsoleCursorPos.Call(hConsole, 0)
}

// БЕЗОПАСНАЯ проверка прав администратора
func isAdmin() bool {
	if runtime.GOOS == "windows" {
		// Команда "net session" работает только у администратора.
		// Это безопасный способ проверки, который не вызывает подозрений у антивируса.
		_, err := exec.Command("net", "session").Output()
		return err == nil
	}
	return os.Geteuid() == 0
}
