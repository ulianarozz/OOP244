


/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/13
 **********************************************************/
 // I finished this assignment by myself
#define _CRT_SECURE_NO_WARNINGS
#include "Cargo.h"
#include "Train.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
namespace sdds {
	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if (!(Train::isValid())) {
			cout << "This is an invalid train." << endl;
		}
		else if (isValid()) {
			cout << "    Name: " << Train::name << endl;
			cout.width(10);
			cout << "      ID: " << Train::id << endl;
			cout.width(10);
			if (cargo != nullptr) {
				cout << "   Cargo: " << this->cargo->getDesc()<< endl;
				cout.width(10);
				ios cout_state(nullptr);
				cout_state.copyfmt(cout);
				cout << "  Weight: ";
				cout << fixed;
				cout.precision(2);
				cout<< this->cargo->getWeight()<< endl;
				cout.copyfmt(cout_state);

			}
			else cout << "No cargo on this train." << endl;
		}




	}
	bool Train::isValid() const {
		bool check = true;
		if (id <= 0 || name == nullptr || name[0] == '\0') {
			check = false;
		}
		return check;
	}
	void Train::initialize(const char* name_n, int id_n) {
		if (name_n == nullptr || name_n[0] == '\0' || id_n < 0) {
			name[0] = '\0';
			id = 0;

		}
		else {
			strcpy(name, name_n);
			id = id_n;

		}
		cargo = nullptr;
	}
	void Train::loadCargo(Cargo car) {
		if (this->cargo == nullptr) {
			delete cargo;
			cargo = nullptr;
		}
		delete cargo;
		cargo = nullptr;
		cargo = new Cargo;
		this->cargo->setDesc(car.getDesc());
		this->cargo->setWeight(car.getWeight());
	}
	void Train::unloadCargo() {
		if (this->cargo != nullptr) {
			delete this->cargo;
			this->cargo = nullptr;

		}
	}

	bool Train::swapCargo(Train& other) {
		bool check = false;
		if (isValid() && other.isValid() && this->cargo != nullptr && other.cargo != nullptr) {
			swap(this->cargo, other.cargo);
			check = true;
		}
		return check;
	}
	bool Train::increaseCargo(double weight) {
		bool check = false;
		double n_weight = 0;
		if (isValid() && this->cargo != nullptr && cargo->getWeight()<MAX_WEIGHT) {
			n_weight = this->cargo->getWeight() + weight;
			if (n_weight > MAX_WEIGHT) {
			    n_weight = MAX_WEIGHT;
			}
			this->cargo->setWeight(n_weight);
			check = true;
			
		}
		return check;
	}

	bool Train::decreaseCargo(double weight) {
		bool check = false;
		double n_weight = 0;
		if (isValid() && this->cargo != nullptr && cargo->getWeight() > MIN_WEIGHT) {
			n_weight = this->cargo->getWeight() - weight;
			if (n_weight < MIN_WEIGHT) {
				n_weight = MIN_WEIGHT;
			}
			this->cargo->setWeight(n_weight);
			check =true;
	    }
		return check;
	}


}