#include "CompositePatientLoader.h"

CompositePatientLoader::CompositePatientLoader() {

	_loaders.push_back(new PatientDatabaseLoader());
	_loaders.push_back(new PatientFileLoaderAdapter(".. / PatientSystem / patients.txt"));

}

void CompositePatientLoader::initialiseConnection(){

	for (AbstractPatientDatabaseLoader* loader : _loaders) {
		loader->initialiseConnection();
	}

}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientIn) {
	for (AbstractPatientDatabaseLoader* loader : _loaders) {
		loader->loadPatients(patientIn);
	}
}

void CompositePatientLoader::closeConnection() {
	for (AbstractPatientDatabaseLoader* loader : _loaders) {
		loader->closeConnection();
	}
}