
/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/21
 **********************************************************/
 // I finished this assignment by myself

#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include <iostream>
#include<cstring>
namespace sdds {
	int Employee::get_minimumWorkingHours() const
	{
		return minimumWorkingHours;
	}
	int Employee::get_hourlySalary() const
	{
		return hourlySalary;
	}
	Employee::Employee(int hourlysalary, int minimumworkingHours) : minimumWorkingHours(minimumworkingHours)
	{
		hourlySalary = hourlysalary;
			
	}


	double Employee::getSalary(int workedHours)
	{
		return ((int)workedHours * get_hourlySalary());
	}

	ostream& Employee::display()
	{
		return cout;
	}

	Employee::~Employee() {};
}