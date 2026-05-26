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

//load patients from text file
//format: uid|LastName, FirstName|DD-MM-YYYY|Disease|BT,BP,HR,RR;...

std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file); 
    if (inFile.is_open()) { // file checks

        string line;
        
        while (getline(inFile, line)) { // reads line by line

            stringstream ss(line);
            string uid, fullName, birthday, disease, vitalsStr;

            // get line at |, storing it in the specific variable
            getline(ss, uid, '|');
            getline(ss, fullName, '|');
            getline(ss, birthday, '|');
            getline(ss, disease, '|');
            getline(ss, vitalsStr);

            // same thing for name
            stringstream nameSS(fullName);

            string lastName, firstName;

            getline(nameSS, lastName, ',');
            getline(nameSS, firstName, ',');



            std::tm t{};

            std::istringstream dateSS(birthday);

            dateSS >> std::get_time(&t, "%d-%m-%Y"); // read birthday string and pass into c++ time structure

            Patient* p = new Patient(firstName, lastName, t); // instantiate the patient object

            p->addDiagnosis(disease); // add diagnosis to patient object

            if (!vitalsStr.empty()) { // check if theres vital data

                stringstream vitalsSS(vitalsStr);
                string vitalToken;
                
                while (getline(vitalsSS, vitalToken, ';')) {

                    stringstream vSS(vitalToken);
                    string bt, bp, hr, rr;

                    // split value into metrics
                    getline(vSS, bt, ',');
                    getline(vSS, bp, ',');
                    getline(vSS, hr, ',');
                    getline(vSS, rr, ',');

                    Vitals* v = new Vitals(stof(bt), stoi(bp), stoi(hr), stoi(rr)); // store in Vitals object, stof convert to float, stof convert to int

                    p->addVitals(v); // add vitals to patients object


                }
            }
                
            patients.push_back(p); // store in patients vector
         

        }

    }
    return patients;
}
