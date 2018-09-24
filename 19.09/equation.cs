using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*Создать класс «Квадратное уравнение», описывающий объекты – уравнения вида  . Класс должен содержать указанные ниже элементы. 
•	Закрытые поля для хранения коэффициентов уравнения.
•	Конструктор без параметров для создания уравнения  .
•	Конструктор с параметрами для создания уравнения с произвольными коэффициентами. Предусмотреть проверку на корректность введенных данных.
•	Свойства для доступа к полям класса (только для записи).
•	Свойство для определения дискриминанта.
•	Метод ToString(), результатом которого является строковое представление уравнения, например, «3x^2+2x-6=0».
•	Метод, который вычисляет корни уравнения.
•	Статический метод для проверки, совпадают ли корни уравнений (входные параметры – объекты класса, результат -  true или false).
*/
namespace ConsoleApp1
{
    class Equation
    {
        double a, b, c;
        double end;
        public Equation()
        {
            a = 1;
            b = c = 0;
            end = 1;
        }
        public Equation(double a, double b, double c, double end = 0)
        {
            this.a = a;
            this.b = b;
            this.c = c;
            this.end = end;
        }
        public double A
        {
            set
            {
                a = value;
            }
        }
        public double B
        {
            set
            {
                b = value;
            }
        }
        public double C
        {
            set
            {
                c = value;
            }
        }
        public double Diskrim
        {
            get
            {
                return (b * b - 4 * a * c);
            }
        }
        public override string ToString()
        {
            if (b == 0 && c == 0)
                return ("x^2=" + end);
            else
                return (a+"x^2"+b+"*x"+c+"="+c);
        }
    }
}
==============================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*Создать класс «Квадратное уравнение», описывающий объекты – уравнения вида  . Класс должен содержать указанные ниже элементы. 
•	Закрытые поля для хранения коэффициентов уравнения.
•	Конструктор без параметров для создания уравнения  .
•	Конструктор с параметрами для создания уравнения с произвольными коэффициентами. Предусмотреть проверку на корректность введенных данных.
•	Свойства для доступа к полям класса (только для записи).
•	Свойство для определения дискриминанта.
•	Метод ToString(), результатом которого является строковое представление уравнения, например, «3x^2+2x-6=0».
•	Метод, который вычисляет корни уравнения.
•	Статический метод для проверки, совпадают ли корни уравнений (входные параметры – объекты класса, результат -  true или false).
*/
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            double a=2, b=-3, c=1, d=0;
            Equation equation1 = new Equation();
            Equation equation = new Equation(a, b, c, d);
            Console.WriteLine(equation1);
            Console.WriteLine(equation);
            Console.ReadKey();
        }
    }
}


