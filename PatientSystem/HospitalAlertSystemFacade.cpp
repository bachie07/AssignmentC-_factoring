#include "HospitalAlertSystemFacade.h"

#include <iostream>

//implement IObserver to receive notification when patient hit red alert
//onAlertLevelChanged called automatically by patient when alert changes
//delegate to the existing sendAlertforpatient method


HospitalAlertSystemFacade::HospitalAlertSystemFacade()
{ }

HospitalAlertSystemFacade::~HospitalAlertSystemFacade()
{
}

void HospitalAlertSystemFacade::sendAlertForPatient(Patient* p)
{
	if (p->alertLevel() == AlertLevel::Red) {
		// A mocked alert message. A real message would use an SMS/pager gateway or similar
		std::cout << std::endl;
		std::cout << "This is an alert to the hospital:" << std::endl;
		std::cout << "Patient: " << p->humanReadableID() << " has a critical alert level" << std::endl;
	}
}

void HospitalAlertSystemFacade::onAlertLevelChanged(Patient* patient) {
	sendAlertForPatient(patient);
}