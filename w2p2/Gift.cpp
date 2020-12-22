/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/07
 **********************************************************/

 //I have done all the coding by myself.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "Gift.h"
#include "Gift.h"

using namespace std;
namespace sdds {
	
	bool unwrap(Gift& theGift) {
		bool status = false;
		if (theGift.m_wrap !=nullptr ) {
			cout << "Gift being unwrapped." << endl;

			for (int i = 0; i < theGift.m_wrapLayers; i++) {

				delete[] theGift.m_wrap[i].m_pattern;

				theGift.m_wrap[i].m_pattern = nullptr;
			}
				delete[] theGift.m_wrap;
				theGift.m_wrap = nullptr;
				
				
			
		    status = true;
			
		}
		else {
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
		}
		
		return status;
	}



	bool wrap(Gift& theGift) {
		int i;
		bool status = false;
		if (theGift.m_wrapLayers > 0) {
			cout << "Gift is already wrapped!" << endl;
			return status;
		}
		else {
			wrapping(theGift.m_wrapLayers);
			theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
			
			for (i = 0; i < theGift.m_wrapLayers; i++) {

				char* strT = new char[MAX_WRAP + 1];

				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin.width(MAX_WRAP + 1);
				cin >> strT;
				theGift.m_wrap[i].m_pattern = new char[strlen(strT) +1];
				strcpy(theGift.m_wrap[i].m_pattern, strT);
				delete[] strT;
				strT = nullptr;
			}
			status = true;
		}
		return status;
	}
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}
	void gifting(double& price) {
		do {
			cout << "Enter gift price: ";
			cin >> price;
		} while ((price <0 || price>MAX_PRICE) && cout << "Gift price must be between 0 and 999.999" << endl);
	}
	void gifting(int& units) {
		do {
			cout << "Enter gift units: ";
			cin >> units;
		} while ((units <= 0) && cout << "Gift units must be at least 1" << endl);
	}


	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);
	
	}
	void display(const Gift& theGift) {
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;
		if (theGift.m_wrap ==nullptr) {
			cout << "Unwrapped!" << endl;
		}
		else {
			for (int i = 0; i < theGift.m_wrapLayers; i++) {
				cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
				cout << "Wrap #" << i + 1<<" " << "-> "<<theGift.m_wrap->m_pattern << endl;
			}
		}
		
	}
	void wrapping(int& num) {
		cout << "Wrapping gifts..." << endl;
		do {
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin.width(MAX_WRAP + 1);
			cin >> num;
		} while ((num <= 0) && cout << "Layers at minimum must be 1, try again." << endl);
}
}