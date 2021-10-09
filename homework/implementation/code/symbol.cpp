//------------------------------------------------------------------------------
// symbol.cpp
//------------------------------------------------------------------------------

#include "symbol.h"
#include "rnd.h"
#include "constants.h"

//------------------------------------------------------------------------------
// Ввод параметров
void In(symbol &p, std::ifstream &ifst) {
    ifst >> p.message;
}

// Случайный ввод параметров
void InRnd(symbol &f) {
    for (size_t i = 0; i < MAX_MESSAGE; ++i) {
        f.message[i] = char('a' + Random());
    }
}

//------------------------------------------------------------------------------
// Вывод параметров
void Out(symbol &f, std::ofstream &ofst) {
    ofst << "It is symbol cipher: message = "
         << f.message << "\n"
         << "Div result: " << Div(f) << "\n";
}

//------------------------------------------------------------------------------
// Частное от незашифрованного сообщения.
double Div(symbol &f) {
    double sum = 0;
    double counter = 0;
    for (int i = 0; i < MAX_MESSAGE; i++) {
        sum += f.message[i];
        ++counter;
    }
    return sum / counter;
}