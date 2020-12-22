#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include"Employee.h"
#include "Engineer.h"

namespace sdds {
	Engineer::Engineer(int hourlySal, int lvl) : Employee(hourlySal,30) {
		level = lvl;
	
	}
	double Engineer::getSalary(int workedhours) {
		int salary = 0;
		salary =((workedhours * get_hourlySalary()) + (level * 40));
		if (workedhours < get_minimumWorkingHours()) {
			salary *= 0.8;
		}
		return salary;
	}

	ostream& Engineer::display() {
		cout  << "Engineer" << endl;
		cout << right << setw(20) << "Level: " << level << endl;
		cout << right << setw(20) << "Pay Rate: " << get_hourlySalary() << endl;
		cout << right << setw(20) << "Min Hours: " << get_minimumWorkingHours() << endl;
		return cout;
	}
}