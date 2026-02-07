package libs

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func StartProgram() {
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("\n!!! ПРОИЗОШЛА КРИТИЧЕСКАЯ ОШИБКА !!!")
			fmt.Printf("Ошибка: %v\n", r)
			fmt.Println("Сделайте скриншот этой ошибки.")
			fmt.Println("Нажмите Enter для выхода...")
			bufio.NewReader(os.Stdin).ReadBytes('\n')
		}
	}()
	// ---------------------------------------

	setConsoleTitle("ComputerHelper")

	// Проверка админа
	if !isAdmin() {
		fmt.Println("ВАЖНО: Запустите программу от имени администратора!")
		fmt.Println("(Правая кнопка мыши -> Запуск от имени администратора)")
		fmt.Println("\nНажмите Enter для выхода...")
		bufio.NewReader(os.Stdin).ReadBytes('\n')
		return
	}

	for {
		clearConsole()
		outputMain()

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
			fmt.Print("Неверный ввод. Введите число: ")
		}

		switch a {
		case 0:
			os.Exit(0)
		case 1:
			infoStart()
		case 2:
			fixStart()
		case 3:
			cleanStart()
		default:
			fmt.Println("Нет такой операции!")
			fmt.Println("Нажмите Enter...")
			bufio.NewReader(os.Stdin).ReadBytes('\n')
		}
	}
}

func outputMain() {
	fmt.Println("Почини компутер")
	fmt.Println("============================")
	fmt.Println("0. Выход")
	fmt.Println("1. Информационные параметры")
	fmt.Println("2. Параметры для исправлений")
	fmt.Println("3. Чистка компьютера")
	fmt.Println("")
	fmt.Print("Выберите операцию: ")
}
