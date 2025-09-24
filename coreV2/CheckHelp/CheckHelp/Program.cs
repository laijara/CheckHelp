using CheckHelp.packages;

namespace CheckHelp
{
    internal class Program
    {
        private static void Outputs()
        {
            Console.WriteLine("Почини компутер");
            Console.WriteLine("============================");
            Console.WriteLine("0. Выход");
            Console.WriteLine("1. Информационные параметры");
            Console.WriteLine("2. Параметры для исправлений");
            Console.WriteLine("3. Чистка компьютера");
            Console.WriteLine("");
            Console.Write("Выберите операцию - ");
        }

        public static void Main()
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
                        Environment.Exit(0);
                        break;

                    case 1:
                        Console.Clear();
                        Info.InfoStart();
                        break;

                    case 2:
                        Console.Clear();
                        Fix.FixStart();
                        break;

                    case 3:
                        Console.Clear();
                        Clean.CleanStart();
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
    }
}