/***********************************************************************
// Workshop 2: Dynamic Memory & Function Overloading
// Version 2.0
// Date	2020/05/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/06/02
 **********************************************************/
 //I have done all the coding by myself.

#include <iostream>
#include "Gift.h"
#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {
    int numberOfGifts = 0; // Initial number of Gifts

    // TODO 1: declare a pointer for a dynamic array of Gifts (remember to initialize it)
    Gift *Gifts = nullptr;
    // END TODO 1

    cout << "Enter number of Gifts to allocate: ";
    cin >> numberOfGifts;
    cin.ignore(2000, '\n');
    if (numberOfGifts < 1)
        return 1;

    // TODO 2: allocate dynamic memory for the gifts pointer using the numberOfGifts
   Gifts = new Gift[numberOfGifts];
    // END TODO 2

    for (int i = 0; i < numberOfGifts; ++i)
    {
        cout << "Gift #" << i + 1 << ": " << endl;

        // TODO 3: utilizing the gifting functions, allow input for the gift's description
        gifting(Gifts[i].m_description);
        // END TODO 3

        cin.ignore(2000, '\n'); // clear input buffer

        // TODO 4: utilizing the gifting functions, allow the user to input the gift's price
        gifting(Gifts[i].m_price);
        // END TODO 4

        cin.ignore(2000, '\n'); // clear input buffer

        // TODO 5: utilizing the gifting functions, allow the user to input the units of gift
        gifting(Gifts[i].m_units);
        // END TODO 5
        cin.ignore(2000, '\n');
        cout << endl;
    }



    // TODO 6: display the details of each gift using the Gifts module display function
    for (int i = 0; i < numberOfGifts;i++) {
        cout << "Gift #" << i + 1 <<": "<< endl;
        display(Gifts[i]);
        cout << endl;
    }
    // END TODO 6
  
    // TODO 7: deallocate the gifts pointer here to avoid memory as we are done with it
    delete[] Gifts;
    Gifts = nullptr;
    // END TODO 7

    return 0;
}