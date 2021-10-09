#ifndef __text__
#define __text__

//------------------------------------------------------------------------------
// text.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include "nums.h"
#include "symbol.h"
#include "shift.h"
#include "rnd.h"

const int MAX_NAME = 6;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct text {
    char type[MAX_NAME];
    enum key {NUMS, SYMBOL, SHIFT};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        nums num;
        symbol sym;
        shift s;
    };
};

// Ввод
text *In(ifstream &ifdt);

// Случайный ввод
text *InRnd();

// Вывод
void Out(text &s, ofstream &ofst);

// Вычисление
double Div(text &s);

#endif
