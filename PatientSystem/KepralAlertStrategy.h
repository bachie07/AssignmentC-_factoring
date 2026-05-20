#pragma once

#include "AlertStrategy.h"

class KepralAlertStrategy : public AlertStrategy {

public:
	AlertLevel calculate(const Patient& patient, const Vitals& vitals) override;
};