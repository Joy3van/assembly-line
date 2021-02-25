// Assembly Line Project
// Utilities.h
// Yifan Zhao
// 138736186
// Jul.10.2019
#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <string>

namespace sict {
    class Utilities {
        static size_t fieldWidth;
        static char delimiter;
    public:
        // default constructor set the object in a safe empty state
        Utilities() {}
        const std::string extractToken(const std::string&, size_t&);
        // a query that returns the delimiter character
        const char getDelimiter() const { return delimiter; }
        // a query that returns the field width for the current object
        size_t getFieldWidth() const { return fieldWidth; }
        static void setDelimiter(const char);
        void setFieldWidth(size_t);
    };
}


#endif // UTILITIES_H_INCLUDED
