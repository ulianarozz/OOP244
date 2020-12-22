/* Citation and Sources...
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author Uliana Rozzhyvaikina
-----------------------------------------------------------
Date		Reason
2020/08/06 Definition of ReadWritable.h
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <iostream> 

using namespace std;
namespace sdds
{
	class ReadWritable
	{
		bool flag;
	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv()const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& in = std::cin) = 0;
		virtual std::ostream& write(std::ostream& os = std::cout)const = 0;
	};
	std::ostream& operator<<(std::ostream& , const ReadWritable& );
	std::istream& operator>>(std::istream& , ReadWritable& );
}
#endif