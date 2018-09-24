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
namespace ConsoleApp2
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
        const int widthFirstCol = 8;
        const int widthSecondCol = 9;
        public Tablica(string name,string nameC1, string nameC2)
        {
            nameTablica = name;
            nameCol1 = nameC1;
            nameCOl2 = nameC2;
        }
        public void up_frame()
        {
            Console.WriteLine("Функция : "+nameTablica);
            Console.WriteLine("╔════════╦═════════╗");
            Console.WriteLine($"║{nameCol1,widthFirstCol}║{nameCOl2,widthSecondCol}║");
        }
        public void string_frame(double a, double b)
        {
            Console.WriteLine("╠════════╬═════════╣");
            Console.WriteLine($"║{a,widthFirstCol:f2}║{b,widthSecondCol:f2}║");
        }
        public void down_frame()
        {
            Console.WriteLine("╚════════╩═════════╝");
        }
    }
}


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
namespace ConsoleApp2
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
        public void PlusCircle(double xB, double xE, double xS)
        {
            for (double x = xB; x <= xE; x += xS)
            {
                Console.WriteLine($"x={x:f2} f(x)={GetValue(x):f2}");
            }

        }
        public void MinusCircle(double xB, double xE, double xS)
        {
            for (double x = xB; x >= xE; x -= xS)
            {
                Console.WriteLine($"x={x:f2} f(x)={GetValue(x):f2}");
            }
        }
        public double TabFunction(double xB, double xE, double xS)
        {
            return ((xB <= xE) ? xB += xS : xB -= xS);
        }
        static public void EnterValues(out double xB, out double xE, out double xS)
        {
            Console.Write("Введите начальное значение х : ");
            xB = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите конечное значение x : ");
            xE = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите шаг : ");
            do
            {
                xS = Convert.ToDouble(Console.ReadLine());
                if (xS < 0) Console.Write("Вы неправильно ввели данные, шаг не может быть отрицательным значением, введите снова : ");
            } while (xS < 0);
        }
        public override string ToString()
        {
            return ("1-cos(x+a)*cos(x+a)/|x*x*x-2*b*b|");
        }
    }
}



using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*	Создает два объекта класса «Функция» (параметры функций вводятся с клавиатуры).
	Для каждого объекта вычисляет значения для трех различных значений аргумента.
	Для каждого объекта–функции выполняет табулирование для ряда значений аргумента. Результат выводить в виде таблицы, в заголовке таблицы приводить вид функции.
*/

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            double xb, xe, xs;
            Function function = new Function();
            Function function2 = new Function();
            Input(function);

            Console.ReadKey();
        }
        static void Input(Function function)
        {
            Console.Write("Введите значение a : ");
            function.A = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите значение b : ");
            function.B = Convert.ToDouble(Console.ReadLine());
        }
        static void PrintString(Tablica tablica,)
    }
}


