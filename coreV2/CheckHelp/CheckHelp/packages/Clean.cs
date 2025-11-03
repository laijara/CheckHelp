using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CheckHelp.packages
{
    internal class Clean
    {
        public static void CleanStart()
        {
            int a;
            while (true)
            {
                OutputClean();
                while (true)
                {
                    var input = Console.ReadLine();
                    if (int.TryParse(input, out a))
                    {
                        break;
                    }
                    else
                    {
                        Console.Clear();
                        Console.WriteLine("Ошибка: ВВЕДИТЕ НОМЕР ОПЕРАЦИИ КОРРЕКТНО!");
                        OutputClean();
                    }
                }
                switch (a)
                {
                    case 0:
                        Console.Clear();
                        Program.Main();
                        break;

                    case 1:
                        Console.Clear();
                        CleanTemp();
                        break;

                    default:
                        Console.Clear();
                        Console.WriteLine("Ошибка: ТАКОЙ ОПЕРАЦИИ НЕ СУЩЕСТВУЕТ!");
                        break;
                }
            }
        }

        private static void OutputClean()
        {
            Console.WriteLine("Информационные параметры");
            Console.WriteLine("============================");
            Console.WriteLine("0. Выход");
            Console.WriteLine("1. Очистка папки TEMP");
            Console.WriteLine("");
            Console.Write("Выберите операцию - ");
        }

        private static void CleanTemp()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && del /q /f /s \"C:\\Windows\\Temp\\*.*\" && for /d %%p in (\"C:\\Windows\\Temp\\*.*\") do rd /s /q \"%%p\" && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }
    }
}