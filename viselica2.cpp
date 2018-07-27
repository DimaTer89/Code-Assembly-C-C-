#include <windows.h>
#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 
#include <cctype> 
using namespace std;
void paint(int n)
{
	if (n == 9)
	{
		cout << "   __\n";
	}
	if (n == 8)
	{
		cout << "   __\n"
			<< "  |\n";
	}
	if (n == 7)
	{
		cout << "   __\n"
			<< "  |  |\n";
	}
	if (n == 6)
	{
		cout << "   __\n"
			<< "  |__|\n";

	}
	if (n == 5)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "    |\n"
			<< "    |\n";
	}
	if (n == 4)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\n"
			<< "    |\n";
	}
	if (n == 3)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n";
	}
	if (n == 2)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   /\n ";
	}
	if (n == 1)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   / \\\n ";
	}
	if (n == 0)
	{
		cout << "    |\n"
			<< "   _|_\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   / \\\n ";
	}
}
const int NUM = 26;
const string wordlist[NUM] = { "apiary","beetle","cereal","danger","ensign",
"florid","garage","health","insult","jackal",
"keeper","loaner","manage","nonce","onset",
"plaid","quilt","remote","stolid","train",
"useful","valid","whence","xenon","yearn","zippy" };
int main()
{
	system("cls");

	srand((unsigned)time(0));
	char play;
	cout << "Will you play a word game? <y/n> "; // запуск игры в слова 
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		system("cls");
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 10;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl; // вывод слова 
		while (guesses>0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess !\n";
				--guesses;
				paint(guesses);
				badchars += letter; // добавить к строке 
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				// Проверить, не появляется ли буква еще раз 
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << " . \n";
		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye\n";
	return 0;
}
