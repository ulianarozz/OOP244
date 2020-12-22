/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Definition of Parking.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include<iostream>
#include "Menu.h"
#include"Vehicle.h"
//#include"Motorcycle.h"
#include"ReadWritable.h"
#include"Utils.h"
//#include"Parking.h"
namespace sdds {
	const int MAX_PARKING_SPOTS = 100;
	class Parking :public Menu {
		char* fileName;
		Menu parkMenu;
		Menu vehicleSelection;
		int numSpots;
		//int availableSpots;
		Vehicle* parkingSpots[MAX_PARKING_SPOTS];
		bool loadData();
		bool isEmpty()const;
		int numOfParkedVehicles;
		void empty();
		void setName(const char* name);
		void saveData() const;
		Parking(const Parking& source) = delete;
		Parking& operator=(const Parking& source) = delete;
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles()const;
		bool closeParking();
		bool exitParkingApp() ;
	public:
		using Menu::Menu;
		Parking(const char* name, int noOfSpots);
		~Parking();
		int run();
		//int setSpots(int spts);
	};
	//void clear(void);
}
#endif 