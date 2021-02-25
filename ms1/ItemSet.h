// Assembly Line Project
// ItemSet.h
// Yifan Zhao
// 138736186
// Jul.10.2019
#ifndef ITEMSET_H_INCLUDED
#define ITEMSET_H_INCLUDED

#include <string>
#include <iostream>
#include "Utilities.h"

namespace sict {
    class ItemSet {
        std::string itemName;
        unsigned int serialNum;
        unsigned int quantity;
        std::string itemDesc;
        Utilities util;
    public:
        ItemSet(const std::string&);
        const std::string& getName() const;
        const unsigned int getSerialNumber() const;
        const unsigned int getQuantity() const;
        ItemSet& operator--();
        void display(std::ostream& os, bool full) const;
        ItemSet(ItemSet&&);
        // disable list
        ItemSet& operator=(const ItemSet&) = delete;
        ItemSet& operator=(ItemSet&&) = delete;
        ItemSet(const ItemSet&) = delete;
    };
}



#endif // ITEMSET_H_INCLUDED
