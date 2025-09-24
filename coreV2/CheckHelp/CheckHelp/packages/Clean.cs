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
        private static void Outputs()
        {
            Console.WriteLine("Информационные параметры");
            Console.WriteLine("============================");
            Console.WriteLine("0. Выход");
            Console.WriteLine("1. Очистка папки TEMP");
            Console.WriteLine("");
            Console.Write("Выберите операцию - ");
        }

        public static void CleanStart()
        {
            int a;
            while (true)
            {
                Outputs();
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
                        Outputs();
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
                        Console.WriteLine("");
                        Console.WriteLine("Такой операции не существует!!!!");
                        Console.WriteLine("");
                        break;
                }
            }
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