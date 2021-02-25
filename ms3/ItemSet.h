// Assembly Line Project
// ItemSet.h
// Yifan Zhao
// 138736186
// Jul.10.2019
#ifndef SICT_ITEM_SET_H_INCLUDED
#define SICT_ITEM_SET_H_INCLUDED

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
        void display(std::ostream& os, bool full = true) const;
        ItemSet(ItemSet&&);
        // disable list
        ItemSet& operator=(const ItemSet&) = delete;
        ItemSet& operator=(ItemSet&&) = delete;
        ItemSet(const ItemSet&) = delete;
    };
}



#endif // SICT_ITEM_SET_H_INCLUDED
