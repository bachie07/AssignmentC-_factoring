#pragma once
#include "AlertStrategy.h"

class CordycepsAlertStrategy : public AlertStrategy {

public:
	void calculate(const Patient& patient, const Vitals& vitals) override;
};