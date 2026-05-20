#pragma once

class Patient;

class Vitals;

class AlertStrategy {

public:

	virtual void calculate(const Patient& patient, const Vitals& vitals) = 0;

	virtual ~AlertStrategy() = default;

};