
/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/09
 **********************************************************/
#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H
namespace sdds {
	const int MAX_NAME = 30;
	
	class Train {
		char name[MAX_NAME+1];
		int id;
		Cargo* cargo;
	public:
		void initialize(const char* name_n, int id_n);
		void display() const;
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		

};
}
#endif