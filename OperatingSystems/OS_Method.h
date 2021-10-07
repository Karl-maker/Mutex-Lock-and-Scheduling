#pragma once

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

#include <queue>;

#include "Applicant.h";

class OS_Methods
{
    //Attributes

    Applicant selectedApplicants[5];
    string selectedApplicantsLabel[6];

public:
 
    //Methods

	void covidVaccinePriority(); //To Show Sheduling
	queue<Applicant> organizePriorityQueue(Applicant* applicant);
    void contactApplicants();
    void giveVaccines();

};