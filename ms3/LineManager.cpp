// Assembly Line Project
// LineManager.cpp
// Yifan Zhao
// 138736186
// Aug.1.2019

#include <algorithm>
#include "LineManager.h"

using namespace std;

namespace sict {
    // five-argument constructor, moves customer orders to the front of a queue holding orders and determines index of last station
    //
    LineManager::LineManager(std::vector<Station*>& address, std::vector<size_t>& index, std::vector<CustomerOrder>& filleeOrders, size_t start, std::ostream& os) {
        staAddresses = address;
        startingIndex = start;

        for(auto& order : filleeOrders) {
            toBeFilled.push_back(std::move(order));
        }
        // store the orders that station need to process to staOrder
        staOrder.push_back(start);
        for(size_t i = 0; i < index.size(); ++i) {
            staOrder.push_back(index[start]);
            start = index[start];
        }
        // set the last index on the line
        endingIndex = staOrder.back();
        staIndex = index;
        orderItems = toBeFilled.size();
    }
    // display function, display completed/incomplete orders at the end of the line
    //
    void LineManager::display(std::ostream& os) const {
        os << "COMPLETED ORDERS" << endl;
        for(auto& order : completed) {
            order.display(os, true);
        }
        os << endl;
        os << "INCOMPLETE ORDERS" << endl;
        for(auto& order: incomplete) {
            order.display(os, true);
        }
    }
    // run function, executing the whole procedures of this module
    //
    bool LineManager::run(std::ostream& os) {
        bool terminate = false;
        CustomerOrder temp;

        if(!toBeFilled.empty()) {
            *staAddresses[startingIndex] += std::move(toBeFilled.front());
            toBeFilled.pop_front();
        }
        for (size_t i = 0; i != staIndex.size(); ++i) {
            staAddresses[i]->fill(os);
        }
        for (size_t i = 0; i < staAddresses.size(); ++i) {
            if (staAddresses[i]->hasAnOrderToRelease()) {
                if (staIndex[i] == endingIndex) {
                    staAddresses[i]->pop(temp);
                    if(temp.isFilled()) {
                        os << " --> " << temp.getNameProduct() << " move from " << staAddresses[i]->getName() << " to Completed Set" << endl;
                        completed.push_back(std::move(temp));
                        --orderItems;
                    }
                    else {
                        os << " --> " <<temp.getNameProduct() << " move from " << staAddresses[i]->getName() << " to Incomplete Set" << endl;
                        incomplete.push_back(std::move(temp));
                        --orderItems;
                    }
                }
                else {
                    staAddresses[i]->pop(temp);
                    os << " --> " <<temp.getNameProduct() << " move from " << staAddresses[i]->getName() << " to "
                       << staAddresses[staIndex[i]]->getName() << endl;
                    *staAddresses[staIndex[i]] += std::move(temp);
                }
            }
        }
        return terminate = (orderItems == 0 ? true : false);
    }
}
