#include "PatientFileLoaderAdapter.h"


PatientFileLoaderAdapter::PatientFileLoaderAdapter(const std::string& filename) : _filename(filename)
{

}


void PatientFileLoaderAdapter::initialiseConnection()
{
}


//delegate to PatientFileLoader and copies results into vector
void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientsIn) {

	std::vector<Patient*> loaded = _fileLoader.loadPatientFile(_filename);

	for (Patient* p : loaded) {

		patientsIn.push_back(p);
	}
}

void PatientFileLoaderAdapter::closeConnection() {

}

