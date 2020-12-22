/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/24
 **********************************************************/
 // I finished this assignment by myself


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <math.h>
#include"Ship.h"
#include "Engine.h"

using namespace std;
namespace sdds {

	Ship::Ship()
	{
		emptyState();
	}


	Ship::Ship(const char* type, Engine engines[], int numEngines) {
		if (strlen(type) < TYPE_MAX_SIZE && numEngines > 0) {
			set(type, engines, numEngines);
		}
		else {
			emptyState();
		}

	}

	Ship::~Ship()
	{
	}


	void Ship::emptyState() {
		m_type[0] = '\0';
		m_engCnt = -1;
	}


	void Ship::set(const char* type, Engine engines[], int numEngines) {
		strcpy(m_type, type);
		m_engCnt = numEngines;
		for (int i = 0; i < m_engCnt; i++) {
			m_engines[i] = engines[i];
		}
	}




	Ship::operator bool() const {
		bool check = false;
		if (strlen(m_type) < TYPE_MAX_SIZE && m_engCnt > 0 && m_engCnt < 10) {
			check = true;
		}
		return check;
	}
	Ship& Ship::operator+=(Engine engine) {
		if (strlen(m_type) > TYPE_MAX_SIZE || m_engCnt < 0 || m_engCnt > 10) {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			if (m_engCnt < 10) {
				m_engines[m_engCnt] = engine;
				m_engCnt++;
			}
		}
		return *this;
	}

	bool Ship::operator<(double power) const {
		bool check = false;
		if (power > getPower()) {
			check = true;
		}
		return check;
	}

    double Ship::getPower() const  {
		double power=0;
		for (int i = 0; i < m_engCnt; i++) {
			power = power + (double)(m_engines[i].get() * 5);
		}
		return power;
	}

	bool operator<(double power, const Ship& theShip) {
		return (double)(power < theShip.getPower());
	}
	 
	 void Ship::display() const {
	
		 if (strlen(m_type) < TYPE_MAX_SIZE && m_engCnt > 0 && m_engCnt < 10) {
			 
			 cout << m_type << " - ";
			 if (floor(getPower()) == getPower()) {
				 cout << fixed;
				 cout.precision(0);
				 cout << getPower() << endl;
			 }
			 else {
				 cout << getPower() << endl;
			 }
			 for (int i = 0; i < m_engCnt; i++)
			 {
				 m_engines[i].display();

				 
			 }
			 cout << fixed;
			 cout.precision(3);
		 }
		 else {
			 cout << "No available data" << endl;
		 }
	 }
}