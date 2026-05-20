#pragma once

class Patient;

class Vitals;

class AlertStrategy {

public:

	//pure virtual - the different strategies will implement this

	virtual void calculate(const Patient& patient, const Vitals& vitals) = 0;

	//virtual destructor
	virtual ~AlertStrategy() = default;

};