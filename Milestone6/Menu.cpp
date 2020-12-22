/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Implentation file of Menu.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {

	MenuItem::MenuItem() {
		setItem(nullptr);
	}
	MenuItem::MenuItem(const char* item) {

		setItem(item);
	}
	void MenuItem::setItem(const char* item) {
		if (item != nullptr && item[0] != '\0') {
			itemName = new char[strlen(item) + 1];
			strcpy(itemName, item);

		}
		else {

			itemName = nullptr;
		}
	}
	void MenuItem::emptyState() {

		itemName = nullptr;
	}
	std::ostream& MenuItem::display() const {
		if (itemName != nullptr && itemName[0] != '\0') {
			cout << itemName << endl;
		}
		return cout;
	}
	MenuItem::~MenuItem() {

		delete[] itemName;
		itemName = nullptr;

	}
	void Menu::ident()const {
		for (int i = 0; i < identation; i++)
		{
			std::cout << "    ";
		}

	}
	Menu::Menu() {
		setName(nullptr);
		setItems({ nullptr }, 0);
		setId(0);
		
	}
	Menu::Menu(const char* name, int id) {
		setName(name);
		setItems({ nullptr }, 0);
		setId(id);
	}

	void Menu::setItems(MenuItem* const items[], int num) {
		numItems = 0;
		for (int i = 0; i < numItems; i++) {
			delete MenuItems[i];
			MenuItems[i] = nullptr;
		}
		if (num > 0) {

			numItems = num <= MAX_NO_OF_ITEMS ? num : MAX_NO_OF_ITEMS;
			for (int i = 0; i < numItems; i++) {
				MenuItems[i] = new MenuItem(items[i]->itemName);
			}
		}
		else {

			for (int i = 0; i < numItems; i++) {
				MenuItems[i] = nullptr;
			}
			numItems = 0;
		}
	}
	void Menu::setName(const char* name) {

		if (name != nullptr) {
			titleName = new char[strlen(name) + 1];
			strcpy(titleName, name);
		}
		else {
			titleName = nullptr;
		}
	}
	void Menu::setId(int id) {
		if (id > 0) {
			identation = id;
		}
		else {
			identation = 0;
		}
	}
	Menu::operator int() const {
		return run();
	}
	Menu::operator bool() const {
		bool check = true;
		if (!isEmpty()) {
			check = true;
		}
		else { check = false; }
		return check;
	}
	bool Menu::isEmpty()const {
		bool check = true;
		if (titleName == nullptr) {
			check = true;
		}
		else {
			check = false;
		}
		return check;
	}
	void Menu::emptyState() {
		for (int i = 0; i < numItems; i++) {
			delete[] MenuItems[i];
			MenuItems[i] = nullptr;
		}
		titleName = nullptr;
		numItems = 0;
		identation = 0;
	}
	Menu::Menu(const Menu& menu) { // shallow copy
		setName(menu.titleName);
		setItems(menu.MenuItems, menu.numItems);
		setId(menu.identation);

	}
	Menu& Menu::operator=(const Menu& source) { //assignment copy
		if (this != &source) {
			delete[] titleName;
			titleName = nullptr;
			for (int i = 0; i < numItems; i++) {
				delete MenuItems[i];
				MenuItems[i] = nullptr;
			}
			setName(source.titleName);
			setItems(source.MenuItems, source.numItems);
			setId(source.identation);


		}

		return *this;
	}
	Menu::~Menu() {

		delete[] titleName;
		titleName = nullptr;

		for (int i = 0; i < numItems; i++)
		{
			delete MenuItems[i];
			MenuItems[i] = nullptr;
		}

	}
	std::ostream& Menu::display()const {
		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else {
			ident();
			std::cout << titleName << std::endl;
			if (MenuItems[0] == nullptr) {
				std::cout << "No Items to display!" << std::endl;
			}
			else {

				for (int i = 0; i < numItems; i++) {
					ident();
					std::cout << i + 1 << "- ";
					MenuItems[i]->display();
				}
				ident();
				std::cout << "> ";
			}
		}
		//delete[] titleName;
		//titleName = nullptr;
		return cout;
	}
	Menu& Menu::operator=(const char* name) {
		delete[] titleName;
		if (name != nullptr) {
			setName(name);
		}
		else {
			setName(nullptr);
			setItems({ nullptr }, 0);
			setId(0);
		}
		return *this;
	}
	void Menu::add(const char* newname) {
		if (!isEmpty()) {
			if (numItems < MAX_NO_OF_ITEMS) {
				if (newname != nullptr && newname[0] != '\0') {

					MenuItems[numItems] = new MenuItem(newname);
					numItems++;
				}
				else {
					delete[] titleName;
					titleName = nullptr;
					/*for (int i = 0; i < numItems; i++) {
						delete[] MenuItems[i];
						MenuItems[i] = nullptr;

					}*/
					setName(nullptr);
					setItems({ nullptr }, 0);
					setId(0);
				}
			}
		}

	}
	Menu& Menu::operator<<(const char* item) {
		add(item);
		return *this;
	}
	int Menu::run()const {
		int selection = 0;
		display();
		if (!isEmpty() && numItems > 0) {
			Utils::read(selection, 1, numItems, "Invalid selection, try again: ");

		}
		return selection;
	}



}