/* Citation and Sources...
Final Project Milestone 6
Module: Utils
Filename: Utils.cpp
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Implentation file of Utils.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<iostream>
#include <cctype>
#include "Utils.h"
using namespace std;
namespace sdds {
	char* to_Upper(char* plt) {
		int i;
		for (i = 0; plt[i]!='\0'; i++) {
			plt[i] = toupper(plt[i]);
		}
		return plt;
	}

	bool case_unsens(const char* str1, const char* str2) {
		bool same = false;
		if (strlen(str1) == strlen(str2)) {
			char* st1 = new char[strlen(str1) + 1];
			strcpy(st1, str1);
			to_Upper(st1);
			char* st2 = new char[strlen(str2) + 1];
			strcpy(st2, str2);
			to_Upper(st2);
			if (strcmp(st1, st2) == 0)
			{
				same = true;
			}
			delete[] st1;
			st1 = nullptr;
			delete[] st2;
			st2 = nullptr;
		}

		return same;
	}

	bool validAnswer() {
		char answer = 'n', check = '\0';
		bool ans = false;
		cin >> answer;
		if (answer!= '\n') {
			check = getchar();
		}

		if (check != '\n' && check != '\0') {
			while (getchar() != '\n');
		}
		while (check != '\n' || (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')) {
			cout << ("Invalid response, only (Y)es or (N)o are acceptable, retry: ");
			cin >> answer;
			if (answer != '\n') {
				check = getchar();
			}
			if (check != '\n' && check != '\0') {
				while (getchar() != '\n');
			}
		}

		if (answer == 'Y' || answer == 'y') {
			ans = true;
		}
		else {
			ans = false;
		}
		return ans;
	}

	void Utils::read(int& val, int min, int max, const char* errorMess) {
		bool ok;
		char newLine;
		const char* orgMes = errorMess;
		const char invalidInt[] = "Invalid Integer, try again: ";
		do {
			cin >> val;
			newLine = cin.get();
			if (cin.fail() && newLine != '\0') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
				errorMess = invalidInt;
			}
			else {
				ok = val <= max && val >= min;
				errorMess = orgMes;
			}


		} while (!ok && cout << errorMess);
	}


}