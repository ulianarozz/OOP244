

#ifndef DOCTOR_H
#define DOCTOR_H

#include"Employee.h"
namespace sdds {
	class Doctor : public Employee{
		char doctorType[32];
		bool specialist;
	public:
		Doctor(const char*, int, int);
		Doctor(const char*, int, int,bool);
		virtual double getSalary(int workedHours);
		virtual ostream& display();
	};



}






#endif
