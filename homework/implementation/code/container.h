#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "text.h"
#include "rnd.h"
#include "fstream"

using namespace std;

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container
{
private:
    enum {max_len = 10000};
    void Clear();
    int len;
    Text *cont[max_len];
public:
    Container();
    ~Container();
    void In(ifstream *ifst);
    void InRnd(int size);
    void Out(ofstream *ofst);
    void Sort();
};
#endif
