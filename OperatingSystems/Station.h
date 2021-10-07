#pragma once

//These are to be looked as a process/thread, they work on data which is the applicants

#include <iostream>;
#include "Applicant.h";

using namespace std;

class Station
{
	int stationNo;

public:

	Station(int i);

	int getStationNo();
	void contactApplicant(int selection, Applicant *applicants);
	void administerVaccine(int selection, Applicant* applicants);

};

