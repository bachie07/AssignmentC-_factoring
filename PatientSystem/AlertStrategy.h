#pragma once
#include "PatientAlertLevels.h"

//defines interface of all alert strategies
// each disease will have its own strategy

class Patient;

class Vitals;

class AlertStrategy {

public:

	//pure virtual - the different strategies will implement this

	virtual AlertLevel calculate(const Patient& patient, const Vitals& vitals) = 0;

	//virtual destructor
	virtual ~AlertStrategy() = default;

};