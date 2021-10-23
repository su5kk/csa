//------------------------------------------------------------------------------
// text.cpp
//------------------------------------------------------------------------------

#include "text.h"
#include "string.h"
#include "symbol.h"
#include "nums.h"
#include "shift.h"
#include "reader.h"
#include <iostream>

using std::string;

//------------------------------------------------------------------------------
// Ввод параметров обобщенного текста из файла.
Text* Text::StaticIn(ifstream *ifst) {
    Text* txt;
    char type[6];
    *ifst >> type;
    if (!strcmp(type, "nums")) {
        txt = new Nums;
    } else if (!strcmp(type, "symbol")) {
        txt = new Symbol;
    } else if (!strcmp(type, "shift")) {
        txt = new Shift;
    } else {
        std::cout << "ERROR: wrong cipher type" << type;
        exit(1);
    }
    txt->In(ifst);
    return txt;
}

Text *Text::StaticInRnd() {
    int k = 1 + (rand() % 3);
    Text* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Symbol;
            break;
        case 2:
            sp = new Nums;
            break;
        case 3:
            sp = new Shift;
            break;
        default:
            return nullptr;
    }
    sp->InRnd();
    return sp;
}