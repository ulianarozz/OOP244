/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Implentation file of Parking.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include <fstream>
#include "Menu.h"
#include"Vehicle.h"
#include"Car.h"
#include"Motorcycle.h"
#include"ReadWritable.h"
#include"Parking.h"
#include"Utils.h"

using namespace std;

namespace sdds {
	bool Parking::isEmpty()const {
		bool check = false;
		if (fileName == nullptr) {
			check = true;
		}
		else {
			check = false;
		}
		return check;
	}


	Parking::Parking(const char* name, int noOfSpots) {
		empty();
		setName(name);
		if (noOfSpots >= 10 && noOfSpots < MAX_PARKING_SPOTS) {
			numSpots = noOfSpots;

		}
		else {
			numSpots = 0;
		}
		if (loadData()) {
			parkMenu = Menu("Parking Menu, select an action:", 0);
			parkMenu.add("Park Vehicle");
			parkMenu.add("Return Vehicle");
			parkMenu.add("List Parked Vehicles");
			parkMenu.add("Close Parking (End of day)");
			parkMenu.add("Exit Program");
			vehicleSelection = Menu("Select type of the vehicle:", 1);
			vehicleSelection.add("Car");
			vehicleSelection.add("Motorcycle");
			vehicleSelection.add("Cancel");
		}
		else {


			cout << "Error in data file" << endl;
			this->empty();
		}
	}



	void Parking::setName(const char* name) {
		if (name != nullptr && name[0] != '\0') {
			int size = strlen(name) + 1;
			fileName = new char[size];
			strcpy(fileName, name);
		}
		else {
			fileName = nullptr;
		}
	}
	void Parking::empty() {
		setName(nullptr);
		numOfParkedVehicles = 0;
		numSpots = 0;
		for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
			parkingSpots[i] = nullptr;
		}
	}



	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		//setSpots(count);
		int count = 0;
		for (int i = 0; i < numSpots; i++) {
			if (parkingSpots[i] == nullptr) {
				count++;
			}
		}
		cout.width(4);
		cout.setf(ios::left);
		cout << count << " *****" << endl;
		cout.unsetf(ios::left);
	}


	void Parking::parkVehicle() {
		int count = 0;
		for (int i = 0; i < numSpots; i++) {
			if (parkingSpots[i] == nullptr) {
				count++;
			}
		}
		if (count==0) {
			cout << "Parking is full" << endl;
		}

		else {
			int selection = vehicleSelection.run();
			if (selection == 3) {
				cout << "Parking cancelled" << endl;
			}
			else {
				Vehicle* new_v = nullptr;
				if (selection == 1) {
					new_v = new Car;
				}
				else if (selection == 2) {
					new_v = new Motorcycle;
				}
				new_v->setCsv(false);
				new_v->read();
				bool nostop = true;
				if (nostop && numOfParkedVehicles <= numSpots) {
					for (int i = 0; i <= numSpots && nostop; i++) {
						if (parkingSpots[i] == nullptr) {
							parkingSpots[i] = new_v;
							parkingSpots[i]->setParkingSpot(i + 1);
							cout << "\nParking Ticket" << endl;
							parkingSpots[i]->write();
							cout << endl;
							numOfParkedVehicles++;
							nostop = false;

						}

					}

				}

			}

		}

	}


	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;
		char plate[MAX_PLATE + 1] = { '\0' };
		bool invalid;
		cout << "Enter Licence Plate Number: ";
		do {
			invalid = false;
			cin >> plate;
			cin.ignore();
			if (strlen(plate) < 1 || strlen(plate) > 8) {
				cout << "Invalid Licence Plate, try again: ";
				invalid = true;
			}
		} while (invalid);
		to_Upper(plate);

		bool stop = true;
		for (int i = 0; i <= numSpots&& stop; i++) {
			if (stop&& parkingSpots[i] != nullptr && *parkingSpots[i] == plate) {
				cout << "\nReturning: " << endl;
				parkingSpots[i]->setCsv(false);
				parkingSpots[i]->write();
cout << endl;
				delete parkingSpots[i];
				parkingSpots[i] = nullptr;
				numOfParkedVehicles--;
				stop = false;
			}
		}
		if (stop) {
			cout << "\nLicense plate " << plate << " Not found\n" << endl;
		}
	}


	void Parking::listParkedVehicles()const {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				parkingSpots[i]->setCsv(false);
				parkingSpots[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
	}



	bool Parking::closeParking() {
		bool closed = false;
		if (numOfParkedVehicles == 0) {
			cout << "Closing Parking" << endl;
			closed = true;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			if (validAnswer()) {
				cout << "Closing Parking" << endl;
				for (int i = 0; i < numSpots; i++) {
					if (parkingSpots[i] != nullptr) {
						cout << endl << "Towing request" << endl;
						cout << "*********************" << endl;
						parkingSpots[i]->write();
						delete parkingSpots[i];
						parkingSpots[i] = nullptr;
						numOfParkedVehicles--;	
					}
				}
				
				closed = true;
			}
			else {
				cout << "Aborted!" << endl;
				closed = false;
			}
		}

		return closed;
	}


	bool Parking::exitParkingApp() {
		bool exit = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		if (validAnswer()) {
			cout << "Exiting program!" << endl;
			exit = true;
		}
		return exit;
	}



	bool Parking::loadData() {
		bool state = true;
		ifstream file;
		if (!isEmpty()) {
			file.open(fileName);
		}
		char vehicle_type;
		numOfParkedVehicles = 0;
		Vehicle* new_v;
		while (numOfParkedVehicles < numSpots && state && file) {
			vehicle_type = 'k';
			new_v = nullptr;
			file >> vehicle_type;
			file.ignore();
			if (vehicle_type == 'C') {
				new_v = new Car;
			}
			else if (vehicle_type == 'M') {
				new_v = new Motorcycle;
			}

			if (new_v) {
				new_v->setCsv(true);
				file >> *new_v;
				if (file) {
					parkingSpots[new_v->getParkingSpot() - 1] = new_v;
					numOfParkedVehicles++;
				}
				else {
					delete new_v;
					new_v = nullptr;
					state = false;
				}
			}
		}
		return state;
	}

	void Parking::saveData() const {
		if (!isEmpty()) {
			ofstream file(fileName);
			//file.open(fileName);
			if (file) {
				for (int i = 0; i < numSpots; i++) {
					if (parkingSpots[i] != nullptr) {
						parkingSpots[i]->setCsv(true);
						file << *parkingSpots[i];
					}
				}
			}
		}
	}



	Parking::~Parking() {
		saveData();
		delete[] fileName;
		fileName = nullptr;
		//vehicleSelection = nullptr;
		for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
			delete parkingSpots[i];
			parkingSpots[i] = nullptr;
		}
	}


	
	int Parking::run() {
		int res = 1;
		if (!isEmpty()) {
			int choice, done;
			res = 0;
			do{
				parkingStatus();
				done = 1;
				choice = parkMenu.run();
				switch (choice)
				{
				case 1:
					parkVehicle();
					break;

				case 2:
					returnVehicle();
					break;

				case 3:
					listParkedVehicles();
					break;

				case 4:
					if (closeParking()) {
					//	saveData();
						done = 0;
					}
					break;
				default:
					if (exitParkingApp()) {
						//saveData();
						//cout << "Exiting program!" << endl;
						done = 0;
					}
					break;
				}
			} while (done);
		
		}
		return res;
	}
	
	
}