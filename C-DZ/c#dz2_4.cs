using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*Создать класс «Таблица», описывающий объекты-таблицы из двух столбцов, содержащий следующие элементы:
­	+Закрытые поля: заголовок таблицы, заголовки столбцов, ширина первого столбца, ширина второго столбца.
­	+Конструктор с параметрами. 
­	+Метод для вывода шапки таблицы.
­	+Метод для вывода строки таблицы (входные параметры – числовые значения, которые выводятся в строке  таблицы).
­	+Метод для вывода низа таблицы.
*/
namespace HomeWork2_2
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
    class Tablica
    {
        string nameTablica;
        string nameCol1;
        string nameCOl2;
        int widthFirstCol;
        int widthSecondCol;
        public Tablica(string nameC1,string nameC2,int width1=20,int width2=20, string name= "f(x)=1+cos^2(x+a)/|x^3-2*b^2|")
        {
            nameTablica = name;
            nameCol1 = nameC1;
            nameCOl2 = nameC2;
            widthFirstCol = width1;
            widthSecondCol = width2;
        }
        public void up_frame()
        {
            Console.Write("╔");
            int len = nameTablica.Length;
            if ((widthFirstCol + widthSecondCol) < len)
            {
                widthFirstCol = len / 2;
                widthSecondCol = len - widthFirstCol;
            }
            else
                len = widthFirstCol + widthSecondCol;
            for(int i=0;i<len;i++)
            {
                Console.Write("═");
            }
            Console.WriteLine("╗");
            Console.Write("║");
            for (int i=0;i<len;i++)
            {
                if (i == 7)
                {
                    Console.Write(nameTablica);
                    int len1 = nameTablica.Length;
                    i = len1 + 7;
                }
                Console.Write(" ");
            }
            Console.WriteLine("║");
            Console.Write("╠");
            for(int i=0;i<widthFirstCol+widthSecondCol;i++)
            {
                if (i == ((widthFirstCol + widthSecondCol) / 2))
                    Console.Write("╦");
                else
                    Console.Write("═");
            }
            Console.WriteLine("╣");
            Console.Write("║");
            for(int i=0;i<widthFirstCol;i++)
            {
                Console.Write(" ");
                if (i == widthFirstCol / 2-2)
                {
                    Console.Write("x");
                    i++;
                }
            }
            Console.Write("║");
            for(int i=0;i<widthSecondCol;i++)
            {
                Console.Write(" ");
                if (i == widthSecondCol / 2-3)
                {
                    Console.Write("f(x)");
                    i += 5;
                }
            }
            Console.WriteLine("║");
            
        }
        public void middle_frame(Function function,double xB,double rez)
        {
            Console.Write("╠");
            for (int i = 0; i < widthFirstCol + widthSecondCol; i++)
            {
                if (i == ((widthFirstCol + widthSecondCol) / 2))
                    Console.Write("╬");
                else
                    Console.Write("═");
            }
            Console.WriteLine("╣");
            Console.Write("║");
            for(int i=0;i<widthFirstCol;i++)
            {
                if (i == (widthFirstCol / 2 - 1))
                {
                    Console.Write($"{xB:f2}");
                    if (xB <= -10)
                    {
                        i += 5;
                        continue;
                    }
                    if (xB < 0)
                    {
                        i += 4;
                        continue;
                    }
                    if (xB >= 0&&xB<0)
                    {
                        i += 3;
                        continue;
                    }
                    if (xB >= 10 )
                    {
                        i += 4;
                        continue;
                    }
                    else
                        i += 4;
                } 
                Console.Write(" ");
            }
            Console.Write("║");
            string tmp = Convert.ToString(rez);
           for(int i=0;i<widthSecondCol;i++)
           {
                if (i == 0)
                {
                    Console.Write("{0:f10}", rez);
                    string str = Convert.ToString(rez);
                    int len = str.Length;
                    i=test(len, rez);
                }
               Console.Write(" ");
           }
           
           Console.WriteLine("║");
        }
        static int test(int len,double rez)
        {
            if (len > 1 && rez < 10)
                return 13;
            else if (len > 1 && rez >= 10 && rez < 100)
                return 14;
            else if (len > 1 && rez >= 100 && rez < 1000)
                return 15;
            else if (len > 1 && rez >= 1000 && rez < 10000)
                return 16;
            else if (len > 1 && rez >= 10000)
                return 17;
            else
                return len+1;
        }
        public void down_frame()
        {
            Console.Write("╚");
            for (int i = 0; i < widthFirstCol + widthSecondCol; i++)
            {
                if (i == ((widthFirstCol + widthSecondCol) / 2))
                    Console.Write("╩");
                else
                    Console.Write("═");
            }
            Console.WriteLine("╝");
        }
    }
}
=============================================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*Создать класс «Функция», описывающий объекты - функции из семейства функций заданного вида  . Класс должен содержать следующие элементы: 
­	+Закрытые поля для хранения значения параметров функции a и b.
­	+Свойства для доступа к параметрам функции.
­	+Метод для вычисления значения функции (входной параметр – значение аргумента х).
­	-+Метод для табулирования функции (входные параметры - хнач, хкон, шаг ∆х). При хнач <= хкон шаг прибавлять, при хнач > хкон шаг вычитать (использовать тернарную операцию ? :).
­	+Метод ToString(), результатом которого является строковое представление функции.
­	+Статический метод для ввода начального значения аргумента, конечного значения аргумента и шага изменения аргумента функции (выходные параметры - хнач, хкон, шаг ∆х) Ввод продолжать до тех пор пока не будет введен шаг ∆х>= 0.
*/
namespace HomeWork2_2
{
    class Function
    {
        double a;
        double b;
        public double A
        {
            get
            {
                return a;
            }
            set
            {
                a = value;
            }
        }
        public double B
        {
            get
            {
                return b;
            }
            set
            {
                b = value;
            }
        }
        public double GetValue(double num)
        {
            return ((1 + Math.Pow((Math.Cos(num + a)), 2)) / Math.Abs(Math.Pow(num, 3) - 2 * Math.Pow(b, 2)));
        }
        public double TabFunction(double xB,double xE,double xS)
        {
            double sum=(xB <= xE ? xB+=xS : xB-=xS);
            return sum;
        }
        static public void EnterValues(out double xB,out double xE,out double xS)
        {
            Console.Write("Введите начальное значение х : ");
            xB = test();
            Console.Write("Введите конечное значение x : ");
            xE = test();
            Console.Write("Введите шаг : ");
            do
            {
                xS = test();
                if (xS < 0) Console.Write("Вы неправильно ввели данные, шаг не может быть отрицательным значением, введите снова : ");
            } while (xS < 0);
        }
        public override string ToString()
        {
            return ("f(x)=1+cos^2(x+"+a+")/|x^3-2*"+b+"^2|");
        }
        static double test()
        {
            double num;
            bool flag = false;
            do
            {
                if (!double.TryParse(Console.ReadLine(), out num))
                    Console.Write("Неприавильное число введите снова : ");
                else
                    flag = true;
            } while (!flag);
            return num;
        }
    }
}
 =======================================================================
 using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*	Создает два объекта класса «Функция» (параметры функций вводятся с клавиатуры).
	Для каждого объекта вычисляет значения для трех различных значений аргумента.
	Для каждого объекта–функции выполняет табулирование для ряда значений аргумента. Результат выводить в виде таблицы, в заголовке таблицы приводить вид функции.
