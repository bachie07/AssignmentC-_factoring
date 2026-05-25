#include "CompositePatientLoader.h"

//constructor - add database loader first, then file loader
//database patients appear before file patients in the list
CompositePatientLoader::CompositePatientLoader() {

	_loaders.push_back(new PatientDatabaseLoader());
	_loaders.push_back(new PatientFileLoaderAdapter("../PatientSystem/patients.txt"));

}

//each methods loop through all loaders and call the same method on each

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

CompositePatientLoader::~CompositePatientLoader() {
	for (AbstractPatientDatabaseLoader* loader : _loaders) {
		delete loader;
	}
}