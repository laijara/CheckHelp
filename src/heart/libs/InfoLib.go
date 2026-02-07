package libs

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func infoStart() {
	for {
		clearConsole()
		outputInfo()

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
			outputInfo()
		}

		clearConsole()

		switch a {
		case 0:
			return
		case 1:
			infoSystem()
		case 2:
			infoIP()
		case 3:
			infoResources()
		case 4:
			infoLogs()
		case 5:
			infoTaskList()
		case 6:
			infoNet()
		default:
			fmt.Println("Ошибка: ТАКОЙ ОПЕРАЦИИ НЕ СУЩЕСТВУЕТ!")
			fmt.Println("Нажмите Enter...")
			bufio.NewReader(os.Stdin).ReadBytes('\n')
		}
	}
}

func outputInfo() {
	fmt.Println("Информационные параметры")
	fmt.Println("============================")
	fmt.Println("0. Назад")
	fmt.Println("1. Информация о системе (systeminfo)")
	fmt.Println("2. Информация о соединениях (ipconfig)")
	fmt.Println("3. Информация о потреблении ресурсов (resmon)")
	fmt.Println("4. Просмотр логов (eventvwr.msc)")
	fmt.Println("5. Информация о запущенных задачах (tasklist)")
	fmt.Println("6. Проверка работоспособности интернета")
	fmt.Println("")
	fmt.Print("Выберите операцию - ")
}

func infoSystem() {
	runCommand("cmd", "/c", "systeminfo", "&", "pause")
}

func infoIP() {
	runCommand("cmd", "/c", "ipconfig", "/all", "&", "pause")
}

func infoResources() {
	runCommand("resmon")
}

func infoLogs() {
	runCommand("eventvwr")
}

func infoTaskList() {
	runCommand("cmd", "/c", "tasklist", "&", "pause")
}

func infoNet() {
	runCommand("cmd", "/k", "ping ya.ru && tracert ya.ru && pause")
}
