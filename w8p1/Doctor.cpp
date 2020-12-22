
/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/21
 **********************************************************/
 // I finished this assignment by myself
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include<cstring>
#include"Doctor.h"
#include"Employee.h"

namespace sdds {
	Doctor::Doctor(const char* type, int HourlySalary, int minHours) : Employee(HourlySalary,minHours) {
		strcpy(doctorType,type);
		Employee::get_hourlySalary();
		//Employee::get_minimumWorkingHours();
		specialist = false;
	}
	Doctor::Doctor(const char* type, int HourlySalary, int minHours,bool spec) : Employee(HourlySalary, minHours) {
		strcpy(doctorType, type);
		//Employee::get_hourlySalary();
		//Employee::get_minimumWorkingHours();
		specialist = spec;
	}
	double Doctor::getSalary(int WorkedHours) {
		int salary = 0;
		if (WorkedHours <= Employee::get_minimumWorkingHours()) {
			salary = (int)(WorkedHours * Employee::get_hourlySalary());
			if (specialist == true) {
				salary += 2000;
			}
		}
		else if (WorkedHours > Employee::get_minimumWorkingHours()) {
			int temp = 0;
			int temp2 = 0;
			int extraH = 0;
			int hrs= 0;
			int slr = 0;
			slr = Employee::get_hourlySalary();
			hrs = Employee::get_minimumWorkingHours();
			extraH = WorkedHours - hrs;
			temp = (hrs * slr);
			temp2 = extraH *slr * 1.5;
			salary = temp + temp2;
			if (specialist == true) {
				salary += 2000;
			}
		}
		return salary;
	}

	ostream& Doctor::display() {
		if (this->specialist == true) {
			cout << "Doctor" << endl;
			cout << right << setw(16) << "Type: " << doctorType << " (specialist)" << endl;
			cout << right << setw(16) << "Pay Rate: " << get_hourlySalary() << endl;
			cout << right << setw(16) << "Min Hours: " << get_minimumWorkingHours() << endl;
		}
		else {
			cout << "Doctor" << endl;
			cout << right << setw(16) << "Type: " << doctorType << endl;
			cout << right << setw(16) << "Pay Rate: " << get_hourlySalary() << endl;
			cout << right << setw(16) << "Min Hours: " << get_minimumWorkingHours() << endl;
		}
		return cout;
	}



}