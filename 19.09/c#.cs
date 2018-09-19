using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork4
{
    class Program
    {
        //метод с параметром-ссылкой
        static void Inc(ref int x,int dx=1)
        {
            x += dx;
        }
        //метод с выходным параметром
        static void Input(out int x,string str="Введите число : ")
        {
            Console.Write(str);
            if (!int.TryParse(Console.ReadLine(), out x))
                throw new Exception("Не правильное число ");
        }
        //метод с переменным числом параметров(с параметром-массивом)
        static int op(int a=1,params int[] arr)
        {
           
            foreach (int item in arr)
            {
                a *= item;
            }
            return a;
        }
        //метод для вывода указанных чисел или массива. Параметры : заголовок, параметр массив элементов финансового типа. Пример вызова: Show("исходный массив", array);Show("зарплаты сотрудников",200,340,120)
        static void Show(string str="исходный массив",params decimal[] arr)
        {
            Console.Write(str);
            foreach (decimal item in arr)
            {
                Console.Write(" "+item);
            }
            Console.Write("\n");
        }
        static void Main(string[] args)
        {
            int number;
            Console.Write("Введите значени переменной : ");
            number = Convert.ToInt32(Console.ReadLine());
            Inc(ref number);
            Console.WriteLine("Число ={0:f2}", number);
            int newNumber;
            try
            {
                Input(out newNumber);
                Console.WriteLine("Вы ввели число " + newNumber);
            }
            catch (Exception exeption)
            {
                Console.WriteLine(exeption.Message);
            }
            int p1 = op(65, 2, 1, 7);
            Console.WriteLine(65 + "*2*1*7=" + p1);
            decimal[] arr = { 2, 4, 6, 8 };
            Show("Исходный массив:", arr);
            Show("Зарплаты сотрудников :", 154.2m, 456, 78, 97, 3321, 4569);
            Console.ReadKey();
        }
    }
}
===================================================================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork5
{
    class Program
    {
        static void Main(string[] args)
        {
            Fraction f1 = new Fraction();
           //f1.Numerator = 3;//вызывается часть set
            Console.WriteLine("Числитель первой дроби = "+f1.Numerator);//выполняется часть get
            Console.WriteLine(f1+"="+f1.Decimal);
            Fraction f2 = new Fraction(2, -8);
            Fraction f3 = Fraction.MultiPly(f1, f2);
            Console.WriteLine(f1+"*"+f2+"="+f3);
            //Упаковка
            int x = 3;
            object ob = x;//упаковка
            int y = (int)ob;//распаковка
            Console.ReadKey();
        }
    }
}

=========================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classWork5
{
    class Fraction
    {
        //поля
        int numerator;
        int denominator;
        static string objectName;
        //Свойства для доступа к полям класса (только для записи).
        public int Numerator
        {
            get
            {
                return numerator;
            }
            set
            {
                numerator = value;
            }
        }
        public int Denominator
        {
            get
            {
                return denominator;
            }
            set
            {
                if (value == 0)
                    throw new Exception("Знаменатель равен 0");
                else
                    denominator = value;

            }
        }
        //Конструктор с параметрами для создания произвольной дроби. Предусмотреть проверку на корректность введенных данных.
        public Fraction(int numerator=1,int denominator=2)
        {
            //if (denominator == 0)
            //{
            //    throw new Exception("Знаменатель равен нулю");
            //}
            //Console.WriteLine("Работает конструктор с параметрами");
            //if (denominator < 0)
            //{
            //    numerator *= -1;
            //    denominator *= -1;
            //}
            //this.numerator = numerator;
            //this.denominator = denominator;
            Denominator = denominator < 0 ? (-denominator) : denominator;
            this.numerator = denominator < 0?(-numerator):numerator;
           
        }
        //Конструктор без параметров
        public Fraction():this(1,2)//вызов конструктора с параметрами
        {
            Console.WriteLine("Работает конструктор без параметрами");
        }
        //Статический конструктор, который задает название для всех объектов «Дробь»
        static Fraction()
        {
            Console.WriteLine("Работает ОМОН");
            objectName = "Дробь";
        }
        //	Статический метод для умножения двух дробей (входные параметры – объекты класса, результат – объект класса).
        public static Fraction MultiPly(Fraction f1,Fraction f2)
        {
            Fraction fraction = new Fraction(f1.numerator*f2.numerator,f1.denominator*f2.denominator);
            return fraction;
        }
        //	Метод ToString(), результатом которого является строковое представление дроби, например, «1/2».
        public override string ToString()
        {
            return (numerator+"/"+denominator);
        }
        //Свойство для представления в виде десятичной дроби.
        public double Decimal
        {
            get
            {
                return (numerator / (double)denominator);
            }
        }
    }
}
============================================================
