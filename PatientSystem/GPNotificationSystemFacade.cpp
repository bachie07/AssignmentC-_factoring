#include "GPNotificationSystemFacade.h"

#include <iostream>

//implement IObserver to receive notification when patient hit red alert
//onAlertLevelChanged called automatically by patient when alert changes
//delegate to the existing sendGPnofiticationforpatient method


GPNotificationSystemFacade::GPNotificationSystemFacade()
{ }

GPNotificationSystemFacade::~GPNotificationSystemFacade()
{ }

void GPNotificationSystemFacade::sendGPNotificationForPatient(Patient* p)
{
	if (p->alertLevel() > AlertLevel::Orange) {
		// A mocked alert message. A real message would use an SMS/pager gateway or similar
		std::cout << std::endl;
		std::cout << "This is an notification to the GPs:" << std::endl;
		std::cout << "Patient: " << p->humanReadableID() << " should be followed up" << std::endl;
	}
}

void GPNotificationSystemFacade::onAlertLevelChanged(Patient* patient) {
	sendGPNotificationForPatient(patient);
}