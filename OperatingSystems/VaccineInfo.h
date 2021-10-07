#pragma once
#include <string>;
#include <iostream>;

/*
Using contigous allocation this class functions to show how data is retrieved from storage
*/

using namespace std;

class VaccineInfo
{

	string data[15] = {
	"The first mass vaccination programme started in early December 2020", "and as of and as of 15 February 2021,", "175.3 million vaccine doses have been administered.",
	"Even if you have already had COVID-19\nyou should be vaccinated when it is offered to you.", "The protection that someone gains from having COVID-19 will vary from person to person,\nand we also don’t know how long natural immunity might last.",
	"Vaccines are usually tested in adults first,\nto avoid exposing children who are still developing and growing.\nCOVID-19 has also been a more serious and dangerous disease among older populations.", "Now that the vaccines have been determined to be safe for adults,\nthey are being studied in children. Once those studies have been completed,\nwe should know more and guidelines will be developed.", "In the meantime, make sure children continue to physical distance from others,\nclean their hands frequently, sneeze and cough into their elbow and wear a mask if age appropriate.",
	"The impact of COVID-19 vaccines on the pandemic will depend on several factors.\nThese include the effectiveness of the vaccines;\nhow quickly they are approved,\nmanufactured, and delivered;\nthe possible development of other variants and how many people get vaccinated", "Whilst trials have shown several COVID-19 vaccines to have high levels of efficacy,\nlike all other vaccines, COVID-19 vaccines will not be 100% effective. WHO is working to help ensure that approved vaccines are as effective as possible, so they can have the greatest impact on the pandemic.",
	"The COVID-19 vaccines are safe for most people 18 years and older,\nincluding those with pre-existing conditions of any kind,\nincluding auto-immune disorders.\nThese conditions include: hypertension, diabetes, asthma, pulmonary, liver and kidney disease, as well as chronic infections that are stable and controlled.\nIf supplies are limited in your area, discuss your situation with your care provider if you:",
	"Have a compromised immune system", "Are pregnant or nursing your baby", "Have a history of severe allergies, particularly to a vaccine (or any of the ingredients in the vaccine)", "Are severely frail ",
	};

	//https://www.who.int/news-room/q-a-detail/coronavirus-disease-(covid-19)-vaccines?adgroupsurvey={adgroupsurvey}&gclid=Cj0KCQjwgtWDBhDZARIsADEKwgOYXAH9nFcjieOvi9cXmXPMn36x8P22sJlPxM9ic68vi395pusO1oUaAkcfEALw_wcB

public: 

	//Contains info on Vaccine

	void getInfo(int start, int length);
};

