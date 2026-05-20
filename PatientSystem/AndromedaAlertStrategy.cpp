#include "AndromedaAlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"
#include "PatientAlertLevels.h"

AlertLevel AndromedaAlertStrategy::calculate(const Patient& patient, const Vitals& vitals) {

	if (vitals.BP() > 140) {
		return AlertLevel::Red;
	}
	else if (vitals.BP() > 130) {

		return AlertLevel::Orange;
	}
	else if (vitals.BP() > 110) {
		
		return AlertLevel::Yellow;
	}

}