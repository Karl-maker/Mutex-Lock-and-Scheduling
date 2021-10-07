#pragma once

//Used for displaying data and UI design

#include <iostream>;

using namespace std;

class General
{
public:

	int Selection(string title, string arraylist[], short int col);
	void ColorSelect(short int col);
	string DisplayBool(bool result);

};

