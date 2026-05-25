#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientDatabaseLoader.h"
#include "PatientFileLoaderAdapter.h"
#include <vector>

class CompositePatientLoader : public AbstractPatientDatabaseLoader {

public:
	CompositePatientLoader();
	void initialiseConnection() override;

	void loadPatients(std::vector<Patient*>& patientIn) override;

	void closeConnection() override;

private:
	std::vector<AbstractPatientDatabaseLoader*> _loaders;

};