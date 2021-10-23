//------------------------------------------------------------------------------
// shift.cpp - содержит функции обработки сообщения, зашифрованного методом сдвига.
//------------------------------------------------------------------------------

#include "shift.h"
#include "rnd.h"

Shift::~Shift() = default;
//------------------------------------------------------------------------------
// Ввод параметров
void Shift::In(std::ifstream *ifst) {
    *ifst >> message;
}

// Случайный ввод параметров
void Shift::InRnd() {
    for (size_t i = 0; i < MAX_MESSAGE; ++i) {
        message[i] = char('a' + Random());
    }
}

//------------------------------------------------------------------------------
// Вывод параметров
void Shift::Out(std::ofstream *ofst) {
    *ofst << "It is Shift cipher: message = "
         << message << "\n"
         << "Div result: " << Div() << "\n";
}

//------------------------------------------------------------------------------
// Частное от незашифрованного сообщения.
double Shift::Div() {
    double sum = 0;
    double counter = 0;
    for (int i = 0; i < MAX_MESSAGE; i++) {
        sum += message[i];
        ++counter;
    }
    return sum / counter;
}