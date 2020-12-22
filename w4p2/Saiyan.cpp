/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/19
 **********************************************************/
 // I finished this assignment by myself and only copied the code that professor gave me
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
		if (name == nullptr || name[0] == '\0' || dob > 2020 || power < 1) {
			emptyState();
		}
		else
		{

			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = false;
			m_level = 0;
		}
	}
	Saiyan::Saiyan() {
		m_name = nullptr;
		m_dob = -1;
		m_power = 0;
		m_super = false;
		m_level = -1;
	}
	bool Saiyan::isSuper() const {
		bool check = false;
		if (m_super== true) {
			check = true;
		}
		return check;
	}
	bool Saiyan::isValid() const {
		return (m_name != nullptr && m_dob > 0 && m_power > 0);
	}
	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

		if (name == nullptr || name[0] == '\0' || dob > 2020 || power < 1) {
			emptyState();
		}
		else
		{
			if (isValid())
			{
				delete[] m_name;
				m_name = nullptr;
			}
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
	}

	void Saiyan::display() const {
		if (!isValid())
		{
			cout << "Invalid Saiyan!" << endl;

		}
		else if (!isSuper())
		{
			cout << m_name << endl;
			cout.width(10);
			cout << "DOB: " << m_dob << endl;
			cout.width(10);
			cout << "Power: " << getPower() << endl;
			cout.width(10);
			cout << "Super: " << "no" << endl;
		}
		else
		{
			cout << m_name << endl;
			cout.width(10);
			cout << "DOB: " << m_dob << endl;
			cout.width(10);
			cout << "Power: " << getPower() << endl;
			cout.width(10);
			cout << "Super: " << "yes" << endl;
			cout.width(10);
			cout << "Level: " << m_level << endl;
		}

	}
	
	bool Saiyan::fight(Saiyan& other) {
		bool check = false;
		if (isValid()&& other.isValid()) {
			
			if (isSuper()) {
				powerup();
			}
			if (other.isSuper()) {
				other.powerup();
			}
			this->getPower() > other.getPower() ? check = true : check;
			
		}
		return check;
	}
	void Saiyan::emptyState() {
		m_name = nullptr;
		m_dob = -1;
		m_power = 0;
		m_super = false;
		m_level = -1;
	}
	int Saiyan::getPower() const {
		return m_power;
	}
	void Saiyan::powerup() {
		if (isSuper()) {
			m_power = m_power + (int)(m_power * m_level/10 );
		}
	}
	Saiyan::~Saiyan() {
		delete[] m_name;
		m_name = nullptr;
	}
	

}

