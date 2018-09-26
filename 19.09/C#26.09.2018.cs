using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            int[] arr = { 2, -2, 1, -1, 5, 6, 9, 0, 11, -5 };
            void Show(string str)//локальный метод
            {
                Console.WriteLine(str);
                foreach (int item in arr)
                {
                    Console.Write(item+"  ");
                }
                Console.WriteLine();
            }
            Show("Исходный " + arr.Rank + "-мерный массив");
            Array.Clear(arr,3,3);
            Show("Массив с нулями от 3-го до 5-го");
            Array.Sort(arr);
            Show("Отсортированный массив");
            Console.Write("Какое число найти : ");
            int num = Convert.ToInt32(Console.ReadLine());//(int.Parse(Console.ReadLine());
            int n = Array.BinarySearch(arr,num);
            if(n<0)
                Console.WriteLine("Заданного числа нет в массиве, но он стоял бы в "+(~n)+"-м месте ");//(~n) побитовое дополнение до единицы
            else
                Console.WriteLine("Номер найденного элемента = "+n);
            int len = arr.Length;
            int[] arr1 = new int[len];
            Array.Copy(arr, arr1, len);
            Console.WriteLine("Новый массив ");
            foreach (int item in arr1)
            {
                Console.Write(item + "  ");
            }
            //Изменение размера массива 
            Console.WriteLine();
            Array.Resize(ref arr, arr.Length + 1);
            arr[arr.Length - 1] = 100;
            Show("Новый размер массива");
            Array.Resize(ref arr, 3);
            Show("Новый размер массива");
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}

============================================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Cat
    {
        public string Name { get; set; }
        public string Kind { get; set; }
        public double Weight { get; set; }
        public override string ToString()
        {
            return ("Кот "+Name+" породы "+Kind+" весит "+Weight+" килограмм ");
        }
    }
}
=============================================================
