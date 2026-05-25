#pragma once
#include "AlertStrategy.h"

// strategy for Cordyceps brain infection
class CordycepsAlertStrategy : public AlertStrategy {

	// implement alert level calculation based on respiratory rate
public:
	AlertLevel calculate(const Patient& patient, const Vitals& vitals) override;
};