/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/13
 **********************************************************/
 // I finished this assignment by myself
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include"MotorVehicle.h"

namespace sdds {
	class Truck : public MotorVehicle {
		double t_capacity;
		double t_cargo;
	public:
		Truck(const char* plate, int year, double capacity, const char* address);
		using MotorVehicle::MotorVehicle;
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& trck);
	std::istream& operator>>(std::istream& in, Truck& trck);

}
#endif