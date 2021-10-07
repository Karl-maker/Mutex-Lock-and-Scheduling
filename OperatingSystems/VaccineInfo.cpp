#include "VaccineInfo.h"

void VaccineInfo::getInfo(int start, int length) {
	
	int loop = start;
	int i = 0;

	while (i < length) {
		cout << VaccineInfo::data[loop] << "\n";
		loop++;
		i++;
	}

	cout << "\n\n";
}