
#include <iostream>;
#include "Station.h";
#include "Applicant.h";
#include "VaccineInfo.h";

using namespace std;

Station::Station(int i) {
	this->stationNo = i;
}

int Station::getStationNo() {
	return Station::stationNo;
}

void Station::administerVaccine(int selection, Applicant* selectedApplicants) {

	VaccineInfo info;

	//Parallel Arrays

	int data_start[5] = {0, 3, 5, 8, 10};
	int data_length[5] = {3, 2, 3, 2, 5};
	int random = rand() % 5;


	if (!selectedApplicants[selection].isVaccinated()) {
		system("cls");
		info.getInfo(data_start[random], data_length[random]);//Give random fact about Vaccine
		selectedApplicants[selection].vaccinateApplicant();
		system("pause");
	}
	else {
		system("cls");
		cout << selectedApplicants[selection].getName() << " already was given a Vaccine\n\n"; //Print Info On Vaccine
		system("pause");
	}
	
}

void Station::contactApplicant(int selection, Applicant *selectedApplicants) {

	if (selectedApplicants[selection].getMutex() && selectedApplicants[selection].getStation() == Station::stationNo) {
		system("cls");
		cout << "Ended Call With " << selectedApplicants[selection].getName() << "...\n\n";
		//selectedApplicants[selection].setStation(0);
		selectedApplicants[selection].freeMutex();
		system("pause");
	}
	else if (!selectedApplicants[selection].getMutex()) {
		system("cls");
		cout << "Start Call With " << selectedApplicants[selection].getName() << "\n\n";
		selectedApplicants[selection].setStation(Station::stationNo);
		selectedApplicants[selection].lockMutex(); 
		system("pause");
	}
	else if (selectedApplicants[selection].getMutex() && selectedApplicants[selection].getStation() != Station::stationNo) {
		system("cls");
		cout << selectedApplicants[selection].getName() << " Currently Being Contacted By Station #" << selectedApplicants[selection].getStation() << "\n\n";
		system("pause");
	}
}
