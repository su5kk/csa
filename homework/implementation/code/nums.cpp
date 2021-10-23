//------------------------------------------------------------------------------
// nums.cpp - содержит функции обработки сообщения.
//------------------------------------------------------------------------------

#include "nums.h"
#include "rnd.h"

Nums::~Nums() = default;
//------------------------------------------------------------------------------
// Ввод параметров
void Nums::In(std::ifstream *ifst) {
    *ifst >> message;
}

// Случайный ввод параметров
void Nums::InRnd() {
    for (size_t i = 0; i < MAX_MESSAGE; ++i) {
        message[i] = char('a' + Random());
    }
}

//------------------------------------------------------------------------------
// Вывод параметров
void Nums::Out(std::ofstream *ofst) {
    *ofst << "It is Nums cipher: message = "
         << message << "\n"
         << "Div result: " << Div() << "\n";
}

//------------------------------------------------------------------------------
// Частное от незашифрованного сообщения.
double Nums::Div() {
    double sum = 0;
    double counter = 0;
    for (int i = 0; i < MAX_MESSAGE; i++) {
        sum += message[i];
        ++counter;
    }
    return sum / counter;
}