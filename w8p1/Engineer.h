#ifndef ENGINEER_H
#define ENGINEER_H

#include"Employee.h"

namespace sdds {
	class Engineer : public Employee {
		int level;
	public:
		Engineer(int, int);
	virtual	double getSalary(int);
		virtual ostream& display();
	};
}

#endif