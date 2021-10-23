#ifndef __shift__
#define __shift__

//------------------------------------------------------------------------------
// shift.h - содержит описание шифрования символ в символ  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "rnd.h"
#include "constants.h"
#include "text.h"
using namespace std;

class Shift: public Text {
private:
    char message[MAX_MESSAGE];
public:
    ~Shift();
    virtual void In(ifstream *ifst);
    virtual void InRnd();
    virtual void Out(ofstream *ofst);
    virtual double Div();
};
#endif //__shift__
