/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/07
 **********************************************************/
 // I finished this assignment by myself

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket
    {
        Fruit* m_fruits;
        int m_cnt;
        double m_price;
    public:
        Basket(); //default constructor
        Basket(Fruit* fruits, int cnt, double price); // 3 arg constructor
        ~Basket(); //destructor 
        void emptyState();
        void setPrice(double price);
        explicit operator bool() const;
        std::ostream& display(std::ostream& os) const;
        Basket(const Basket& basket); // copy constructor
        Basket& operator=(const Basket& basket); //copy assignment operator
        Basket& operator+=(Fruit fruit);
    };
    std::ostream& operator<<(std::ostream& os, const Basket& bsk);
}

#endif
