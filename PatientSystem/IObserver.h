#pragma once

class Patient;

// abstract observer interface for Observer pattern
//Any class wants to be notified of patient alert change must inherit form this and implement onAlertLevelChanged()


class IObserver {

public:
	//called automatically when patients alert level changed to red
	virtual void onAlertLevelChanged(Patient* patient) = 0;
	virtual ~IObserver() = default;
};