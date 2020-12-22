/* Citation and Sources...
Final Project Milestone 6
Module: Car
Filename: Car.cpp
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Implentation file of Car.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include<iostream>
#include<cstring>
#include"Car.h"
#include"Utils.h"
namespace sdds {
	Car::Car() {
		emptyState();
	}
	Car::Car(const char* plt, const char* mk_md,bool wash) :Vehicle( plt, mk_md) {
		setEmpty();
		if (plt == nullptr || plt[0] == '\0' || strlen(plt) > MAX_PLATE||mk_md==nullptr || mk_md[0]=='\0') {
			emptyState();
			carwash = false;
		}
		else {
			setPlate(plt);
			setMakeModel(mk_md);
			setParkingSpot(0);
			carwash = wash;
		}
	}
	void Car::emptyState() {
		Vehicle::setEmpty();
		carwash = false;
	}

	
	std::istream& Car::read(std::istream& is) {
		if (isCsv()) {
			Vehicle::read(is);
			int value;
			is >> value;
			if (value == 0) {
				carwash = false;
			}
			else {
				carwash = true;
			}
			is.ignore();
		}
		else {
			cout << "\nCar information entry" << endl;
			Vehicle::read(is);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			if (validAnswer()) {
				carwash = true;
			}
			else {
				carwash = false;
			}

		}
		return is;
	}
	std::ostream& Car::write(std::ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Car Object" << endl;
		}
		else {
			if (isCsv()){
				os << "C,";
				Vehicle::write(os);
				os << int(carwash) << endl;
			}
			else {
				os << "Vehicle type: Car" << endl;
				Vehicle::write(os);
				if (carwash == true) {
					os<<"With Carwash" << endl;
				}
				else {
					os << "Without Carwash" << endl;
				}
			}
		}
		return os;
	}



	Car::~Car(){

	}

}