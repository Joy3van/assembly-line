// Assembly Line Project
// Station.h
// Yifan Zhao
// 138736186
// Aug.1.2019
#ifndef SICT_STATION_H_INCLUDED
#define SICT_STATION_H_INCLUDED

#include <iostream>
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
    class Station {
        std::deque<CustomerOrder> orderQue;
        ItemSet stItemSet;
        std::string stName;
    public:
        Station(const std::string&);
        void display(std::ostream&) const;
        void fill(std::ostream&);
        const std::string& getName() const;
        bool hasAnOrderToRelease() const;
        Station& operator--();
        Station& operator+=(CustomerOrder&&);
        bool pop(CustomerOrder&);
        void validate(std::ostream&) const;

        // disable list
        Station(const Station&) = delete; // no copy
		Station& operator=(const Station&) = delete; // no copy-assign
		Station(Station&&) = delete; // no move
		Station& operator=(Station&&) = delete; // no move-assign
    };
}



#endif // STATION_H_INCLUDED
