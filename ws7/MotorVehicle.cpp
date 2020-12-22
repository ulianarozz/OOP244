/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/13
 **********************************************************/
 // I finished this assignment by myself
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include"MotorVehicle.h"
#include"Truck.h"
using namespace std;
namespace sdds {

	MotorVehicle::MotorVehicle(const char* plate, int year) {
		v_year = year;
		strcpy(v_plate, plate);
		char temp[12] = "Factory";
		strcpy(v_address, temp);
	}
	void MotorVehicle::moveTo(const char* address) {
		if (address!= v_address) {
			char curAd[64];
			strcpy(curAd, v_address);
			strcpy(v_address, address);
			cout << "|" << right << setw(10) << v_plate << "| " << "|" << right << setw(20) << curAd << " --->--- " << left << setw(20) << v_address << "|" << endl;
		}
	}
	std::ostream& MotorVehicle::write(ostream& os) const{
		os << "| " << this->v_year << " | " << this->v_plate << " | " << this->v_address ;
		return os;
	}
	std::istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> this->v_year;
		//cout << endl;
		cout << "License plate: ";
		in >> this->v_plate;
		//cout << endl;
		cout << "Current location: ";
		in >> this->v_address;
		//cout << endl;
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mtv) {
		mtv.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, MotorVehicle& mtv) {
		mtv.read(in);
		return in;
	}
}