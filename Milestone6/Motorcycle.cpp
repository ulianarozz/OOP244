/* Citation and Sources...
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Implentation file of Motorcycle.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Motorcycle.h"
#include"Utils.h"

namespace sdds {
	void Motorcycle::emptyState() {
		Vehicle::setEmpty();
		sidecar = false;
	}
	Motorcycle::Motorcycle() {
		emptyState();
	}
	Motorcycle::Motorcycle(const char* plt, const char* mk_md, bool side) :Vehicle(plt, mk_md) {
		setEmpty();
		if (plt == nullptr || plt[0] == '\0' || strlen(plt) > MAX_PLATE || mk_md == nullptr || mk_md[0] == '\0') {
			emptyState();
		}
		else {
			setPlate(plt);
			setMakeModel(mk_md);
			setParkingSpot(0);
			sidecar = side;
		}
	}
	std::istream& Motorcycle::read(std::istream& is) {

		if (isCsv()){
			Vehicle::read(is);
			int value;
			is >> value;
			if (value == 1){
				sidecar = true;
			}
			else{
				sidecar = false;
			}
			is.ignore();
		}
		else
		{
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(is);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			if (validAnswer()) {
				sidecar = true;
			}
			else {
				sidecar = false;
			}
			
		}

		return is;
	}
	std::ostream& Motorcycle::write(std::ostream& os) const {
		if (isEmpty()){
			os << "Invalid Motorcycle Object" << endl;
		}
		else{
			if (isCsv()){
				os << "M,";
				Vehicle::write(os);
				os << int(sidecar) << endl;
			}
			else{
				os << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(os);
				if (sidecar){
					os << "With Sidecar" << endl;
				}
			}
		}

		return os;
	}
	Motorcycle::~Motorcycle(){
	}
}