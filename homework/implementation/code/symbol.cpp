//------------------------------------------------------------------------------
// symbol.cpp
//------------------------------------------------------------------------------

#include "symbol.h"
#include "rnd.h"
#include "constants.h"

Symbol::~Symbol() = default;
//------------------------------------------------------------------------------
// Ввод параметров
void Symbol::In(std::ifstream *ifst) {
    *ifst >> message;
}

// Случайный ввод параметров
void Symbol::InRnd() {
    for (size_t i = 0; i < MAX_MESSAGE; ++i) {
        message[i] = char('a' + Random());
    }
}

//------------------------------------------------------------------------------
// Вывод параметров
void Symbol::Out(std::ofstream *ofst) {
    *ofst << "It is symbol cipher: message = "
         << message << "\n"
         << "Div result: " << Div() << "\n";
}

//------------------------------------------------------------------------------
// Частное от незашифрованного сообщения.
double Symbol::Div() {
    double sum = 0;
    double counter = 0;
    for (int i = 0; i < MAX_MESSAGE; i++) {
        sum += message[i];
        ++counter;
    }
    return sum / counter;
}