/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.cpp
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Implentation file of Vehicle.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"ReadWritable.h"
#include"Vehicle.h"
#include "Utils.h"

namespace sdds {
    void Vehicle::setEmpty() {
		make_model = nullptr;
		plate[0] = '\0';
		parking_spot = 0;
	}
	Vehicle::Vehicle() :ReadWritable(){
		setEmpty();
	}
	Vehicle::Vehicle(const char* plt, const char* mk_md):ReadWritable() {
		setEmpty();
		if (plt == nullptr || plt[0] == '\0' || strlen(plt)>MAX_PLATE ){
			setEmpty();
		}
		else {
			setPlate(plt);
			setMakeModel(mk_md);
			setParkingSpot(0);
		}
	}
	void Vehicle::setPlate(const char* plt) {
		strcpy(plate, plt);
	}
	Vehicle::~Vehicle() {
		delete[] make_model;
		make_model = nullptr;
	}
	bool Vehicle::isEmpty() const{
			bool empty = false;
			if (plate[0] == '\0' || make_model == nullptr){
				empty = true;
			}
			return empty;
		
	}
	const char* Vehicle::getLicensePlate() const {
		return plate;
	}
	const char* Vehicle::getMakeModel() const {
		return make_model;
	}

	void Vehicle::setMakeModel(const char* mk_md) {
		if (mk_md != nullptr && mk_md[0] != '\0' && strlen(mk_md) >= 2){
			int size = strlen(mk_md) + 1;
			delete[] make_model;
			make_model = new char[size];
			strcpy(make_model, mk_md);
		}
		else{
			delete[] make_model;
			setEmpty();
		}
	}

	int Vehicle::getParkingSpot()const {
		return parking_spot;
	}

	void Vehicle::setParkingSpot(int spot_No) {
		if (spot_No >= 0) {
			parking_spot = spot_No;
		}
		else {
			delete[] make_model;
			setEmpty();
		}
	}
	bool operator==(const Vehicle& vhcl, const char* plt) {
		bool check = false;
		if (!vhcl.isEmpty()) {
			if (plt[0] != '\0' && plt != nullptr && strlen(plt) <= MAX_PLATE) {
				if ((case_unsens(vhcl.plate, plt))) {
					check = true;
				}
			}
		}
		return check;
	 }
	bool operator==(const Vehicle& vhcl1, const Vehicle& vhcl2) {
		bool check = false;
		if (!vhcl1.isEmpty() && !vhcl2.isEmpty()) {
			if (case_unsens(vhcl1.plate, vhcl2.plate)) {
				check = true;
			}
		}
		return check;
	}
	std::istream& Vehicle::read(std::istream& is) {
		if (isCsv()) {
			is >> parking_spot;
			is.ignore();
			is.getline(plate, MAX_PLATE + 1, ',');
			to_Upper(plate);
			char m_m[60 + 1] = { '\0' };
			is.getline(m_m, 60 + 1, ',');
			setMakeModel(m_m);
		}
		else {
			cout << "Enter Licence Plate Number: ";
			int done;
			char temp[MAX_PLATE +2 ];

			do {
				done = 0;
				is.getline(temp, MAX_PLATE + 2);
				if ((strlen(temp) > MAX_PLATE ) || strlen(temp) ==0) {
					done = 1;
					cout << "Invalid Licence Plate, try again: ";
				}
				is.clear();

			} while (done);

			strncpy(plate, temp, MAX_PLATE +2 );
			to_Upper(plate);

			cout << "Enter Make and Model: ";
			char m_m2[60 + 1] = { '\0' };
			do {
				done = 0;
				is.getline(m_m2, 60 + 1);
				if (strlen(m_m2) < 2 || strlen(m_m2) > 60) {
					done = 1;
					cout << "Invalid Make and model, try again: ";
				}
			} while (done);
			setMakeModel(m_m2);
		}
		if (is.fail()) {
			setEmpty();
		}
		return is;
	}
	std::ostream& Vehicle::write(std::ostream& os) const {
		if (this->isEmpty()) {
			os << "Invalid Vehicle Object" << endl;
		}
		else {
			if (isCsv()) {
				os << parking_spot << "," << plate << "," << make_model << ",";
			}
			else {
			os << "Parking Spot Number: ";
			if (parking_spot > 0){
				os << parking_spot << endl;
			}
			else{
				os << "N/A" << endl;
			}
			os << "Licence Plate: " << plate << endl;
			os << "Make and Model: " << make_model << endl;
			}
			
		}
		return os;
	}



}



