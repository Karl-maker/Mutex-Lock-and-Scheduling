/*
The goal of this class is to organize and harmonize all the algorithms and objects that play a part in demonstrating the different simulations

This application focuses on organizing and administering vaccines to applicants. The goal is to use this as a way to show how these OS concepts work:
a) Sheduling with priority
b) Process Synchronization using mutexlocks and semaphors 
c) Storage Management with Contigous Allocation

This carries out many task:

1. Entering applicants for the vaccine
2. Prioritizing them
3. Contacting the selected applicants
4. Administering the vaccine to them 

*/

#include <iostream>;
#include "OS_Method.h"
#include "General.h";
#include "Station.h";
#include <sstream>;

const int APPLICANT_NUM = 10; //Number of Applicants allowed to enter
const int VACCINE_NUM = 5; //Number of avaliable vaccines
int number_check = 0;
Station station1(1);
Station station2(2);
Station station3(3);
General general;

void OS_Methods::giveVaccines() {

	selectedApplicantsLabel[5] = " ";

	bool running = true;
	int selection = 0;

	while (running) {
		system("cls");

		string list[5] = { "Station #1", "Station #2", "Station #3", "Exit      ", " " };

		cout << "PRESS UP ARROW";

		switch (general.Selection("Pick Station:", list, 27)) {

		case 1:
			selection = general.Selection("Give Vaccine To A Applicant Below", selectedApplicantsLabel, 237) - 1;

			station1.administerVaccine(selection, selectedApplicants);
			break;

		case 2:
			selection = general.Selection("Give Vaccine To A Applicant Below", selectedApplicantsLabel, 237) - 1;

			station2.administerVaccine(selection, selectedApplicants);
			break;

		case 3:
			selection = general.Selection("Give Vaccine To A Applicant Below", selectedApplicantsLabel, 237) - 1;

			station2.administerVaccine(selection, selectedApplicants);
			break;

		case 4:
			running = false;
			break;

		}
	}
}

void OS_Methods::contactApplicants() {

	selectedApplicantsLabel[5] = " ";

	bool running = true;
	int selection = 0;

	while (running) {
		system("cls");

		string list[5] = { "Station #1", "Station #2", "Station #3", "Exit      ", " " };

		cout << "PRESS UP ARROW";

		switch (general.Selection("Pick Station:", list, 27)) {

		case 1:
			selection = general.Selection("Contact A Applicant Below", selectedApplicantsLabel, 237) - 1;

			station1.contactApplicant(selection, selectedApplicants);
			break;

		case 2:
			selection = general.Selection("Contact A Applicant Below", selectedApplicantsLabel, 237) - 1;

			station2.contactApplicant(selection, selectedApplicants);
			break;

		case 3:
			selection = general.Selection("Contact A Applicant Below", selectedApplicantsLabel, 237) - 1;

			station2.contactApplicant(selection, selectedApplicants);
			break;

		case 4:
			running = false;
			break;
		
		}



	}
}

queue<Applicant> OS_Methods::organizePriorityQueue(Applicant* applicants) {

	int i = 0;
	
	queue<Applicant> queue;

	const int MAX_AGE = 75; //1st
	const int MID_AGE = 65; //2nd
	const int MIN_AGE = 16; //3rd

	while (i < APPLICANT_NUM) {

		if (applicants[i].getIsFrontLineWorker() && !applicants[i].getIsVisited()) {
			//Queue First
			applicants[i].setIsVisited(true);
			if (number_check < VACCINE_NUM) {
				queue.push(applicants[i]);
				selectedApplicants[number_check] = applicants[i];
				selectedApplicantsLabel[number_check] = applicants[i].getName();
				number_check++;
			}
		}
		i++;
	}

	i = 0;

	while (i < APPLICANT_NUM) {

		if (applicants[i].getAge() >= MAX_AGE && !applicants[i].getIsVisited()) {
			//Queue Second
			applicants[i].setIsVisited(true);
			if (number_check < VACCINE_NUM) {
				queue.push(applicants[i]);
				selectedApplicants[number_check] = applicants[i];
				selectedApplicantsLabel[number_check] = applicants[i].getName();
				number_check++;
			}
		}
		i++;
	}

	i = 0;

	while (i < APPLICANT_NUM) {

		if (applicants[i].getAge() < MAX_AGE && applicants[i].getAge() >= MID_AGE && !applicants[i].getIsVisited()) {
			//Queue Third
			applicants[i].setIsVisited(true);
			if (number_check < VACCINE_NUM) {
				queue.push(applicants[i]);
				selectedApplicants[number_check] = applicants[i];
				selectedApplicantsLabel[number_check] = applicants[i].getName();
				number_check++;
			}
		}
		i++;
	}

	i = 0;

	while (i < APPLICANT_NUM) {

		if (applicants[i].getAge() >= MIN_AGE && applicants[i].getAge() < MID_AGE && !applicants[i].getIsVisited()) {
			//Queue Fourth
			applicants[i].setIsVisited(true);
			if (number_check < VACCINE_NUM) {
				queue.push(applicants[i]);
				selectedApplicants[number_check] = applicants[i];
				selectedApplicantsLabel[number_check] = applicants[i].getName();
				number_check++;
			}
		}
		i++;
	}

	i = 0;

	return queue;

}

