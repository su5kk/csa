#ifndef __reader__
#define __reader__

#include "iostream"
#include "fstream"
#include "string"
using std::ifstream;

static string ReadType(ifstream *ifst) {
    std::string number;
    *ifst >> number;
    try {
        return number;
    } catch (const std::exception &_) {
        return 0;
    }
}
#endif //__reader__
