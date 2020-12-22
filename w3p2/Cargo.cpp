

/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/13
 **********************************************************/
 // I finished this assignment by myself
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Cargo.h"
#include"Train.h"


namespace sdds {

	void Cargo::initialize(const char* desc, double weight) {
		setDesc(desc);
		setWeight(weight);
	}
	const char* Cargo::getDesc() const {
		return name;
	}
	double Cargo::getWeight() const {
		return weight;
	}
	void Cargo::setDesc(const char* description) {
		strncpy(this->name, description, MAX_DESC + 1);
	}
	void Cargo::setWeight(double weight) {
		if (weight< MIN_WEIGHT || weight>MAX_WEIGHT) {
			this->weight = MIN_WEIGHT;
		}
		else {
			this->weight = weight;
		}
	}




}