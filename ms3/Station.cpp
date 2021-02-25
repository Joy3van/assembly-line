// Assembly Line Project
// Station.cpp
// Yifan Zhao
// 138736186
// Aug.1.2019

#include "Station.h"

using namespace std;

namespace sict {
    // one-argument constructor
    //
    Station::Station(const std::string& str) : stItemSet(str) { // calling ItemSet constructor to create sub-object
        stName = stItemSet.getName();
    }
    // display() function, displays the data for its ItemSet on os
    //
    void Station::display(std::ostream& os) const {
        stItemSet.display(os);
    }
    // fill function, a modifier fills the last order in the customer order queue
    //
    void Station::fill(std::ostream& os) {
        if (!orderQue.empty()) {
            orderQue.front().fillItem(stItemSet, os);
        }
    }
    // a query that returns the name(reference) of the ItemSet sub-object
    //
    const std::string& Station::getName() const { return stItemSet.getName(); }
    // a query that returns the release state of the current object
    //
    bool Station::hasAnOrderToRelease() const {
        bool release = false;
        if (!orderQue.empty()) {// ItemSet quantity is unsigned
            if(!stItemSet.getQuantity())
                release = true;
            else
                release = orderQue.front().isItemFilled(stName);
        }
        return release;
    }
    // --operator overloading, decrement the number of items in ItemSet sub-object
    //
    Station& Station::operator--() {
        --stItemSet; // calling ItemSet::operator--
        return *this;
    }
    // +=operator overloading, a modifier move received orders to the back of the station queue
    //
    Station& Station::operator+=(CustomerOrder&& order) {
        orderQue.push_back(move(order));
        return *this;
    }
    // pop function, removes the order at the front of the queue
    //
    bool Station::pop(CustomerOrder& ready) {
        bool ifFilled = false; // Indicate the filled status
        if(!orderQue.empty()) {
            ifFilled = orderQue.front().isItemFilled(stName);
            ready = move(orderQue.front());
            orderQue.erase(orderQue.begin());
        }
        return ifFilled;
    }
    // validate function, a query that reports the state of the ItemSet
    //
    void Station::validate(std::ostream& os) const {
        os << " getName(): " << stItemSet.getName() << endl;
		os << " getSerialNumber(): " << stItemSet.getSerialNumber() << endl;
		os << " getQuantity(): " << stItemSet.getQuantity() << endl;
    }
}
