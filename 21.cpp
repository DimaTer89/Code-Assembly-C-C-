/*Реализовать 21 очко*/ 
#include <iostream>
#include <Windows.h>
#include <time.h>
#define NAME_KARD 9
#define MAST_KARD 4

using namespace std;

class TwentyOne
{
public:
	const char* kard[NAME_KARD] = {"6", "7", "8", "9", "10", "Валет", "Дама", "Король", "Туз"};
	const char* mast[MAST_KARD] = {"Пика", "Бубна", "Черви", "Крест"};
	int kol_kard[NAME_KARD] = { 6,7,8,9,10,2,3,4,11 };
    int coloda[MAST_KARD][NAME_KARD] = { { 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 } };
	static int scoreKomp;
	static int scoreGamer;
	void komp();
	void gamer();
	int getCard();
	int Proverka();
	void Repeat();
	bool prov(int a,int mas);
};
void TwentyOne::komp()
{
	int kol = 0;
	while (kol < 2)
	{
		scoreKomp+=getCard();
		kol++;
	}
	if(scoreKomp < 21)
		scoreKomp += getCard();
	cout << " Счёт компьютера = " << scoreKomp << endl;
}
void TwentyOne::gamer()
{
	int kol = 0;
	char key;
	while (kol < 2)
	{
		scoreGamer+=getCard();
		kol++;
	}
	cout << " Счёт игрока = " << scoreGamer << endl;
	do
	{
		cout << " Взять карту (y/n) : ";
		cin >> key;
		if (key == 'y')
		{
			scoreGamer += getCard();
			cout << " Счёт игрока = " << scoreGamer << endl;
		}
	} while (key != 'n');
}
int TwentyOne::getCard()
{
	int kol = 0;
	int mas;
	int name;
	int numb;
	while (kol < 1)
	{
		mas = rand() % 4;
		name = rand() % 9;
		numb= kol_kard[name];
		if (!prov(numb,mas))
		{
			coloda[mas][name] = numb;
			kol++;
		}
	}
	cout << " Выпала карта : " << kard[name] << " " << mast[mas] << "(очков: " << kol_kard[name] << ")"<<endl;
	return numb;
}
int TwentyOne::Proverka()
{
	if ((scoreGamer > scoreKomp) && scoreGamer <= 21)
	{
		return 1;
	}
	if ((scoreGamer < scoreKomp) && scoreKomp <= 21)
	{
		return 0;
	}
	if (scoreGamer > 21 && scoreKomp > 21)
	{
		return -1;
	}
	if ((scoreGamer > scoreKomp) && (scoreKomp < 21 && scoreGamer>21))
	{
		return 2;
	}
	if ((scoreGamer < scoreKomp) && (scoreGamer < 21 && scoreKomp>21))
	{
		return 3;
	}
}
void TwentyOne::Repeat()
{
	for (int i = 0; i < MAST_KARD; i++)
	{
		for (int j = 0; j < NAME_KARD; j++)
		{
			 coloda[i][j]=0;
		}
	}
	
}
bool TwentyOne::prov(int numb, int mas)
{
	for (int i = 0; i < NAME_KARD; i++)
	{
	    if (coloda[mas][i] == numb)
		    return true;
	}
	return false;
	
}
int TwentyOne::scoreGamer = 0;
int TwentyOne::scoreKomp = 0;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	char ch;
	int schetGamer = 0;
	int schetKomp = 0;
	TwentyOne gamerVSkomp;
	do
	{
		system("cls");
		gamerVSkomp.gamer();
		gamerVSkomp.komp();
		if (gamerVSkomp.Proverka() == 1)
		{
			cout << " Вы выиграли , поздравляю !!!\n";
			schetGamer += 10;
		}
		if (gamerVSkomp.Proverka() == 0)
		{
			cout << " Вы проиграли , не огорчайтесь , есть шанс отыграться \n";
			schetKomp += 10;
		}
		if (gamerVSkomp.Proverka() == -1)
		{
			cout << " Никто не выиграл \n";
		}
		if (gamerVSkomp.Proverka() == 2)
		{
			cout << " Вы проиграли , не огорчайтесь , есть шанс отыграться \n";
			schetKomp += 10;
		}
		if (gamerVSkomp.Proverka() == 3)
		{
			cout << " Вы выиграли , поздравляю !!!\n";
			schetGamer += 10;
		}
		cout << " Продолжить игру (y/n): ";
		cin >> ch;
		if (ch == 'y')
		{
			gamerVSkomp.Repeat();
			TwentyOne::scoreGamer = 0;
			TwentyOne::scoreKomp = 0;
		}
		
	} while (ch != 'n');
	cout << " Счёт игры : \n";
	cout << " Игрок = " << schetGamer << endl;
	cout << " Компьютер = " << schetKomp << endl;
	if (schetGamer > schetKomp)
		cout << " Поздравляю , вы играли великолепно \n";
	else if (schetGamer < schetKomp)
		cout << " В этот раз удача была не на вашей стороне \n";
	else
		cout << " Ничья \n";
	system("pause");
}
