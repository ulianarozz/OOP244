/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/24
 **********************************************************/
 // I finished this assignment by myself

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H
#include <cstring>
namespace sdds {
	const int TYPE_MAX_SIZE = 30;
	class Engine
	{
		double m_size;
		char m_type[TYPE_MAX_SIZE + 1];

	public:
		Engine();
		Engine(const char* type,double size);
		~Engine();
		void emptyState();
		double get() const;
		void display() const;
		
	};


	
}
#endif