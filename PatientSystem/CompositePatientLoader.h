#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientDatabaseLoader.h"
#include "PatientFileLoaderAdapter.h"
#include <vector>

//Composite loader - implement composite pattern
//contain multiple loaders and runs them all when loadpatients() is called
//allow system to load from both database and file simultaneously
//Switching between loaders is a one line change in PatientManagementSystem


class CompositePatientLoader : public AbstractPatientDatabaseLoader {

public:
	CompositePatientLoader();
	void initialiseConnection() override;

	void loadPatients(std::vector<Patient*>& patientIn) override;

	void closeConnection() override;

	~CompositePatientLoader();

private:

	//hold all loaders - database first, then file
	std::vector<AbstractPatientDatabaseLoader*> _loaders;

};