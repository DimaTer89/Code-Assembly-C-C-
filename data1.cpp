#include <iostream>
#include <iomanip>
#include "MyDate.h"

using namespace std;

MyDate::MyDate()
{
	day_ = 1;
	month_ = 1;
	year_ = 1970;
}

MyDate::~MyDate()
{
}

MyDate::MyDate(int day, int month, int year)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

void MyDate::SetDay(unsigned int day)
{
	day_ = day;
	if(day_ > daysInMonth[month_ - 1])
  day_ = daysInMonth[month_ - 1];
	if (!(year_ % 4)&&((month_-1)==1)&&day==29)day_=29;
	if(day_ == 0)
  day_ = 1;
}

void MyDate::SetMonth(unsigned int month)
{
	month_ = month;
	if(month_ > 12)
  month_ = 12;
	if(month_ == 0)
  month_ = 1;
}

void MyDate::SetYear(unsigned int year)
{
	year_ = year;
 if(year_ < 1970)
  year_ = 1970;
}

int MyDate::GetDay()
{
	return day_;
}

int MyDate::GetMonth()
{
	return month_;
}

int MyDate::GetYear()
{
	return year_;
}

int MyDate::GetDays()
{
	unsigned int days = year_ * 365;
	days += (year_ -1)/ 4;

	for (unsigned int m = 1; m < month_; m++)
	{
		
		days += daysInMonth[m - 1];
		if (!(year_ % 4)&&(m == 2))
			day_++;
	}
	return days + day_;
}

