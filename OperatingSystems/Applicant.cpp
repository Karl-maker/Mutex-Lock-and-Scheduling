#include "Applicant.h"

//Applicant

Applicant::Applicant() {
	this->first_name = "";
	this->last_name = "";
	this->age = 0;
	this->is_frontlineworker = false;
}

Applicant::Applicant(string firstname, string lastname, int age, bool is_frontlineworker) {
	//...
	this->first_name = firstname;
	this->last_name = lastname;
	this->age = age;
	this->is_frontlineworker = is_frontlineworker;
}

float Applicant::getWaitTime() {
	return Applicant::wait_time;
}

void Applicant::startWaitTime() {

}

void Applicant::endWaitTime() {

}

void Applicant::setStation(int i) {
	this->station = i;
}

int Applicant::getStation() {
	return Applicant::station;
}

bool Applicant::getMutex() {
	return Applicant::mutex;
}

void Applicant::lockMutex() {
	this->mutex = true;
}

void Applicant::freeMutex() {
	this->mutex = false;
}

int Applicant::getAge() {
	return Applicant::age;
}

bool Applicant::getIsFrontLineWorker() {
	return Applicant::is_frontlineworker;
}

string Applicant::getName() {
	return first_name + " " + last_name;
}

bool Applicant::getIsVisited() {
	return Applicant::isVisited;
}

void Applicant::setIsVisited(bool visited) {
	this->isVisited = visited;
}

bool Applicant::isVaccinated() {
	return vaccinated;
}

void Applicant::vaccinateApplicant() {
	this->vaccinated = true;
}
