
/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/21
 **********************************************************/
 // I finished this assignment by myself
#ifndef Employee_H
#define Employee_H

#include <iostream>
#include <stdio.h>

using namespace std;
namespace sdds {
	class Employee
	{
	private:
		const int minimumWorkingHours;
		int hourlySalary;

	protected:
		int get_minimumWorkingHours() const;
		int get_hourlySalary() const;

	public:
		Employee(int, int);
		void set_Values(int, int);
		virtual double getSalary(int)=0;
		virtual ostream& display()=0;
		virtual ~Employee();
	};
}
#endif