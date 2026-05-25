#include "AndromedaAlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"
#include "PatientAlertLevels.h"

//calculate alert level based on blood pressure as per table 1
AlertLevel AndromedaAlertStrategy::calculate(const Patient& patient, const Vitals& vitals) {

	if (vitals.BP() > 140) { // if bp > 140 = red
		return AlertLevel::Red;
	}
	else if (vitals.BP() > 130) { // if bp > 130 = orange

		return AlertLevel::Orange;
	}
	else if (vitals.BP() > 110) { // if bp > 110 = yellow
		
		return AlertLevel::Yellow;
	}

	return AlertLevel::Green; // otherwise green
}