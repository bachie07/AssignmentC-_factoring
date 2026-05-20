#include "CordycepsAlertStrategy.h"

#include "Patient.h"
#include "Vitals.h"
#include "PatientAlertLevels.h"

AlertLevel CordycepsAlertStrategy::calculate(const Patient& patient, const Vitals& vitals) {

	if (vitals.RR() > 40) {
		return AlertLevel::Red;
	}
	else if (vitals.RR() > 30) {
		return AlertLevel::Orange;
	}
	else if (vitals.RR() > 20) {
		return AlertLevel::Yellow;
	}

	return AlertLevel::Green;
	
}
