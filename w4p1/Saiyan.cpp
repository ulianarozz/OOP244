/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/16
 **********************************************************/
 // I finished this assignment by myself
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include <cstring>
#include "Saiyan.h"
#include "Saiyan.h"
using namespace std;
namespace sdds {
 
	
	Saiyan::Saiyan(const char* name, int dob, int power)
	{     
		
			set(name, dob, power);
	   
	}
	Saiyan::Saiyan() {
		emptyState();
	}
	bool Saiyan::isValid() const {
		bool check = true;
		if (m_name[0]=='\0' || m_dob >MAX_YEARS || m_power<0) {
			check = false;;
		}
		return check;
	}
	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (name == nullptr || strlen(name) < 1 || dob > MAX_YEARS || power < 0) {
			m_name[0] = '\0';
			m_dob = 0;
			m_power = 0;
			m_super = super;
		}
		else {
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		
		}
	}

	void Saiyan::display() const {
		if (this->isValid()) {
			cout << this->m_name << endl;
			cout << "DOB: " << this->m_dob << endl;
			cout << "Power: " << this->m_power << endl;
			if (m_super == true) {
				cout << "Super: " << "yes" << endl;
			}
			else cout << "Super: " << "no" << endl;
		}
		else
			cout << "Invalid Saiyan!" << endl;
	}
	bool Saiyan::fight(const Saiyan& other) const {
		bool check = false;
		if (this->isValid() && other.isValid() && this->m_power > other.m_power) {
			check = true;
		}
		return check;
	}
	void Saiyan::emptyState() {
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}
}