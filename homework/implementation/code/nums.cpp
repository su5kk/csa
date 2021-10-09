//------------------------------------------------------------------------------
// nums.cpp - содержит функции обработки сообщения.
//------------------------------------------------------------------------------

#include "nums.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров
void In(nums &p, std::ifstream &ifst) {
    ifst >> p.message;
}

// Случайный ввод параметров
void InRnd(nums &f) {
    for (size_t i = 0; i < MAX_MESSAGE; ++i) {
        f.message[i] = char('a' + Random());
    }
}

//------------------------------------------------------------------------------
// Вывод параметров
void Out(nums &f, std::ofstream &ofst) {
    ofst << "It is nums cipher: message = "
         << f.message << "\n"
         << "Div result: " << Div(f) << "\n";
}

//------------------------------------------------------------------------------
// Частное от незашифрованного сообщения.
double Div(nums &f) {
    double sum = 0;
    double counter = 0;
    for (int i = 0; i < MAX_MESSAGE; i++) {
        sum += f.message[i];
        ++counter;
    }
    return sum / counter;
}