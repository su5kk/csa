#ifndef __symbol__
#define __symbol__

//------------------------------------------------------------------------------
// symbol.h - содержит описание шифрования символ в символ  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "constants.h"
#include "text.h"
using namespace std;

class Symbol: public Text {
private:
    char message[MAX_MESSAGE];
public:
    ~Symbol();
    virtual void In(ifstream *ifst);
    virtual void InRnd();
    virtual void Out(ofstream *ofst);
    virtual double Div();
};
#endif //__symbol__
