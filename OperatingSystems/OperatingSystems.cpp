// OperatingSystems.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include "OS_Method.h";
#include "General.h";

/*
	Date Created: 14/04/2021
	Authors: Karl-Johan Bailey
	Course: Operating Systems

	The case is that they're 5 vaccines avaliable and many applicants. The goal is to get Applicants, shedule their taking of the vaccine based on priority, contact them and give them these vaccines
*/

using namespace std;

int main()
{ 

	//Variables and Objects

	General general; //To allow for ease of use with UI and display of information
	OS_Methods osMethod; //To organize and carry out various simulations

	string methods[5] = { "Covid Vaccine Listing", "Contact Applicants   ", "Give Vaccine         ", "Exit                 ", " " }; //This list is used to display information
	bool running = true;

	while (running)
	{
		cout << "ENTER ARROW UP"; //GET ANY KEY 

		switch (general.Selection("COVID CRISIS SOFTWARE", methods, 200)) //Selection works by giving the header title, the list of choices and the colour code
		{
		case 1:
			osMethod.covidVaccinePriority(); //Priority Scheduling
			break;

		case 2:
			osMethod.contactApplicants(); //Process Synchronization With Mutexlocks
			break;

		case 3:
			osMethod.giveVaccines(); //Contigous Allocation
			break;

		case 4:
			running = false;
			break;
		}
	}

	return 0;
}





