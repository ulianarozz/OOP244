/* Citation and Sources...
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Implentation file of ReadWritable.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "ReadWritable.h"


using namespace std;
namespace sdds
{
	ReadWritable::ReadWritable() {
		flag = false;
	}
	bool ReadWritable::isCsv()const {
		return flag;
	}

	ReadWritable::~ReadWritable() {
	}

	void ReadWritable::setCsv(bool value) {
		flag = value;
	}

	std::ostream& operator<<(std::ostream& os, const ReadWritable& rw) {
		rw.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, ReadWritable& rw) {
		rw.read(is);
		return is;
	}

}