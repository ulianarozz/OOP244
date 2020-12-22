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

namespace sdds {
	Truck::Truck(const char* plate, int year, double capacity, const char* address) : MotorVehicle(plate, year) { //derived then based(keep names)
		t_cargo = 0;
	//	MotorVehicle::MotorVehicle(plate, year);
		this->t_capacity = capacity;
		moveTo(address);
	}
	bool Truck::addCargo(double cargo) {
		bool check = false;
		if (t_cargo < t_capacity) {
			t_cargo += cargo;
			check = true;
			if (t_cargo  > t_capacity) {
				t_cargo = t_capacity;	
			}
		}
		return check;
	}
	bool Truck::unloadCargo() {
    	bool check =false;
		if (t_cargo != 0) {
			t_cargo = 0;
			check = true;
		}
		return check;
	}
	std::ostream& Truck::write(std::ostream& os)const {
		MotorVehicle::write(os); // outpur from moto 
		os << " | " << this->t_cargo << "/" << this->t_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		std::cout << "Capacity: ";
		in >> t_capacity;
		std::cout << "Cargo: ";
		in >> t_cargo;
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Truck& trck) {
		trck.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Truck& trck) {
		trck.read(in);
		return in;
	}
}