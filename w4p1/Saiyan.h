#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H
/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/16
 **********************************************************/
 // I finished this assignment by myself
namespace sdds {
	const int MAX_NAME = 32;
	const int MAX_YEARS = 2020;
	class Saiyan {
	    char m_name[MAX_NAME];
		int m_dob;
		int m_power;
		bool m_super;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		void emptyState();
		bool isValid() const;
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool fight(const Saiyan& other) const;
	};
	

}
#endif