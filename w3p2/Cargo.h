
/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/13
 **********************************************************/
 // I finished this assignment by myself
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
	const int MAX_DESC = 20;

	const double MAX_WEIGHT = 777.555;
	const double MIN_WEIGHT = 44.2222;

	class Cargo {
		char name[MAX_DESC+1];
		double weight;
	public :
		void initialize(const char* desc, double weight);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char* description);
		void setWeight(double weight);

	};
}
#endif