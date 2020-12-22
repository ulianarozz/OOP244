/**********************************************************
 * Name:Uliana Rozzhyvaikina
 * Student ID: 132294190
 * Seneca email: urozzhyvaikina@myseneca.ca
 * Section: NDD
 * Date: 2020/07/07
 **********************************************************/
 // I finished this assignment by myself
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Basket.h"

using namespace std;

namespace sdds
{
    Basket::Basket() {
        emptyState();
    }

    Basket::Basket(Fruit *fruits, int cnt, double price) {
        m_fruits = nullptr;
        m_cnt = 0;
        m_price = 0;
       
        if (fruits != nullptr && cnt > 0 && price > 0) {
            m_cnt = cnt;
           delete[] m_fruits;
            m_fruits = new Fruit[cnt + 1];
            for (int i = 0; i < cnt; i++) {
                m_fruits[i] = fruits[i];
            }
            m_price = price;
        }
        else {
            emptyState();
        }
    }

    Basket::Basket(const Basket& basket) {
        //shallow copies
        m_cnt = basket.m_cnt;
        m_price = basket.m_price;
        if (basket.m_fruits != nullptr ) {
            m_fruits = new Fruit[m_cnt + 1];
            for (int i = 0; i < m_cnt; i++) {
                m_fruits[i] = basket.m_fruits[i];
            }
        }
        else {
            m_fruits = nullptr;
        }
    }

    Basket& Basket::operator=(const Basket& basket) { // assignment copy
        if (this != &basket) { 
            m_cnt = basket.m_cnt;
            m_price = basket.m_price;
            delete[] m_fruits;
            if (basket.m_fruits != nullptr) {
                m_fruits = new Fruit[m_cnt + 1];
                for (int i = 0; i < m_cnt; i++) {
                    m_fruits[i] = basket.m_fruits[i];
                }
            }
            else {
                m_fruits = nullptr;
            }
        }
        return *this;
    }

    Basket::~Basket() {
        delete[] m_fruits;
        m_fruits = nullptr;
    }

    void Basket::emptyState() {
        m_fruits = nullptr;
        m_cnt = 0;
        m_price = 0;
    }

    void Basket::setPrice(double price) {
        if (price >= 0) {
            m_price = price;
        }
    }

    Basket::operator bool() const {
        bool check = true;
        if (m_fruits == nullptr) {
            check = false;
        }
        return check;
    }

  

    ostream& Basket::display(ostream& os) const {
        if (m_fruits==nullptr) {
            os << "The basket is empty!" << std::endl;
        }
        else {
            os << "Basket Content:" << std::endl;
            for (int i = 0; i < m_cnt; i++) {
                os.width(10);
                os << m_fruits[i].m_name << ": " << m_fruits[i].m_qty <<"kg" <<endl;
            }
            os.setf(std::ios::fixed);
            os.precision(2);
            os << "Price: " << m_price << std::endl;
        }
        return os;
    }


    Basket&Basket::operator+=(Fruit fruit) {
        Fruit* temp = new Fruit[m_cnt + 1];
        for (int i = 0; i < m_cnt; i++) {
            temp[i] = m_fruits[i];
        }
        temp[m_cnt++] = fruit;
        delete[] m_fruits;
        m_fruits = temp;
        return *this;
    }

  

    ostream& operator<<(ostream& os, const Basket& basket) {
        basket.display(os);
        return os;
    }
}
