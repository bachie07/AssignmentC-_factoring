#pragma once

class Patient;

class IObserver {

public:
	virtual void onAlertLevelChanged(Patient* patient) = 0;
	virtual ~IObserver() = default;
};