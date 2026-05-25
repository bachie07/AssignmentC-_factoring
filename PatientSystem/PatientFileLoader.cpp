#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {

        string line;
        
        while (getline(inFile, line)) {

            stringstream ss(line);
            string uid, fullName, birthday, disease, vitalsStr;

            getline(ss, uid, '|');
            getline(ss, fullName, '|');
            getline(ss, birthday, '|');
            getline(ss, disease, '|');
            getline(ss, vitalsStr);

            stringstream nameSS(fullName);

            string lastName, firstName;

            getline(nameSS, lastName, ',');
            getline(nameSS, firstName, ',');




         

        }
    }

    return patients;
}
