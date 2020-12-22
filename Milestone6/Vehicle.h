/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Definition of Vehicle.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_

#include <iostream>
#include <stdio.h>
#include"ReadWritable.h"
const char MAX_PLATE = 8;
using namespace std;
namespace sdds {
	class Vehicle : public ReadWritable {
		char plate[MAX_PLATE +1 ];
		char* make_model;
		int parking_spot;
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char*);
	public:
		Vehicle();
		Vehicle(const char* plt,const char* mk);
		~Vehicle();
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		int getParkingSpot() const;
		void setParkingSpot(int spot_No);
		void setPlate(const char*);
		friend bool operator==(const Vehicle&, const char*);
		friend bool operator==(const Vehicle&, const Vehicle&);
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
	};


}


#endif