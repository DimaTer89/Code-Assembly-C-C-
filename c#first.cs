using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            Console.WriteLine("Как вас зовут ?");
            Console.Write("Введите имя : ");
            string str=Console.ReadLine();
            Console.WriteLine("Здравствуйте, "+str);
            Console.Write("Сколько лет : ");
            //int age = Convert.ToInt32(Console.ReadLine());
            //int age = int.Parse(Console.ReadLine());
            int age;
            if(!int.TryParse(Console.ReadLine(), out age))
            {
                Console.WriteLine(" Не получилось преобразовать");
            }
            else if(age<=18)
                Console.WriteLine("Привет малолетка");
            int yearOfBirth = DateTime.Now.Year - age;
            Console.WriteLine("Вы родились в {0,7} году. Вам {1,4:f3} лет ",yearOfBirth,age);
            Console.ReadKey();
        }
    }
}
===========================
    using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            Console.WriteLine("Как вас зовут ?");
            Console.Write("Введите имя : ");
            string str=Console.ReadLine();
            Console.WriteLine("Здравствуйте, "+str);
            Console.Write("Сколько лет : ");
            //int age = Convert.ToInt32(Console.ReadLine());
            //int age = int.Parse(Console.ReadLine());
            int age;
            if(!int.TryParse(Console.ReadLine(), out age))
            {
                Console.WriteLine(" Не получилось преобразовать");
            }
            else if(age<=18)
                Console.WriteLine("Привет малолетка");
            int yearOfBirth = DateTime.Now.Year - age;
            Console.WriteLine($"Вы родились в {yearOfBirth} году. Вам {age} лет ");
            Console.ReadKey();
        }
    }
}
