#pragma once

#include "Patient.h"
#include "IObserver.h"


class GPNotificationSystemFacade : public IObserver {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);

	void sendAlertForPatient(Patient* p);
	void onAlertLevelChanged(Patient* patient) override;

};

