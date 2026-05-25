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


            std::tm t{};

            std::istringstream dateSS(birthday);

            dateSS >> std::get_time(&t, "%d-%m-%Y");

            Patient* p = new Patient(firstName, lastName, t);

            p->addDiagnosis(disease);

            if (!vitalsStr.empty()) {

                stringstream vitalsSS(vitalsStr);
                string vitalToken;
                
                while (getline(vitalsSS, vitalToken, ';')) {

                    stringstream vSS(vitalToken);
                    string bt, bp, hr, rr;

                    getline(vSS, bt, ',');
                    getline(vSS, bp, ',');
                    getline(vSS, hr, ',');
                    getline(vSS, rr, ',');

                    Vitals* v = new Vitals(stof(bt), stoi(bp), stoi(hr), stoi(rr));

                    p->addVitals(v);


                }
            }
                
            patients.push_back(p);
         

        }

    }
    return patients;
}
