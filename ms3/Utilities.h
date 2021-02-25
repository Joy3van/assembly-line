// Assembly Line Project
// Utilities.h
// Yifan Zhao
// 138736186
// Jul.10.2019
#ifndef SICT_UTILITIES_H_INCLUDED
#define SICT_UTILITIES_H_INCLUDED

#include <string>

namespace sict {
    class Utilities {
        static size_t fieldWidth;
        static char delimiter;
    public:

        Utilities();
        const std::string extractToken(const std::string&, size_t&);

        const char getDelimiter() const;

        size_t getFieldWidth() const;
        static void setDelimiter(const char);
        void setFieldWidth(size_t);
    };
}


#endif // SICT_TILITIES_H_INCLUDED
