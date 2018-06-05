#include <iostream>
using namespace std;

class date {

	int day;
	int month;
	int year;

public:
	//конструктор по умолчанию.
	date();
	//конструктор с параметрами.
	date(int day, int month, int year);
	//метод установки даты.
	void set(int day, int month, int year);
	//метод вывода даты на экран.
	void show(char symb = '/');
	//выдает количество дней, прошедших от рождества Христова.
	int daysAm();
	//превращает int в года от рождества христова.
	void intToDate(int days);
	int operator- (const date &Obj);
	date operator+ (const int days);
	operator int();
};

//перегруженный минус.
int date::operator- (const date &Obj) {

	date temp = Obj;

	int res = int(*this) - int(temp);

	return res;
}
date date::operator+ (const int days) {
	int dayCount = daysAm() + days;

	intToDate(dayCount);

	return *this;
}
date::operator int() {
	return daysAm();
}
void date::intToDate(int dayCount) {
	year = 0;

	//сколько дней в году
	int daysinyear = 365;

	//будем отнимать от количества дней 365 или 366 дней пока не выйдем за <365.
	for (dayCount; dayCount>daysinyear; ) {

		dayCount -= daysinyear;
		year++;

		if ((year + 1) % 4 == 0 || ((year + 1) % 100 == 0 && (year + 1) % 400 == 0))daysinyear = 366;
		else daysinyear = 365;
	}

	year++;

	month = 1;

	int daysinmonth = 31;

	while (dayCount>daysinmonth) {

		dayCount -= daysinmonth;
		month++;

		if (month == 1)daysinmonth = 31;
		else if (month == 2) {
			if ((year) % 4 == 0 || ((year) % 100 == 0 && (year) % 400 == 0))daysinmonth = 29;
			else daysinmonth = 28;

		}
		else if (month == 3)daysinmonth = 31;
		else if (month == 4)daysinmonth = 30;
		else if (month == 5)daysinmonth = 31;
		else if (month == 6)daysinmonth = 30;
		else if (month == 7)daysinmonth = 31;
		else if (month == 8)daysinmonth = 31;
		else if (month == 9)daysinmonth = 30;
		else if (month == 10)daysinmonth = 31;
		else if (month == 11)daysinmonth = 30;
		else if (month == 12)daysinmonth = 31;

	}

	if (dayCount == 0)day = 1;
	else day = dayCount;

}
int date::daysAm() {
	bool visokosniy = false;
	if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))visokosniy = true;

	int amDays = (year - 1) * 365 + (year - 1) / 4 - ((year - 1) % 400 != 0 && (year - 1) % 100 == 0) + day;

	for (int i = 2; i <= month; i++) {
		if (i == 2)amDays += 31;
		else if (i == 3) {
			if (visokosniy)amDays += 29;
			else { amDays += 28; }
		}
		else if (i == 4)amDays += 31;
		else if (i == 5)amDays += 30;
		else if (i == 6)amDays += 31;
		else if (i == 7)amDays += 30;
		else if (i == 8)amDays += 31;
		else if (i == 9)amDays += 31;
		else if (i == 10)amDays += 30;
		else if (i == 11)amDays += 31;
		else if (i == 12)amDays += 30;
		//else if(i==12)amDays+=31;
	}

	return amDays;
}
date::date() {
	day = 0;
	month = 0;
	year = 0;
}
date::date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}
void date::set(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}
void date::show(char symb) {
	if (day<10) cout << 0;
	cout << day;
	cout << symb;
	if (month<10) cout << 0;
	cout << month;
	cout << symb << year << '\n';
}

int main() {

	setlocale(0, "");

	cout << "Есть 2 даты\n";
	//текущая дата
	date someday;
	someday.set(3, 6, 2018);
	someday.show();

	//дата моего рождения
	date yearAgo;
	yearAgo.set(5, 7, 1989);
	yearAgo.show();

	//сколько я прожил на белом свете дней.

	cout << "Вычтем одну из другой и получим: \n";
	int res = someday - yearAgo;
	cout << res << endl;

	cout << "Прибавим к первой дате 365 дней: \n";
	//плюс тоже работает.
	someday = someday + 10;
	someday.show('.');

	cout << "Опять вычтем одну из другой и получим: \n";
	res = someday - yearAgo;
	cout << res << endl;

	cout << "Прибавим к первой дате 365 дней: \n";
	someday = someday + 10;
	someday.show('.');

	cout << "Опять вычтем одну из другой и получим: \n";
	res = someday - yearAgo;
	cout << res << endl;

	cout << "Прибавим к первой дате 365 дней: \n";
	someday = someday + 10;
	someday.show('.');

	cout << "Опять вычтем одну из другой и получим: \n";
	res = someday - yearAgo;
	cout << res << endl;
	system("pause");
	return 0;
}
