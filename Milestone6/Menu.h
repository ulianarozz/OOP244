/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.h
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Definition of Menu.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include "Utils.h"
#include <ostream>
const int MAX_NO_OF_ITEMS = 10;
using namespace std;
namespace sdds {
	class MenuItem {
		char* itemName;
		MenuItem();
		MenuItem(const char* item);
		void setItem(const char* item);
		void emptyState();
		std::ostream& display() const;
		MenuItem(const MenuItem& source) = delete;
		MenuItem& operator=(const MenuItem& source) = delete;
		friend class Menu;
		~MenuItem();
	};

	class Menu {
		char* titleName;
		int numItems;
		int identation;
		MenuItem* MenuItems[MAX_NO_OF_ITEMS];

	public:
		Menu();
		Menu(const char* name, int id = 0);
		void ident()const;
		Menu(const Menu& source);
		Menu& operator=(const Menu& source);
		operator bool()const;
		bool isEmpty() const;
		void emptyState();

		void setName(const char* name);
		void setId(int identation);
		void setItems(MenuItem* const items[], int num);
		std::ostream& display() const;
		Menu& operator=(const char* name);
		void add(const char* newname);
		int run()const;
		Menu& operator<<(const char* item);
		operator int() const;
		~Menu();

	};



}
#endif 