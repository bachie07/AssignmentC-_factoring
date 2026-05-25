#include "KepralAlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"
#include "PatientAlertLevels.h"

//calculate alert level bawed on heart rate and age referencing table 1 
AlertLevel KepralAlertStrategy::calculate(const Patient& patient, const Vitals& vitals) {

	if (patient.age() < 12 && vitals.HR() > 120) { // Age < 12 and HR > 120 = RED
		return AlertLevel::Red;
	}
	else if (patient.age() >= 12 && vitals.HR() > 100) { // Age >= 12 and HR > 100 = Red
		return AlertLevel::Red;
	}

	return AlertLevel::Green; // otherwise green

}