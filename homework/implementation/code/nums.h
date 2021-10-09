#ifndef __nums__
#define __nums__

//------------------------------------------------------------------------------
// nums.h - содержит описание шифрования символ в символ  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include <unordered_map>
#include "rnd.h"
#include "constants.h"
using namespace std;

// шифрование символа в символ
struct nums {
    char message[MAX_MESSAGE];
};

// Ввод параметров
void In(nums &r, ifstream &ifst);

// Случайный ввод параметров
void InRnd(nums &f);

// Вывод параметров
void Out(nums &r, ofstream &ofst);

// Вычисление
double Div(nums &r);

#endif //__nums__
