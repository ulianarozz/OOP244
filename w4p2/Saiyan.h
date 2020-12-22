/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/19
 **********************************************************/
 // I finished this assignment by myself and only copied the code that professor gave me
#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H
namespace sdds {
	const int MAX_NAME = 32;
	const int MAX_YEARS = 2020;
	class Saiyan {
		char *m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		~Saiyan();
		bool isSuper() const;
		void emptyState();
		bool isValid() const;
		void display() const;
		void powerup();
		void set(const char* name, int dob, int power,int level =0, bool super = false);
		bool fight(Saiyan& other);
		int getPower() const;
	};


}
#endif