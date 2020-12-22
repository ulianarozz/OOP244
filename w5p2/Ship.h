/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/28
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
		Engine* m_engines;
		char* m_type;
		int m_engCnt;
		void emptyState();
		void set(const char* type, Engine* engines, int numEngines);
	public:
		Ship();
		Ship(const char* type, Engine* engines, int numEngines);
		~Ship();
		
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		double getPower() const;
		
	
	};
	bool operator<(double power, const Ship& theShip);
	

	
}
#endif