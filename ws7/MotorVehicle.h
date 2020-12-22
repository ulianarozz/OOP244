/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/13
 **********************************************************/
 // I finished this assignment by myself
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

namespace sdds {

	class MotorVehicle {
		char v_plate[32];
		char v_address[64];
		int v_year;
	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mtv) ;
	std::istream& operator>>(std::istream& in, MotorVehicle& mtv);

}

#endif