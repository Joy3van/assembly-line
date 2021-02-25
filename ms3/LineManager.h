// Assembly Line Project
// LineManager.h
// Yifan Zhao
// 138736186
// Aug.1.2019
#ifndef LINEMANAGER_H_INCLUDED
#define LINEMANAGER_H_INCLUDED

#include <iostream>
#include <vector>
#include "Station.h"

namespace sict {
    class LineManager {
        std::vector<Station*> staAddresses;
        std::vector<size_t> staIndex; // index of the vector of station addresses
        std::deque<CustomerOrder> toBeFilled; // used to store the customer orders need to be filled
        std::deque<CustomerOrder> completed; // used to store the filled orders
        std::deque<CustomerOrder> incomplete;// used to store the incomplete orders
        std::vector<size_t> staOrder;// used to store the orders that stations need to process
        size_t startingIndex;
        size_t endingIndex;
        size_t orderItems;
    public:
        LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
        void display(std::ostream&) const;
        bool run(std::ostream&);
    };
}




#endif // LINEMANAGER_H_INCLUDED
