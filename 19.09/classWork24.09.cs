using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*Разработать класс «Книга», который должен содержать следующие элементы:
 * закрытое поле название,
 * закрытое поле автор, свойства (только для чтения) этих полей класса; 
 * статическое поле издательство, 
 * свойство для доступа к этому полю;
 * автоматические свойства тираж, цена книги; конструктор с необязательными параметрами; деструктор, который выводит сообщение «Уничтожена книга … »;   статический конструктор, метод  возвращающий стоимость всего тиража; статический метод, который принимает в качестве параметров два объекта класса, а в качестве результата возвращает общий тираж этих книг. 

В методе Main нужно создать два объекта класса «Книга» с издательством «РОСМЭН», заданным через статический конструктор. Данные для первой книги задавать в виде констант, а для второй вводить с клавиатуры. Вывести информацию о книгах, включая стоимость издания и общий тираж. Заменить издательство на «Михалыч®». Написать фрагмент кода, который демонстрирует работу деструктора.
*/
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            string avtorBook;
            string titleBook;
            Book book1 = new Book();
            book1.Circlation = 200;
            book1.Price=5.35;
            Console.Write("Введите название книги : ");
            titleBook = Convert.ToString(Console.ReadLine());
            Console.Write("Введите автора книги : ");
            avtorBook = Convert.ToString(Console.ReadLine());
            Book book2 = new Book(titleBook, avtorBook);
            Console.Write("Введите тираж книги : ");
            book2.Circlation = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите стоимость одной книги : ");
            book2.Price = Convert.ToDouble(Console.ReadLine());
            PrintBook(book1, book2);
            Book.PubHouse = "Михалыч";
            Console.WriteLine("Издательство : "+Book.PubHouse);
            PrintBook(book1, book2);
            book1 = null;
            GC.Collect();
            Console.ReadKey();
        }
        static void PrintBook(Book book1,Book book2)
        {
            Console.WriteLine("=====================");
            Console.WriteLine("Издательство : " + Book.PubHouse);
            Console.WriteLine("Книга 1");
            Console.WriteLine("Название : " + book1.Title + "\nАвтор : " + book1.Avtor + "\nТираж : " + book1.Circlation + "\nСтоимость одной книги : " + book1.Price + "\nСтоимость тиража : " + book1.PriceCirclation());
            Console.WriteLine("Книга 2");
            Console.WriteLine("Название : " + book2.Title + "\nАвтор : " + book1.Avtor + "\nТираж : " + book2.Circlation + "\nСтоимость одной книги : " + book2.Price + "\nСтоимость тиража : " + book2.PriceCirclation());
            Console.WriteLine("Общий тираж книг : " + Book.AllCirclationBook(book1, book2));
        }
    }
}
===============================================
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/**Разработать класс «Книга», который должен содержать следующие элементы:
 * +закрытое поле название,
 * +закрытое поле автор, свойства (только для чтения) этих полей класса; 
 * +статическое поле издательство, 
 * +свойство для доступа к этому полю;
 * автоматические свойства тираж, цена книги; конструктор с необязательными параметрами; деструктор, который выводит сообщение «Уничтожена книга … »;   статический конструктор, метод  возвращающий стоимость всего тиража; статический метод, который принимает в качестве параметров два объекта класса, а в качестве результата возвращает общий тираж этих книг. 
 * */
namespace ConsoleApp1
{
    class Book
    {
        string title;
        string avtor;
        static string pubHouse;
        public Book(string title="Песнь льда и пламени",string avtor="Джордж Р.Р. Мартин")
        {
            this.title = title;
            this.avtor = avtor;
        }
        static Book()
        {
            pubHouse = "РОСМЭН";
        }
        ~Book()
        {
            Console.WriteLine("Уничтожена книга "+this);
            
        }
        public override string ToString()
        {
            return (title);
        }
        public static string PubHouse
        {
            get
            {
                return pubHouse;
            }
            set
            {
                pubHouse = value;
            }
        }
        public string Title
        {
            get
            {
                return title;
            }
        }
        public string Avtor
        {
            get
            {
                return avtor;
            }
        }
        public int Circlation
        { get; set; }
        public double Price
        { get; set; }
        public double PriceCirclation()
        {
            return ((double)Price * Circlation);
        }
        public static int AllCirclationBook(Book book1,Book book2)
        {
            return (book1.Circlation + book2.Circlation);
        }
    }
}
