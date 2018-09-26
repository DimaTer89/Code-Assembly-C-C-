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
    class CatCollection
    {
        Cat[] cats;
        public string Owner { get; set; }
        public CatCollection(string owner="инкогнито",params Cat[] cats)
        {
            Owner = owner;
            this.cats = cats;
        }
        public int KolCat => cats.Length;
        //public Cat[] Cats { get { return cats; } }
        //индексатор
        public Cat this[int i]
        {
            get
            {
                return cats[i];
            }
            set
            {
                cats[i] = value;
            }
        }
        public void Add(Cat cat)
        {
            Array.Resize(ref cats, cats.Length + 1);
            cats[cats.Length - 1] = cat;
        }
    }
}

=============================================================
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
            //int[] arr = { 2, -2, 1, -1, 5, 6, 9, 0, 11, -5 };
            //void Show(string str)//локальный метод
            //{
            //    Console.WriteLine(str);
            //    foreach (int item in arr)
            //    {
            //        Console.Write(item+"  ");
            //    }
            //    Console.WriteLine();
            //}
            //Show("Исходный " + arr.Rank + "-мерный массив");
            //Array.Clear(arr,3,3);
            //Show("Массив с нулями от 3-го до 5-го");
            //Array.Sort(arr);
            //Show("Отсортированный массив");
            //Console.Write("Какое число найти : ");
            //int num = Convert.ToInt32(Console.ReadLine());//(int.Parse(Console.ReadLine());
            //int n = Array.BinarySearch(arr,num);
            //if(n<0)
            //    Console.WriteLine("Заданного числа нет в массиве, но он стоял бы в "+(~n)+"-м месте ");//(~n) побитовое дополнение до единицы
            //else
            //    Console.WriteLine("Номер найденного элемента = "+n);
            //int len = arr.Length;
            //int[] arr1 = new int[len+2];
            //Array.Copy(arr, arr1, len);
            //Console.WriteLine("Новый массив ");
            //foreach (int item in arr1)
            //{
            //    Console.Write(item + "  ");
            //}
            ////Изменение размера массива 
            //Console.WriteLine();
            //Array.Resize(ref arr, arr.Length + 1);
            //arr[arr.Length - 1] = 100;
            //Show("Новый размер массива");
            //Array.Resize(ref arr, 3);
            //Show("Новый размер массива");
            //Console.WriteLine();
            //Массив котов
            const int num = 5;
            Cat[] cats = new Cat[num]
            {
                new Cat{Name="Барсик",Kind="Сиамский",Weight=6},
                new Cat{Name="Мурзик",Kind="Сибирский",Weight=9},
                new Cat{Name="Барон",Kind="Мейн-Кун",Weight=15},
                null,
                new Cat{Name="Вася",Kind="Британский вислоухий",Weight=10},
            };
            Console.WriteLine("Прайд котов");
            foreach (Cat item in cats)
            {
               if(item!=null)
                    Console.WriteLine(item);
            }
            //Определить средний вес котов
            int kol_cats = 0;
            double sum = 0;
            foreach (Cat item in cats)
            {
                if (item != null)
                {
                    sum += item.Weight;
                    kol_cats++;
                }
            }
            Console.WriteLine("Средний вес котов : "+sum/kol_cats);
            //Отсортировать котов по убыванию веса
            //for (int k = num - 1; k > 0; k--)
            //{
            //    for (int i = 0; i < k; i++)
            //    {
            //        if (cats[i] != null && cats[i + 1] != null)
            //        {
            //            if (cats[i].Weight > cats[i + 1].Weight)
            //            {
            //                Cat tmp = cats[i];
            //                cats[i] = cats[i + 1];
            //                cats[i + 1] = tmp;
            //            }
            //        }
            //    }
            //}
            Array.Sort(cats, Compare);
            //Array.Reverse(cats);
            CatsShow(cats);
            CatCollection catCollection = new CatCollection("бабуся",
                new Cat { Name = "Барсик", Kind = "Сиамский", Weight = 6 },
                new Cat { Name = "Мурзик", Kind = "Сибирский", Weight = 9 },
                new Cat { Name = "Барон", Kind = "Мейн-Кун", Weight = 15 });
            Console.WriteLine("Владелец котов "+catCollection.Owner);
            for(int i=0;i<catCollection.KolCat;i++)
            {
                Console.WriteLine(catCollection[i].Name);
            }
            catCollection[0].Weight += 4;//get индексатор
            Console.WriteLine(catCollection[0]);
            catCollection[0] = new Cat { Name = "Барсик", Kind = "Дворовый", Weight = 15 };
            for (int i = 0; i < catCollection.KolCat; i++)
            {
                Console.WriteLine(catCollection[i]);
            }
            catCollection.Add(new Cat { Name = "Барон", Kind = "Мейн-Кун", Weight = 5 });
            for (int i = 0; i < catCollection.KolCat; i++)
            {
                Console.WriteLine(catCollection[i]);
            }
            Console.ReadKey();
        }
        //static int Compare(Cat cat1, Cat cat2)
        //{
        //    if (cat1 == null || cat2 == null)
        //        return -2;
        //    else if (cat1.Weight < cat1.Weight)
        //        return -1;
        //    else if (cat1.Weight == cat2.Weight)
        //        return 0;
        //    else
        //        return 1;
        //}
        static int Compare(Cat cat1, Cat cat2)
        {
            if (cat1 == null && cat2 == null)
                return 0;
            if (cat1 == null)
                return -1;
            if (cat2 == null)
                return 0;
            if (cat1.Weight < cat2.Weight)
                return -1;
            if (cat1.Weight == cat2.Weight)
                return 0;
            else
                return 1;
            //return cat1.Weight.CompareTo(cat2.Weight);
        }
        static void CatsShow(Cat[] cats)
        {
            Console.WriteLine("Прайд котов");
            foreach (Cat item in cats)
            {
                if (item != null)
                    Console.WriteLine(item);
            }
        }
    }
}
===================================================
    
