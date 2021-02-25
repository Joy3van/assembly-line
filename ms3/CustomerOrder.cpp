// Assembly Line Project
// CustomerOrder.cpp
// Yifan Zhao
// 138736186
// Jul.17.2019

#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"

using namespace std;

namespace sict {
    //---------------------------Private-----------------------
    // static class variable initialization
    size_t CustomerOrder::fieldWidth = 0;
    //---------------------------Public------------------------
    // default constructor sets empty state for the object
    //
    CustomerOrder::CustomerOrder() : custName{}, proName{}, itemCount{0} {}
    // one-argument constructor
    //
    CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities utily;
        // assign customer name
        size_t the_pos = str.find(utily.getDelimiter());
        custName = str.substr(0, the_pos);
        // determine field width to be used in displaying customer names for all orders managed by this class
        fieldWidth = fieldWidth < utily.getFieldWidth() ? utily.getFieldWidth() : fieldWidth;
        proName = utily.extractToken(str, the_pos);
        itemCount = count(begin(str), end(str), utily.getDelimiter()) - 1; // using STL count the number of items
        aLotItems = new ItemInfo[itemCount];
        if (itemCount < 1)
            throw string("Can't find any item!");
        else {
            for(size_t i = 0; i < itemCount; ++i) {
                aLotItems[i].iName = utily.extractToken(str, the_pos);
            }
        }
    }
    // Move assignment operator
    //
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
        // self assignment check
        if (this != &src) {
            custName = src.custName;
            proName = src.proName;
            itemCount = src.itemCount;
            aLotItems = src.aLotItems;
            src.aLotItems = nullptr;
        }
        return *this;
    }
    // Move constructor
    //
    CustomerOrder::CustomerOrder(CustomerOrder&& src) {
        *this = move(src);
    }
    // Destructor
    //
    CustomerOrder::~CustomerOrder() {
        delete [] aLotItems;
        aLotItems = nullptr;
    }
    // fillItem function,
    //
    void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
        for (size_t i = 0; i < itemCount; ++i) {
            if (item.getName() == aLotItems[i].iName) {
                if (item.getQuantity() && !isItemFilled(item.getName())) { // quantity is unsigned so it's either 0 or not 0 ( > 0)
                    aLotItems[i].sNumber = item.getSerialNumber();
                    aLotItems[i].isFilled = true;
                    --item;
                    os << " Filled " << getNameProduct() << "[" << aLotItems[i].iName << "][" << aLotItems[i].sNumber << "]" << endl;
                }
                else {
                    if (!item.getQuantity()) {
                        os << " Unable to fill " << getNameProduct() << "[" << aLotItems[i].iName << "][" << aLotItems[i].sNumber << "]" << " out of stock" << endl;
                    }
                    if (isItemFilled(item.getName())) {
                        os << " Unable to fill " << getNameProduct() << "[" << aLotItems[i].iName << "][" << aLotItems[i].sNumber << "]" << " already filled" << endl;
                    }
                }
            }
        }
    }
    // isFilled Function, a query that searches the list of items requested
    //
    bool CustomerOrder::isFilled() const {
        for (size_t i = 0; i < itemCount; ++i) {
            if (!aLotItems[i].isFilled)
                return false;
        }
        return true;
    }
    // isItemFilled function, a query searches the item request list for that item
    //
    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        for (size_t i = 0; i < itemCount; ++i) {
            if (aLotItems[i].iName == itemName) {
                if (!aLotItems[i].isFilled)
                    return false;
            }
        }
        return true;
    }
    // getNameProduct function, a query that returns the name of the customer and product
    //
    std::string CustomerOrder::getNameProduct() const {
        return custName + " [" + proName + "]";
    }
    // display function, display the order in required format
    //
    void CustomerOrder::display(std::ostream& os, bool showDetail) const {
        os << std::left << setw(fieldWidth) << custName << " [" << proName << "]" << endl;
        if (!showDetail) {
            for (size_t i = 0; i <itemCount; ++i) {
                os << setfill(' ') << setw(fieldWidth + 1) << "    " << std::right << aLotItems[i].iName << endl;
            }
        }
        else {
            for (size_t i = 0; i < itemCount; ++i) {
                 os << setfill(' ') << setw(fieldWidth + 1) << " " << "[" << aLotItems[i].sNumber << "] " << aLotItems[i].iName << " - "
                    << ((aLotItems[i].isFilled) ? "FILLED" : "MISSING") << endl;
            }
        }
    }
}
