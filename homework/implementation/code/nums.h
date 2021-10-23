#ifndef __nums__
#define __nums__

#include <fstream>
#include <unordered_map>
#include "rnd.h"
#include "constants.h"
#include "text.h"
using namespace std;

class Nums: public Text {
private:
    char message[MAX_MESSAGE];
public:
    ~Nums();
    virtual void In(ifstream *ifst);
    virtual void InRnd();
    virtual void Out(ofstream *ofst);
    virtual double Div();
};
#endif //__nums__
