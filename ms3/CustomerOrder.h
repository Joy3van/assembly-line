// Assembly Line Project
// CustomerOrder.h
// Yifan Zhao
// 138736186
// Jul.17.2019
#ifndef SICT_CUSTOMER_ORDER_H_INCLUDED
#define SICT_CUSTOMER_ORDER_H_INCLUDED

#include <iostream>
#include <string>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
    class CustomerOrder {
        std::string custName;
        std::string proName;
        static size_t fieldWidth;
        size_t itemCount;
        // a nested structure used to store the information of an item
        struct ItemInfo {
            std::string iName;
            unsigned int sNumber;
            bool isFilled;
            // a default constructor to set ItemInfo in empty safe state
            //
            ItemInfo() : iName{""}, sNumber{0u}, isFilled{false} {}
        };
        ItemInfo* aLotItems = nullptr;
    public:
        CustomerOrder();
        CustomerOrder(const std::string&);
        CustomerOrder(CustomerOrder&&);
        CustomerOrder& operator=(CustomerOrder&&);
        ~CustomerOrder();
        void fillItem(ItemSet&, std::ostream&);
        bool isFilled() const;
        bool isItemFilled(const std::string&) const;
        std::string getNameProduct() const;
        void display(std::ostream& os, bool showDetail = false) const;
        // disable copy assignment and constructor
        CustomerOrder& operator=(const CustomerOrder&) = delete;
        CustomerOrder(const CustomerOrder&) = delete;
    };
}



#endif // SICT_CUSTOMER_ORDER_H_INCLUDED
