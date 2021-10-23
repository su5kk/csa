//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

using namespace std;

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }
    clock_t startTime = clock();
    cout << "Start"<< endl;
    auto* c = new Container();
    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        try {
            ifstream ifst(argv[2]);
            if (!ifst.is_open()) {
                std::cout << "Can't open file :(";
                return 1;
            }
            c->In(&ifst);
        } catch (std::exception& e) {
            std::cout << "Failed: " << e.what();
            return 1;
        }
    }
    else if(!strcmp(argv[1], "-n")) {
        int size;
        try {
            size = std::stoi(argv[2]);
        } catch (std::exception& e) {
            cout << "Number of figures should be integer!\n"
                    "Failed with error: " << e.what();
            return 3;
        }
        if((size < 1) || (size > 10000)) { 
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c->InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    try {
        ofstream ofst1(argv[3]);
        if (!ofst1.is_open()) {
            std::cout << "Can't open file :(";
        } else {
            ofst1 << "Filled container:\n";
            c->Out(&ofst1);
        }
    } catch (std::exception& e) {
        std::cout << "Failed: " << e.what();
    }

    // The 2nd part of task
    try {
        ofstream ofst2(argv[4]);
        ofst2 << "Sorted container:\n";
        c->Sort();
        c->Out(&ofst2);
    } catch (std::exception& e) {
        std::cout << "Failed: " << e.what();
    }
    delete c;
    cout << "Stop in "<< ((double)(clock() - startTime)) / CLOCKS_PER_SEC;
    return 0;
}
