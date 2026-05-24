#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader {

public:

	PatientFileLoaderAdapter(const std::string& filename);

	void initialiseConnection() override;

	void loadPatients(std::vector<Patient*>& patientIn) override;

	void closeConnection() override;

private:
	PatientFileLoader _fileLoader;
	std::string _filename;

};
