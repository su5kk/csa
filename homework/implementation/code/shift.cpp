//------------------------------------------------------------------------------
// shift.cpp - содержит функции обработки сообщения, зашифрованного методом сдвига.
//------------------------------------------------------------------------------

#include "shift.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров
void In(shift &p, std::ifstream &ifst) {
    ifst >> p.message;
}

// Случайный ввод параметров
void InRnd(shift &f) {
    for (size_t i = 0; i < MAX_MESSAGE; ++i) {
        f.message[i] = char('a' + Random());
    }
}

//------------------------------------------------------------------------------
// Вывод параметров
void Out(shift &f, std::ofstream &ofst) {
    ofst << "It is shift cipher: message = "
         << f.message << "\n"
         << "Div result: " << Div(f) << "\n";
}

//------------------------------------------------------------------------------
// Частное от незашифрованного сообщения.
double Div(shift &f) {
    double sum = 0;
    double counter = 0;
    for (int i = 0; i < MAX_MESSAGE; i++) {
        sum += f.message[i];
        ++counter;
    }
    return sum / counter;
}