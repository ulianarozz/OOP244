/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/24
 **********************************************************/
 // I finished this assignment by myself

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include <cstring>
#include "Engine.h"
namespace sdds {
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;

	class Ship
	{
		Engine m_engines[10];
		char m_type[TYPE_MAX_SIZE+1];
		int m_engCnt;
	public:
		Ship();
		Ship(const char* type, Engine engines[], int numEngines);
		~Ship();
		void emptyState();
		void set(const char* type, Engine engines[], int numEngines);
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		double getPower() const;

	
	};
	bool operator<(double power, const Ship& theShip);
	

	
}
#endif