#include "Patient.h"

#include <iomanip>
#include <iostream>
#include <sstream>

#include "Vitals.h"


using namespace std;

const std::string Diagnosis::CORDYCEPS_BRAIN_INFECTION = "Cordyceps Brain Infection";
const std::string Diagnosis::KEPRALS_SYNDROME = "Kepral’s Syndrome";
const std::string Diagnosis::ANDROMEDA_STRAIN= "Andromeda Strain";


Patient::Patient(const std::string& firstName, const std::string& lastName, std::tm birthday) :
	Person(firstName, lastName, birthday),
	_alertLevel(AlertLevel::Green),
	_alertStrategy(nullptr)
{
}

int Patient::age() const
{	
	// an inaccurate age estimate but fine for assignment purposes
	return 2022 - (1900 + _birthday.tm_year);
}

std::string Patient::uid() const
{
	std::stringstream ss;
	ss << (char)std::tolower(_lastName.at(0)) 
	   << (char)std::tolower(_firstName.at(0))
	   << std::setfill('0') << std::setw(2) << (_birthday.tm_mon + 1) 
	   << _birthday.tm_year;
	return ss.str();
}

std::string Patient::humanReadableID() const
{
	return "" + _lastName + ", " + _firstName + " (" + uid() + ")";
}

std::ostream& operator<<(std::ostream& os, const Patient& p)
{
	os << p.uid() << "|" << p._lastName << "," << p._firstName << "|" << std::put_time(&p._birthday, "%d-%m-%Y") << "|" << p.primaryDiagnosis();
	
	os << "|";
	for (int i = 0; i < p.vitals().size(); ++i) {
		auto v = p.vitals()[i];
		os << *v;
		if (i != p.vitals().size() - 1) {
			os << ";";
		}
	}
	return os;
}

void Patient::addDiagnosis(const std::string& diagnosis)
{
	_diagnosis.push_back(diagnosis);
}

const std::string& Patient::primaryDiagnosis() const
{
	return _diagnosis.front();
}


//record a new vital reading for the patient
void Patient::addVitals(const Vitals* v)
{
	_vitals.push_back(v);

	//if strategy assigned, calculate alert level immediately
	if (_alertStrategy) {

		AlertLevel level = _alertStrategy->calculate(*this, *v);

		setAlertLevel(level);

	}


}

const std::vector<const Vitals*> Patient::vitals() const
{
	return _vitals;
}

// update alert level and notifies observer if red
void Patient::setAlertLevel(AlertLevel level)
{
	_alertLevel = level;

	if (_alertLevel > AlertLevel::Green) {
		cout << "Patient: " << humanReadableID() << "has an alert level: ";
		switch (_alertLevel) {
		case AlertLevel::Yellow:
			cout << "Yellow";
			break;
		case AlertLevel::Orange:
			cout << "Orange";
			break;
		case AlertLevel::Red:
			cout << "Red";
			notifyObservers();
			break;
		}
		cout << endl;
	}
}

void Patient::setAlertStrategy(AlertStrategy* strategy) {
	_alertStrategy = strategy;
}

// add an observer to the notification list
void Patient::addObserver(IObserver* observer) {
	_observers.push_back(observer);
}


//loops throug all observers and notifies each one
void Patient::notifyObservers() {
	for (IObserver* observer : _observers) {
		observer->onAlertLevelChanged(this);;
	}
}