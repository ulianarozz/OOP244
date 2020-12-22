/* Citation and Sources...
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Definition of Motocycle.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Motorcycle : public Vehicle {
		bool sidecar;
	public:
		Motorcycle();
		void emptyState();
		virtual ~Motorcycle();
		Motorcycle(const char* plt, const char* mk_md, bool side);
		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
 };

}







#endif
