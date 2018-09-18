using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, x;
            Console.Write("Введите переменную а : ");
            a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите переменную x : ");
            x = Convert.ToDouble(Console.ReadLine());
            double rez = (x + a * a) / (1.4 * a) - x;
            Console.WriteLine("Переменная a = "+a+"\nПеременная x = "+x+"\nРезультат f = "+rez);
            Console.ReadKey();
        }
    }
}
============================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите переменную а : ");
            double x = Double.Parse(Console.ReadLine());
            Console.Write("Введите переменную x : ");
            double a = Double.Parse(Console.ReadLine());
            double rez = (x + a * a)/(1.4 * a)-x;
            Console.WriteLine("a = "+a+"  x = "+x);
            Console.WriteLine($"Переменная f = {rez:f3}");
            Console.ReadKey();
        }
    }
}
=================================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите x : ");
            double x = Double.Parse(Console.ReadLine());
            Console.Write("Введите z : ");
            double z = Double.Parse(Console.ReadLine());
            double rez;
            if (z > -5 && z <= 0)
            {
                Console.WriteLine("Вывод по формуле x*x+z");
                rez = Math.Pow(x, 2) + z;
            }
            else if (z <= -5)
            {
                Console.WriteLine("Вывод по формуле 2.5*z");
                rez = 2.5 * z;
            }
            else
            {
                Console.WriteLine("Вывод по формуле (x*x*x+1.3)/z");
                rez = (Math.Pow(x, 3) + 1.3) / z;
            }
            Console.WriteLine($"Результат f = {rez:f2}");
            Console.ReadLine();
        }
    }
}
==========================================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork2
{
    class Program
    {
        // ╚ 200
        // ╔ 201
        // ╩ 202
        // ╦ 203
        // ╠ 204
        // ═ 205
        // ╬ 206
        // ╝ 188
        // ║ 186
        // ╗ 187
        // ╣ 185
        static void Main(string[] args)
        {
            double xn = InputDouble("начальное значение аргумента  : ");
            double xk = InputDouble("конечное значение аргумента : ");
            double dk = InputDouble("шаг изменения кода : ");
            double a = InputDouble("значение а : ");
            if(xn<=xk&&dk>0&&a!=0)
            {
                Console.WriteLine("╔══════╦═══════╗");
                Console.WriteLine("║  x   ║ f(x)  ║");
                Console.WriteLine("╠══════╬═══════╣");
                double f;
                for (double x=xn;x<=xk;x+=dk)
                {
                    f = (x + a * a) / (1.4 * a) - x;
                    Console.WriteLine($"║{x,6:f2}║{f,7:f3}║");
                }
                Console.WriteLine("╚══════╩═══════╝");
            }
            else
            {
                Console.WriteLine("Вы неправильно ввели данные!");
            }
            Console.ReadKey();
        }
        static double InputDouble(string query)
        {
            Console.Write("Введите "+query);
            return Double.Parse(Console.ReadLine());
        
        }
    }
}
==================================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите А : ");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите B : ");
            int b = Convert.ToInt32(Console.ReadLine());
            if (a < b)
            {
                while (a <= b)
                {
                    for (int i = 0; i < a; i++)
                    {
                        Console.Write(a+ " ");
                    }
                    Console.Write("\n");
                    a++;
                }
            }
            else
            {
                Console.WriteLine("Вы не правильно ввели данные! ");
            }
            Console.ReadKey();
        }
    }
}
======================================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Cnsl = System.Console;//создание псевдонима
namespace classWork2
{
    class Program
    {
        static void Main(string[] args)
        {
            Cnsl.Write("Введите А : ");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите B : ");
            int b = Convert.ToInt32(Console.ReadLine());
            if (a < b)
            {
                while (a <= b)
                {
                    for (int i = 0; i < a; i++)
                    {
                        Console.Write(a+ " ");
                    }
                    Console.Write("\n");
                    a++;
                }
            }
            else
            {
                Console.WriteLine("Вы не правильно ввели данные! ");
            }
            Console.ReadKey();
        }
    }
}
==========================================================
using System;
using System.Linq;
namespace classWork3
{
    class Program
    {
        static void Main(string[] args)
        {
            // int[,] matrix = new int[3, 3]; двуменрный массив создание 
            //поиск максимального элемента в массиве 
            int[] array = new int[10] { 2, 45, 65, 8, 9, 7, 1, 3, 47, 79 };
            for (int i = 0; i < array.Length; i++)
            {
                Console.WriteLine(array[i]);
            }
            Console.WriteLine(" C использованием foreach");
            foreach (int item in array)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
            int max = array[0];
            foreach (int item in array)
            {
                if (item > max)
                    max = item;
            }
            Console.WriteLine("Максимальный элемент массива = "+max);
            Console.WriteLine("Максимальный элемент массива = " + array.Max());
            Console.ReadKey();
        }
    }
}
=======================================
using System;
using System.Linq;
namespace classWork3
{
    class Program
    {
        static void ShowNumber(int x=2,double y=5)
        {
            Console.WriteLine("Целое число="+x+" Вещественное число="+y);
        }
        static void Main(string[] args)
        {
            Dog.LapsCount = 4;

            Dog psina = new Dog();
            psina.SetName("Бобик");
            psina.weight = 10;

            Dog pes = new Dog();
            pes.SetName("Шарик");
            pes.weight = 20;
            psina.feed();
            Console.WriteLine(psina);
            ShowNumber(y:9.3);
            Console.ReadKey();
        }
    }
}
==============================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork3
{
    class Dog
    {
        string name;
        public int weight;
        public static int LapsCount;
        //public void SetName(string name)
        //{
        //    this.name = name;
        //}
        public void SetName(string name) => this.name = name;
        //public string GetName()
        //{
        //    return name;
        //}
        public string GetName() => name;
        public override string ToString()=>("собака по кличке "+name+" "+weight);
        
        public void feed(int addweight=1)
        {
            weight += addweight;
        }
    }
}
==================================================
