
/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/07
 **********************************************************/
 //I have done all the coding by myself.
#ifndef SDDS_GIFT_H

#define SDDS_GIFT_H



namespace sdds {

	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;
	const int MAX_DESC = 15;

	struct Wrapping {
		char* m_pattern;
	};
	struct Gift {
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
		int m_wrapLayers;
		Wrapping *m_wrap;
	};

	

	
	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);
	bool wrap(Gift& theGift);
	void gifting(Gift& theGift);
	void wrapping(int& num);
	bool unwrap(Gift& theGift);
}

#endif
