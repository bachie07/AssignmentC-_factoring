#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

//adapter class - implement adapter pattern
//wrap patientfileloader to match abstractpatientdatabaseloader interface
//allow sste to load from a file using the same interface as the database
//PatientFileLoader interface is unchanged

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader {

public:

	PatientFileLoaderAdapter(const std::string& filename);

	void initialiseConnection() override;

	void loadPatients(std::vector<Patient*>& patientIn) override;

	void closeConnection() override;

private:
	//adaptee - class being wrapped
	PatientFileLoader _fileLoader;

	//the file path to load from
	std::string _filename;

};
