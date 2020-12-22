/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/02
 **********************************************************/
 //I have done all the coding by myself.
#ifndef SDDS_GIFT_H

#define SDDS_GIFT_H



namespace sdds {
 
	const char MAX_DESC = 15;
	const double MAX_PRICE = 999.999;

	struct Gift {
	char m_description[MAX_DESC+1];
	double m_price;
	int m_units;
	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);

}

#endif
#pragma once