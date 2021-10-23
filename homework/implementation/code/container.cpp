//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
#include "fstream"
using namespace std;

// Конструктор контейнера
Container::Container(): len(0), cont() {}

// Деструктор контейнера
Container::~Container() {
    Clear();
}

// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream *ifst) {
    while(!ifst->eof()) {
        if((cont[len] = Text::StaticIn(ifst)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((cont[len] = Text::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream *ofst) {
    *ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        *ofst << i << ": ";
        cont[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Сортировка контейнера методом Шэлла методом Шэлла
void Container::Sort() {
    int n = len;
    Text *temp;
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            temp = cont[i];
 
            int j;           
            for (j = i; j >= gap && cont[j - gap]->Div() > temp->Div(); j -= gap) {
                cont[j] = cont[j - gap];
            }
            cont[j] = temp;
        }
    }
}
