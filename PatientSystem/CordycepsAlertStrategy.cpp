#include "CordycepsAlertStrategy.h"

#include "Patient.h"
#include "Vitals.h"
#include "PatientAlertLevels.h"

//calculate alert level based on respiratory rate referencing table 1
AlertLevel CordycepsAlertStrategy::calculate(const Patient& patient, const Vitals& vitals) {

	if (vitals.RR() > 40) { // RR > 40 = red
		return AlertLevel::Red;
	}
	else if (vitals.RR() > 30) { //RR > 30 = ORANGE
		return AlertLevel::Orange;
	}
	else if (vitals.RR() > 20) { //RR > 20 = YELLOW
		return AlertLevel::Yellow;
	}

	return AlertLevel::Green; // otherwise green
	
}
