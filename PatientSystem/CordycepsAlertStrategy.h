#pragma once
#include "AlertStrategy.h"

class CordycepsAlertStrategy : public AlertStrategy {

public:
	AlertLevel calculate(const Patient& patient, const Vitals& vitals) override;
};