/* Citation and Sources...
Final Project Milestone 6
Module: Utils
Filename: Utils.h
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Definition of Utils.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds
{
	char* to_Upper(char*);
	bool case_unsens(const char*, const char*);
	bool validAnswer();
	const unsigned int ReadBufferSize = 40;
	struct Utils {
		static void read(int& val, int min, int max, const char* errorMessage = "");
	};

}
#endif