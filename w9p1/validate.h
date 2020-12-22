/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/27
 **********************************************************/
 //I have done all the coding by myself.

#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H

namespace sict {
	template <typename Type>
	bool validate(const Type& min, const Type test[], const int& element_num, bool results[]) {
		bool res = true;

		for (int i = 0; i < element_num; i++) {
			if (test[i] >= min) {
				results[i] = true;
			}
			else {
				results[i] = false;
				res = false;
			}
		}
		return res;
	}

}
#endif