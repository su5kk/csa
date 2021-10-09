#ifndef __shift__
#define __shift__

//------------------------------------------------------------------------------
// shift.h - содержит описание шифрования символ в символ  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "rnd.h"
#include "constants.h"
using namespace std;

// шифрование сдвигом
struct shift {
    char message[MAX_MESSAGE];
};

// Ввод параметров
void In(shift &r, ifstream &ifst);

// Случайный ввод параметров
void InRnd(shift &f);

// Вывод параметров
void Out(shift &r, ofstream &ofst);

// Вычисление
double Div(shift &r);

#endif //__shift__
