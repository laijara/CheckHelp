using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CheckHelp.packages
{
    internal class Info
    {
        private static void Outputs()
        {
            Console.WriteLine("Информационные параметры");
            Console.WriteLine("============================");
            Console.WriteLine("0. Выход");
            Console.WriteLine("1. Информация о системе (systeminfo)");
            Console.WriteLine("2. Информация о соединениях (ipconfig)");
            Console.WriteLine("3. Информация о потреблении ресурсов (resmon)");
            Console.WriteLine("4. Просмотр логов (eventvwr.msc)");
            Console.WriteLine("5. Информация о запущенных задачах (tasklist)");
            Console.WriteLine("6. Проверка работоспособности интернета");
            Console.WriteLine("");
            Console.Write("Выберите операцию - ");
        }

        public static void InfoStart()
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
                        InfoSystem();
                        break;

                    case 2:
                        Console.Clear();
                        InfoIp();
                        break;

                    case 3:
                        Console.Clear();
                        InfoResources();
                        break;

                    case 4:
                        Console.Clear();
                        InfoLogs();
                        break;

                    case 5:
                        Console.Clear();
                        InfoTaskList();
                        break;

                    case 6:
                        Console.Clear();
                        InfoNet();
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

        private static void InfoSystem()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && systeminfo && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void InfoIp()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && ipconfig && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void InfoResources()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && resmon && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void InfoLogs()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && eventvwr.msc && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void InfoTaskList()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && tasklist && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }

        private static void InfoNet()
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = "cmd.exe",
                Arguments = "/k echo off && ping ya.ru && tracert ya.ru && pause && exit",
                UseShellExecute = true,
                CreateNoWindow = false,
                Verb = "runas"
            });
        }
    }
}