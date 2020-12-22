/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/02
 **********************************************************/

 //I have done all the coding by myself.
#include <iostream>
#include "Gift.h"

using namespace std;
namespace sdds {

	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC+1);
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
	void display(const Gift& theGift) {
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;
	}

	

}