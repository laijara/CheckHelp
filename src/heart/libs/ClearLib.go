package libs

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func cleanStart() {
	for {
		clearConsole()
		outputClean()

		reader := bufio.NewReader(os.Stdin)
		var input string
		var a int
		var err error

		for {
			input, _ = reader.ReadString('\n')
			input = strings.TrimSpace(input)

			a, err = strconv.Atoi(input)
			if err == nil {
				break
			}

			// Если ввели не число, просто перерисовываем меню или просим повторить
			fmt.Println("Ошибка: Введите число!")
			fmt.Print("Выберите операцию: ")
		}

		clearConsole()

		switch a {
		case 0:
			return
		case 1:
			cleanTempFiles()
		case 2:
			cleanDiskMgr()
		case 3:
			cleanDNS()
		case 4:
			cleanRecycleBin()
		case 5:
			cleanUpdateCache()
		default:
			fmt.Println("Ошибка: ТАКОЙ ОПЕРАЦИИ НЕ СУЩЕСТВУЕТ!")
			fmt.Println("Нажмите Enter...")
			bufio.NewReader(os.Stdin).ReadBytes('\n')
		}
	}
}

func outputClean() {
	fmt.Println("Чистка компьютера")
	fmt.Println("============================")
	fmt.Println("0. Назад")
	fmt.Println("1. Быстрая очистка временных файлов (Temp)")
	fmt.Println("2. Системная очистка диска (cleanmgr)")
	fmt.Println("3. Очистка кэша DNS")
	fmt.Println("4. Очистка корзины")
	fmt.Println("5. Очистка кэша обновлений Windows (SoftwareDistribution)")
	fmt.Println("")
	fmt.Print("Выберите операцию: ")
}

// 1. Очистка временных папок пользователя и системы
func cleanTempFiles() {
	fmt.Println("Очистка временных файлов...")
	fmt.Println("Примечание: Некоторые файлы могут использоваться системой и не будут удалены.")

	// Удаляем из пользовательского Temp
	// /q - тихо (без подтверждения), /f - принудительно, /s - включая подпапки
	cmd1 := "del /q /f /s %TEMP%\\*"
	// Удаляем из системного Temp
	cmd2 := "del /q /f /s C:\\Windows\\Temp\\*"

	runCommand("cmd", "/c", cmd1, "&", cmd2, "&", "pause")
}

// 2. Запуск встроенной утилиты Windows
func cleanDiskMgr() {
	fmt.Println("Запуск стандартной утилиты очистки диска...")
	runCommand("cleanmgr", "/d", "C:")
}

// 3. Сброс кэша DNS
func cleanDNS() {
	fmt.Println("Очистка кэша сопоставителя DNS...")
	runCommand("cmd", "/c", "ipconfig", "/flushdns", "&", "pause")
}

// 4. Очистка корзины
func cleanRecycleBin() {
	fmt.Println("Очистка корзины на диске C: ...")
	// rd /s /q удаляет папку со всем содержимым без вопросов
	runCommand("cmd", "/c", "rd /s /q C:\\$Recycle.Bin", "&", "echo Готово!", "&", "pause")
}

// 5. Очистка папки обновлений (помогает если обновления зависли)
func cleanUpdateCache() {
	fmt.Println("ВНИМАНИЕ: Эта операция остановит службу обновлений,")
	fmt.Println("очистит папку SoftwareDistribution и запустит службу снова.")
	fmt.Print("Продолжить? (y/n): ")

	reader := bufio.NewReader(os.Stdin)
	answer, _ := reader.ReadString('\n')
	answer = strings.TrimSpace(strings.ToLower(answer))

	if answer == "y" || answer == "yes" || answer == "д" || answer == "да" {
		// Цепочка команд: Стоп службы -> Стоп BITS -> Удаление папки -> Старт служб
		cmds := []string{
			"net stop wuauserv",
			"net stop bits",
			"rd /s /q C:\\Windows\\SoftwareDistribution",
			"net start wuauserv",
			"net start bits",
			"echo Операция завершена.",
			"pause",
		}
		// Собираем в одну строку через &&
		fullCmd := strings.Join(cmds, " && ")
		runCommand("cmd", "/c", fullCmd)
	} else {
		fmt.Println("Отмена.")
		bufio.NewReader(os.Stdin).ReadBytes('\n')
	}
}
