#pragma once

#include "AlertStrategy.h"

class AndromedaAlertStrategy : public AlertStrategy {

public:
	AlertLevel calculate(const Patient& patient, const Vitals& vitals) override;
};