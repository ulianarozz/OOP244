/* Citation and Sources...
Final Project Milestone 6
Module: Car
Filename: Car.h
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Definition of Car.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include<iostream>
#include"Vehicle.h"
#include"ReadWritable.h"
using namespace std;
namespace sdds {

	class Car : public Vehicle {
		bool carwash;
	public :
		Car();
		Car(const char* plt, const char* mk_md, bool wash);
		virtual ~Car();
		void emptyState();
		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
	};


 }
#endif