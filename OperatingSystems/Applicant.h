#pragma once

#include <iostream>
#include <ctime>

using namespace std;

class Applicant
{
	//Attributes

	int age, station;
	float wait_time;
	string first_name;
	string last_name;
	bool is_frontlineworker, isVisited = false, mutex = false;
	bool vaccinated = false;
	
	//Constructor

public:

	Applicant();
	Applicant(string firstname, string lastname, int age, bool is_frontlineworker);

	//Getters

	float getWaitTime();

	bool isVaccinated();

	int getAge();

	bool getIsFrontLineWorker();

	string getName();

	bool getIsVisited();

	bool getMutex();

	int getStation();

	//Setters

	void setIsVisited(bool visited);
	void setStation(int i);
	void vaccinateApplicant();

	//Methods

	void lockMutex();
	void freeMutex();
	void startWaitTime();
	void endWaitTime();


	//16 - 64 has priority 4
	//65 - 74 has priority 3
	//Ages 75+ has priority 2
	//FrontLineWorkers has priority 1

};