*/

namespace HomeWork2_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            double xb, xe, xs;
            Function function1 = new Function();
            Function function2 = new Function();
            double a1, b1, x1, a2, b2, x2, a3, b3, x3;
            Input2(out a1, out b1, out x1, out a2, out b2, out x2, out a3, out b3, out x3);
            vyvod(function1, a1, b1, x1, a2, b2, x2, a3, b3, x3);
            Tablica tablica1 = new Tablica("x", "f(x)");
            tablica1.up_frame();
            vyvodTablica(tablica1, function1, x1, x2, x3);
            tablica1.down_frame();
            Input2(out a1, out b1, out x1, out a2, out b2, out x2, out a3, out b3, out x3);
            vyvod(function2, a1, b1, x1, a2, b2, x2, a3, b3, x3);
            tablica1.up_frame();
            vyvodTablica(tablica1, function2, x1, x2, x3);
            tablica1.down_frame();
            Console.WriteLine("Табуляция для первого объекта функции ");
            Input(function1);
            Function.EnterValues(out xb, out xe, out xs);
            Tablica tablica2 = new Tablica("x", "f(x)", name: function1.ToString());
            tablica2.up_frame();
            PrintString(tablica2, function1, xb, xe, xs);
            tablica2.down_frame();
            Console.WriteLine("Табуляция для второго объекта функции ");
            Input(function2);
            Function.EnterValues(out xb, out xe, out xs);
            Tablica tablica3 = new Tablica("x", "f(x)", name: function2.ToString());
            tablica3.up_frame();
            PrintString(tablica3, function1, xb, xe, xs);
            tablica3.down_frame();
            Console.ReadKey();
        }
        static void vyvodTablica(Tablica tablica,Function function,double x1,double x2,double x3)
        {
            tablica.middle_frame(function, x1, function.GetValue(x1));
            tablica.middle_frame(function, x2, function.GetValue(x2));
            tablica.middle_frame(function, x3, function.GetValue(x3));
        }
        static void vyvod(Function function,double a1,double b1,double x1,double a2,double b2,double x2,double a3,double b3,double x3)
        {
            function.A = a1;
            function.B = b1;
            Console.WriteLine("f("+x1+")="+function.GetValue(x1));
            function.A = a2;
            function.B = b2;
            Console.WriteLine("f(" + x2 + ")=" + function.GetValue(x2));
            function.A = a3;
            function.B = b3;
            Console.WriteLine("f(" + x3 + ")=" + function.GetValue(x3));
        }
        static void Input(Function function)
        {
            Console.Write("Введите значение a : ");
            function.A = test();
            Console.Write("Введите значение b : ");
            function.B = test();
        }
        static void Input2(out double a1,out double b1,out double x1,out double a2,out double b2,out double x2,out double a3,out double b3,out double x3, string str = "Введите значение ")
        {
            Console.Write(str+"a1 : ");
            a1 = test();
            Console.Write(str + "b1 : ");
            b1 = test();
            Console.Write(str + "x1 : ");
            x1 = test();
            Console.Write(str + "a2 : ");
            a2 = test();
            Console.Write(str + "b2 : ");
            b2 = test();
            Console.Write(str + "x2 : ");
            x2 = test();
            Console.Write(str + "a3 : ");
            a3 = test();
            Console.Write(str + "b3 : ");
            b3 = test();
            Console.Write(str + "x3 : ");
            x3 = test();
        }
        static double test()
        {
            double num;
            bool flag = false;
            do
            {
                if (!double.TryParse(Console.ReadLine(), out num))
                    Console.Write("Неправильное число, повторите ввод : ");
                else
                    flag = true;
            } while (!flag);
            return num;
        }
        static void PrintString(Tablica tablica,Function function,double xB,double xE,double xS)
        {
            if(xB<=xE)
            {
                while(xB<=xE)
                {
                    tablica.middle_frame(function, xB, function.GetValue(xB));
                    xB = function.TabFunction(xB, xE, xS);
                }
                return ;
            }
            if(xB>xE)
            {
                while(xB>xE)
                {
                    tablica.middle_frame(function, xB, function.GetValue(xB));
                    xB = function.TabFunction(xB, xE, xS);
                }
                return;
            }
        }
    }
}
