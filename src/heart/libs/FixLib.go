package libs

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func fixStart() {
	for {
		clearConsole()
		outputFix()

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

			clearConsole()
			fmt.Println("Ошибка: ВВЕДИТЕ НОМЕР ОПЕРАЦИИ КОРРЕКТНО!")
			outputFix()
		}

		clearConsole()

		switch a {
		case 0:
			return
		case 1:
			fixSystem()
		case 2:
			fixDisk()
		case 3:
			fixOperationalMemory()
		case 4:
			fixDism()
		case 5:
			fixNetSettingsReset()
		default:
			fmt.Println("Ошибка: ТАКОЙ ОПЕРАЦИИ НЕ СУЩЕСТВУЕТ!")
			fmt.Println("Нажмите Enter...")
			bufio.NewReader(os.Stdin).ReadBytes('\n')
		}
	}
}

func outputFix() {
	fmt.Println("Параметры для исправлений")
	fmt.Println("============================")
	fmt.Println("0. Назад")
	fmt.Println("1. Проверка системных файлов (sfc /scannow)")
	fmt.Println("2. Проверка диска (chkdsk)")
	fmt.Println("3. Проверка оперативной памяти (mdsched.exe)")
	fmt.Println("4. Проверка компонентов образов (dism)")
	fmt.Println("5. Сброс сетевых настроек (TCP/IP)")
	fmt.Println("")
	fmt.Print("Выберите операцию - ")
}

func fixSystem() {
	runCommand("cmd", "/k", "echo off && sfc /scannow && pause && exit")
}

func fixDisk() {
	fmt.Println("ВНИМАНИЕ: Проверка диска потребует перезагрузки системы!")
	fmt.Println("Диск C: будет проверен при следующей загрузке.")
	fmt.Print("Продолжить? (y/n): ")

	reader := bufio.NewReader(os.Stdin)
	answer, _ := reader.ReadString('\n')
	answer = strings.TrimSpace(strings.ToLower(answer))

	if answer == "y" || answer == "yes" || answer == "д" || answer == "да" {
		runCommand("cmd", "/k", "echo off && chkdsk C: /F /R && pause && exit")
	} else {
		fmt.Println("Операция отменена.")
		fmt.Println("Нажмите Enter...")
		bufio.NewReader(os.Stdin).ReadBytes('\n')
	}
}

func fixOperationalMemory() {
	fmt.Println("Запуск диагностики оперативной памяти...")
	fmt.Println("Система будет перезагружена для выполнения теста.")
	fmt.Print("Продолжить? (y/n): ")

	reader := bufio.NewReader(os.Stdin)
	answer, _ := reader.ReadString('\n')
	answer = strings.TrimSpace(strings.ToLower(answer))

	if answer == "y" || answer == "yes" || answer == "д" || answer == "да" {
		runCommand("cmd", "/k", "echo off && C:\\Windows\\System32\\mdsched.exe && pause && exit")
	} else {
		fmt.Println("Операция отменена.")
		fmt.Println("Нажмите Enter...")
		bufio.NewReader(os.Stdin).ReadBytes('\n')
	}
}

func fixDism() {
	runCommand("cmd", "/k", "echo off && DISM /Online /Cleanup-Image /RestoreHealth && pause && exit")
}

func fixNetSettingsReset() {
	runCommand("cmd", "/k", "echo off && netsh winsock reset && netsh int ip reset && ipconfig /flushdns && pause && exit")
}
