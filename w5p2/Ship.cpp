/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/28
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


	Ship::Ship(const char* type, Engine* engines, int numEngines) {
		if (strlen(type) < TYPE_MAX_SIZE && numEngines > 0) {
			m_engines = nullptr;
			m_type = nullptr;
			m_engCnt = 0;
			set(type, engines, numEngines);
			
		}
		else {
			emptyState();
		}

	}



	void Ship::emptyState() {
		m_type = nullptr;
		m_engCnt = -1;
		m_engines = nullptr;
	}

	void Ship::set(const char* type, Engine* engines, int numEngines) {
		m_engCnt = numEngines;
		m_engines = new Engine[numEngines];
		for (int i = 0; i < m_engCnt; i++) {
			m_engines[i] = engines[i];
		}
		m_type = new char[strlen(type)+1];
		strcpy(m_type, type);
		
	}



	Ship::operator bool() const {
		bool check = false;
		if (m_engCnt > 0 && m_engCnt < 10) {
			check = true;
		}
		return check;
	}
	Ship& Ship::operator+=(Engine engine) {
		if (m_engCnt < 0 || m_engCnt > 10) {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			Engine* temp = new Engine[m_engCnt + 1];
			for (int i = 0; i < m_engCnt; i++) {
				temp[i] = m_engines[i];
			}
			temp[m_engCnt++] = engine;
			delete[] m_engines;
			m_engines = temp;
			
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

	
		 if ( m_engCnt > 0 && m_engCnt < 10) {
			 cout << fixed;
			 cout.precision(2);
			 if (getPower() > 100) {
				 cout << m_type << " - ";

				 cout << getPower() << endl;
			 }
			 else {
				 cout << m_type << " -  ";

				 cout << getPower() << endl;
			 }
				 cout << fixed;
				 cout.precision(2);
			 for (int i = 0; i < m_engCnt; i++)
			 {
				
				 m_engines[i].display();
			 }
			
		 }
		 else {
			 cout << "No available data" << endl;
		 }
	 }

	 Ship::~Ship()
	 {
		 if (m_type != nullptr)
		 {
			 delete[] m_type;
			 m_type = nullptr;
		 }
		 if (m_engines != nullptr)
		 {
			 for (int i = 0; i < m_engCnt + 1; i++)
			 {
				 delete[] m_engines;
				 m_engines = nullptr;
			 }
		 }
	 }
}

