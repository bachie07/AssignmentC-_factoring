#pragma once

#include "Patient.h"
#include "IObserver.h"


class HospitalAlertSystemFacade : public IObserver
{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	void sendAlertForPatient(Patient* p);

	void onAlertLevelChanged(Patient* patient) override;

};

