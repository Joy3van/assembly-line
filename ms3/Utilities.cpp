// Assembly Line Project
// Utilities.cpp
// Yifan Zhao
// 138736186
// Jul.10.2019

#include <string>
#include <iostream>
#include "Utilities.h"
namespace sict {
    //----------------------------Private-------------------------
    // static class variable initialization
    size_t Utilities::fieldWidth = 0;
    char Utilities::delimiter = '\0';
    //----------------------------Public--------------------------
    // default constructor set the object in a safe empty state
    //
    Utilities::Utilities() {}
    // extractToken function,
    const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
            std::string token;
            size_t length = 0;
            size_t start_pos = 0;
            size_t deli_pos = str.find(delimiter, next_pos + 1);
            if(next_pos != 0) {
                length = deli_pos - next_pos - 1;
                start_pos = next_pos + 1;
            }
            else {
                length = deli_pos;
                start_pos = next_pos;
            }
            token = str.substr(start_pos, length);
            next_pos = deli_pos;
            return token;
    }
    // a query that returns the delimiter character
    //
    const char Utilities::getDelimiter() const { return delimiter; }
    // a query that returns the field width for the current object
    //
    size_t Utilities::getFieldWidth() const { return fieldWidth; }
    void Utilities::setDelimiter(const char d) {
        delimiter = d;
    }

    void Utilities::setFieldWidth(size_t f) {
        fieldWidth = f;
    }
}