void MyDate::Fill()
{
	unsigned int day, month, year;
	cout << "Введите день: ";
	cin >> day;
	cout << "Введите месяц: ";
	cin >> month;
	cout << "Введите год: ";
	cin >> year;

	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

void MyDate::Print(char separator)
{
	cout.fill('0');
	cout << std::setw(2) << day_ << separator << std::setw(2) << month_ << separator << year_;
}

void MyDate::Print_stroka()
{
 char* separator=NULL;
	cout.fill('0');
 switch(month_)
  {
   case 1:
    separator=(char*)"января";
    break;
   case 2:
    separator=(char*)"февраля";
    break;
   case 3:
    separator=(char*)"марта";
    break;
   case 4:
    separator=(char*)"апреля";
    break;
   case 5:
    separator=(char*)"мая";
    break;
   case 6:
    separator=(char*)"июня";
    break;
   case 7:
    separator=(char*)"июля";
    break;
   case 8:
    separator=(char*)"августа";
    break;
   case 9:
    separator=(char*)"сентября";
    break;
   case 10:
    separator=(char*)"октября";
    break;
   case 11:
    separator=(char*)"ноября";
    break;
   case 12:
    separator=(char*)"декабря";
    break;
  }
	cout << day_ << " " <<separator << " " << year_ << " года";
}

int MyDate::operator-(MyDate& date)
{
	return GetDays() - date.GetDays() - 1;
}

MyDate& MyDate::operator+(unsigned int days)
{
	if (days > 365)
	{
		year_ += days / 365;
		days %= 365;
	}

	while (days > daysInMonth[month_ - 1])
	{
		days -= daysInMonth[month_ - 1];
		month_++;
		if (month_ > 12)
		{
			year_++;
			month_ = 1;
		}
	}

	day_ += days;

	if (day_ > daysInMonth[month_ - 1])
	{
		day_ -= daysInMonth[month_ - 1];
		month_++;
		if (month_ > 12)
		{
			year_++;
			month_ = 1;
		}
	}
	return *this;
}
bool MyDate::operator>(MyDate date)
{
	if (GetDays() > date.GetDays())
		return true;
	else
		return false;
}
bool MyDate::operator<(MyDate date)
{
	if (GetDays() < date.GetDays())
		return true;
	else
		return false;
}
bool MyDate::operator==(MyDate date)
{
	if (GetDays() == date.GetDays())
		return true;
	else
		return false;
}
MyDate MyDate::operator ++()
{
	int tmp = GetDay();
	day_++;
	if (day_ > daysInMonth[month_ - 1])
	{
		if (!(year_ % 4) && ((month_ - 1) == 1) && tmp == 28)
		{
			day_ = 29;
			month_ = 2;
		}
		else
		{
			day_ -= daysInMonth[month_ - 1];
			month_++;
		}
		if (month_ > 12)
		{
			year_++;
			month_ = 1;
		}
	}
	return *this;
}
#include <iostream>
#include <Windows.h>
#include "MyDate.h"

using namespace std;

int main()
{
 SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
 system("cls");

	int input;
 int days = 0;
	MyDate date1;
 MyDate date2;

	do 
  {
		 cout << "Домашнее задание 1 к модулю 4. Класс Дата.\nМЕНЮ:\n";
		 cout << "1 - Заполнить большую дату (дату1).\n";
		 cout << "2 - Заполнить меньшую дату (дату2).\n";
		 cout << "3 - Разность двух дат (дата1 - дата2).\n";
		 cout << "4 - Увеличить дату1 на N дней.\n";
		 cout << "5 - Увеличить дату2 на N дней.\n";
		 cout << "6 - Показать дату1.\n";
		 cout << "7 - Показать дату2.\n";
		 cout << "8 - Сравнить даты \n";
		 cout << "9 - Увеличить дату1 на 1 день \n";
		 cout << "10 - Увеличить дату2 на 1 день \n";
		 cout << "0 - Выход.\n";
		 cin >> input;
		 if(input < 0 || input > 10)
		  {
			  cout << "Неверный выбор меню.\n";
			  system("pause");
			  system("cls");
			  continue;
		  }
		 switch (input)
		  {
		   case 1:
			   date1.Fill();
			   break;
		   case 2:
			   date2.Fill();
			   break;
		   case 3:
			   cout << "Разность двух дат (";
			   date1.Print('.');
			   cout << " - ";
			   date2.Print('.');
			   cout << ") составляет " << date1 - date2 << " дней." << endl;
			   break;
		   case 4:
			   cout << "Веедите количество дней: ";
			   cin >> days;
			   date1 = date1 + days;
			   break;
		   case 5:
			   cout << "Веедите количество дней: ";
			   cin >> days;
			   date2 = date2 + days;
			   break;
		   case 6:
			   cout << "Дата1: ";
			   date1.Print('.');
			   cout << endl;
      date1.Print_stroka();
			   cout << endl;
			   break;
		   case 7:
			   cout << "Дата2: ";
			   date2.Print('.');
			   cout << endl;
      date2.Print_stroka();
			   cout << endl;
			   break;
		   case 8:
			   if(date1>date2)
			   {
				   cout << " Первая дата больше чем вторая \n";
				   break;
			   }
			   else if (date1 < date2)
			   {
				   cout << " Первая дата меньше чем вторая \n";
				   break;
			   }
			   else
			   {
				   cout << " Даты равны \n";
				   break;
			   }
		   case 9:
			   ++date1;
			   cout << " Успешно выполнено \n";
			   break;
		   case 10:
			   ++date2;
			   cout << " Успешно выполнено \n";
			   break;
		   default:
			   break;
		  }
		 system("pause");
		 system("cls");
	 } 
 while (input);
}
class MyDate
{
 private:
	 unsigned int day_;
	 unsigned int month_;
	 unsigned int year_;
	 unsigned int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 public:
	 MyDate();
	 ~MyDate();
	 MyDate(int day, int month, int year);
	 void SetDay(unsigned int day);
	 void SetMonth(unsigned int month);
	 void SetYear(unsigned int year);
	 int GetDay();
	 int GetMonth();
	 int GetYear();
	 int GetDays();
	 void Fill();
	 void Print(char);
void Print_stroka();
	 int operator - (MyDate & date);
	 MyDate& operator + (unsigned int days);
	 bool operator >(MyDate date);
	 bool operator <(MyDate date);
	 bool operator ==(MyDate date);
	 MyDate operator ++();
};
