using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CheckHelp.packages
{
    internal class Fix
    {
        private static void Outputs()
        {
            Console.WriteLine("Информационные параметры");
            Console.WriteLine("============================");
            Console.WriteLine("0. Выход");
            Console.WriteLine("1. Проверка системных файлов (sfcscan)");
            Console.WriteLine("2. Проверка диска (chkdsk)");
            Console.WriteLine("3. Проверка оперативной памяти (mdsched.exe)");
            Console.WriteLine("4. Проверка компонентов образов (dism)");
            Console.WriteLine("5. Сброс сетевых настроек (TCP/IP)");
            Console.WriteLine("");
            Console.Write("Выберите операцию - ");
        }

        public static void FixStart()
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
                        FixSystem();
                        break;

                    case 2:
                        Console.Clear();
                        FixDisk();
                        break;

                    case 3:
                        Console.Clear();
                        FixOperationalMemory();
                        break;

                    case 4:
                        Console.Clear();
                        FixDism();
                        break;

                    case 5:
                        Console.Clear();
                        FixNetSettingsReset();
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

        private static void FixSystem()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && sfc /scannow && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void FixDisk()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && chkdsk C: /F /R && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void FixOperationalMemory()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && C:\\Windows\\System32\\mdsched.exe && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void FixDism()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && DISM /Online /Cleanup-Image /RestoreHealth && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void FixNetSettingsReset()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && netsh winsock reset && netsh int ip reset && ipconfig /flushdns && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }
    }
}