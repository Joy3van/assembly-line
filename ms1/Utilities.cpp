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
    // extractToken function,
    const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
            // calculate the length of the token
            size_t tokenLen = str.find(delimiter, next_pos + 1) - next_pos - 1;
            std::string token = str.substr(next_pos + 1, tokenLen);
            // set the next_pos to the next delimiter pos
            next_pos = str.find(delimiter, next_pos + 1);
            if(str.at(next_pos + 1) == delimiter)
                throw std::string("Error! No token between two delimiter!");
        return token;
    }
    void Utilities::setDelimiter(const char d) {
        delimiter = d;
    }
    void Utilities::setFieldWidth(size_t f) {
        fieldWidth = f;
    }
}
