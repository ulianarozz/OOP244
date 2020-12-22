/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/09
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Cargo.h"
#include "Train.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if (!(Train::isValid())) {
			cout << "This is an invalid train." << endl;
		}
		else if (isValid()){
			cout << "Name: " << Train::name << endl;
			cout << "ID: " << Train::id << endl;
			if (cargo!=nullptr) {
				cout << "Cargo: " << Train::cargo->name << endl;
				cout << "Weight: " << Train::cargo->weight << endl;
				
			}else cout << "No cargo on this train." << endl;
		}
	
			
		
			
	}
	bool Train::isValid() const {
		bool check = true;
		if (id <=0 || name == nullptr || name[0] =='\0') {
			check = false;
		}
		return check;
	}
	void Train::initialize(const char* name_n, int id_n) {
		if (name_n==nullptr || name_n[0] =='\0' || id_n <0) {
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
		delete cargo;
		cargo = nullptr;
		cargo = new Cargo;
		strcpy(cargo->name, car.name);
		cargo->weight = car.weight;
	}
	void Train::unloadCargo() {
		if (cargo!=nullptr) {
			delete cargo;
			cargo = nullptr;
			
	}
	}
}