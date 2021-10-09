//------------------------------------------------------------------------------
// text.cpp
//------------------------------------------------------------------------------

#include "text.h"
#include "string.h"
#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров обобщенного текста из файла.
text* In(std::ifstream &ifst) {
    text* txt;
    char type[MAX_NAME];
    ifst >> type;
    if (!strcmp(type, "nums")) {
        txt = new text;
        txt->k = text::NUMS;
        In(txt->num, ifst);
    } else if (!strcmp(type, "symbol")) {
        txt = new text;
        txt->k = text::SYMBOL;
        In(txt->sym, ifst);
    } else if (!strcmp(type, "shift")) {
        txt = new text;
        txt->k = text::SHIFT;
        In(txt->s, ifst);
    } else {
        std::cout << "ERROR: wrong cipher type" << type;
        exit(1);
    }
    return txt;
}

// Случайный ввод
text *InRnd() {
    text *txt;
    auto type = rand() % 3;
    if (type == 0) {
        txt = new text;
        txt->k = text::NUMS;
        InRnd(txt->num);
    } else if (type == 2) {
        txt = new text;
        txt->k = text::SYMBOL;
        InRnd(txt->sym);
    } else {
        txt = new text;
        txt->k = text::SHIFT;
        InRnd(txt->s);
    }
    return txt;
}

//------------------------------------------------------------------------------
// Вывод параметров
void Out(text &txt, std::ofstream &ofst) {
    switch (txt.k) {
        case text::NUMS:
            Out(txt.num, ofst);
            break;
        case text::SYMBOL:
            Out(txt.sym, ofst);
            break;
        case text::SHIFT:
            Out(txt.s, ofst);
            break;
        default:
            ofst << "Incorrect text type!\n";
    }
}

//------------------------------------------------------------------------------
// Частное от сообщения.
double Div(text &txt) {
    switch (txt.k) {
        case text::NUMS:
            return Div(txt.num);
        case text::SYMBOL:
            return Div(txt.sym);
        case text::SHIFT:
            return Div(txt.s);
        default:
            return 0;
    }
}