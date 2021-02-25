// Assembly Line Project
// ItemSet.cpp
// Yifan Zhao
// 138736186
// Jul.10.2019

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "ItemSet.h"
#include "Utilities.h"


using namespace std;

namespace sict {
    ItemSet::ItemSet(const std::string& str) {
        size_t next_pos = str.find(util.getDelimiter());
        itemName = str.substr(0, next_pos);
        serialNum = std::stoul(util.extractToken(str, next_pos));
        quantity = std::stoul(util.extractToken(str, next_pos));
        itemDesc = util.extractToken(str, next_pos);
        if (util.getFieldWidth() < itemName.size())
			util.setFieldWidth(itemName.size());
    }
    // getName() function, a query that returns the name
    const std::string& ItemSet::getName() const {
        return itemName;
    }
    // getSerialNumber() function, a query that returns the serial number of the item
    const unsigned int ItemSet::getSerialNumber() const {
        return serialNum;
    }
    // getQuantity() function, a query that returns the remaining nuber of items in the set
    const unsigned int ItemSet::getQuantity() const {
        return quantity;
    }
    // overload prefix decrement operator that reduces the number of items in stock by 1 and increases the serial number by 1
    ItemSet& ItemSet::operator--() {
        --quantity;
        ++serialNum;
        return *this;
    }
    // query that displays the information
    void ItemSet::display(std::ostream& os, bool full) const {
        if(full) {
            os << std::left << std::setw(util.getFieldWidth()) << itemName << " ["
               << std::setw(5) << serialNum << "] Quantity " << std::setw(3) << quantity << std::right  << " Description: " << itemDesc << std::endl;
        }
    }
    // move constructor
    ItemSet::ItemSet(ItemSet&& src) {
        if (this != &src) {
            itemName = src.itemName;
            serialNum = src.serialNum;
            quantity = src.quantity;
            itemDesc = src.itemDesc;
            src.itemName = "";
            src.serialNum = 0;
            src.quantity = 0;
            src.itemDesc = "";
        }
    };
}
