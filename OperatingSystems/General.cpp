#include <iostream>;
#include <conio.h>;
#include <Windows.h>;
#include "General.h";

using namespace std;

#define KEY_ENTER 13
#define KEY_DOWN 80
#define KEY_UP 72

int General::Selection(string title, string arraylist[], short int col)
{

	char key = _getch();
	int value = key;
	int selected = 0, b = 0;

	//count array

	int arraynum = 0;

	while (arraylist[b] != " ")
	{
		arraynum++; b++;
	}

	do {
		switch (_getch())
		{
		case KEY_DOWN:
			selected++;
			break;

		case KEY_UP:
			selected--;
			break;
		
		}
		
		if (selected == arraynum) //Bring selected Back to first option
		{
			selected = 0;
		}
		else if (selected < 0) //If it goes to a negative number it goes to the bottom of the list instead
		{
			selected = arraynum - 1;
		}

		system("cls"); //clear screen

		cout << title << endl;

		for (int i = 0; i < arraynum; i++)
		{
			if (selected == i)
			{
				ColorSelect(col);//Color
				cout << arraylist[i] << endl;
			}
			else
			{
				ColorSelect(7);//White Color 7
				cout << arraylist[i] << endl;
			}
		}

		ColorSelect(7);// Make Sure Everthing Stays White

		key = _getch();
		value = key;


	} while (value != KEY_ENTER);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	return selected + 1;

}

void General::ColorSelect(short int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

string General::DisplayBool(bool result) {

	if (result) {
		return "YES";
	}
	else if (!result) {
		return "NO";
	}
}