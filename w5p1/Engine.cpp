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
#include "Engine.h"
using namespace std;
namespace sdds {

	Engine::Engine()
	{
		emptyState();
	}
	Engine::Engine(const char* type, double size)
	{
		strncpy(m_type, type, TYPE_MAX_SIZE + 1);
		m_size = size;
	}
	Engine::~Engine()
	{
		emptyState();
	}
	void Engine::emptyState() {
		m_size = -1.0;
		m_type[0] = '\0';
	}
	double Engine::get() const {
		return m_size;
	}

	void Engine::display() const {
		cout << fixed;
		cout.precision(1);
		if (floor(m_size)==m_size) {
			cout << fixed;
			cout.precision(0);
			cout << m_size << " liters" << " - " << m_type << endl;
		}
		else {
			cout << m_size << " liters" << " - " << m_type << endl;
		}
	}
}