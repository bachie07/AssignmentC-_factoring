#include "KepralAlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"
#include "PatientAlertLevels.h"

AlertLevel KepralAlertStrategy::calculate(const Patient& patient, const Vitals& vitals) {

	if (patient.age() < 12 && vitals.HR() > 120) {
		return AlertLevel::Red;
	}
	else if (patient.age() >= 12 && vitals.HR() > 100) {
		return AlertLevel::Red;
	}

	return AlertLevel::Green;

}