void OS_Methods::covidVaccinePriority()
{

	bool gettingInput = true;

	//Enter Applicant Info and Calculate Priority

	system("cls");

	//They're a limited number of vaccines at a time

	//A list of applicants will be organized to show a priority list of who needs get the vaccines most to least

	//Applicant Data Entry

	int applicant_num = 1;
	bool applying = true;
	Applicant applicants[APPLICANT_NUM]; //CONST

	while (applying) {

		string firstname;
		string lastname;

		cout << "Please Enter First Name: ";
		getline(cin, firstname);

		cout << "\nPlease Enter Last Name: ";
		getline(cin, lastname);

		int age = 0;
		bool isFrontLine = false;

		system("cls");

		//ISSUE GETTING SECOND INT

		gettingInput = true;

		while (gettingInput && applicant_num <= APPLICANT_NUM) {
			try {

				cout << "Enter Age: ";
				cin >> age;
				cin.clear();
				cin.ignore();
				if (age >= 16 && age <= 100) { //NOT A NUMBER
					gettingInput = false;
				}
				else if (age < 16) {
					throw 404;
				}
				else {
					throw 422; // Throw an exception when a problem arise
				}

				system("cls");
			}
			catch (int error) {

				switch (error) {

				case 422:
					cout << "\n\nPlease Enter A Number" << endl;
					break;

				case 404:
					cout << "\nChildren Below 16 Aren't Applicable To Vaccine\n" << endl;
					break;
				} //switch
				system("pause");
				system("cls");
		
			} 
		}

		gettingInput = true;

		system("cls");


		string list[] = { "Yes", "No", " " };

		/*
		switch (Selection("Are You A Frontline Worker?", list, 200)) {
		case 1:
			isFrontLine = true;
			break;

		case 2:
			isFrontLine = false;
			break;
		}
		*/

		string frontline_result;

		while (gettingInput) {

			cout << "Are You A Frontline Worker?";
			general.ColorSelect(200);
			cout << "(Y/N): ";
			general.ColorSelect(7);
			cin >> frontline_result;

			if (frontline_result == "Y" || frontline_result == "y") {
				isFrontLine = true;
				gettingInput = false;
			}
			else if (frontline_result == "N" || frontline_result == "n") {
				isFrontLine = false;
				gettingInput = false;
			}
			else {
				system("cls");
				general.ColorSelect(200);
				cout << "Please Enter Y or N!";
				general.ColorSelect(7);
			}

			system("cls");
		
		}


		Applicant applicant(firstname, lastname, age, isFrontLine);
		applicants[applicant_num - 1] = applicant;

		//Check if User will Enter More

		cout << "PRESS UP ARROW";

		switch (general.Selection("Enter Another Applicant?", list, 200)) {
		case 1:
			if (applicant_num >= APPLICANT_NUM) {
				applying = false;
			}
			else {
				applying = true;
				applicant_num++;
			}
			
			break;

		case 2:
			applying = false;
			break;
		}

		system("cls");

		cin.clear();
		cin.ignore();

	}//While

	//Organize Priority Queue 

	queue<Applicant> queue = organizePriorityQueue(applicants); //Returns the queue

	cout << "List of Applicants to get COVID VACCINE from higest priority to lowest.\n" << endl;

	int num = 1;

	general.ColorSelect(14);

	while (!queue.empty()) {
		Applicant applicant = queue.front();
		queue.pop();
		cout << num << ") " << applicant.getName() << " | Age: " << applicant.getAge() << " | Front Line Worker: " << general.DisplayBool(applicant.getIsFrontLineWorker()) << "\n" << endl;
		num++;
	}

	general.ColorSelect(7);

	system("pause");

	cin.clear();
	cin.ignore();
}
