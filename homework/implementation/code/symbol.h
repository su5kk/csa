#ifndef __symbol__
#define __symbol__

//------------------------------------------------------------------------------
// symbol.h - содержит описание шифрования символ в символ  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include <unordered_map>
#include "rnd.h"
#include "constants.h"
using namespace std;
// шифрование символа в символ
struct symbol {
    unordered_map<char, char>* table;
    char message[MAX_MESSAGE];
};

// Ввод параметров
void In(symbol &r, ifstream &ifst);

// Случайный ввод параметров
void InRnd(symbol &f);

// Вывод параметров
void Out(symbol &r, ofstream &ofst);

// Вычисление
double Div(symbol &r);

#endif //__symbol__
