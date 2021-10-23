#ifndef __text__
#define __text__

#include <fstream>
using namespace std;

class Text {
public:
    virtual ~Text() = default;
    static Text *StaticIn(ifstream *ifdt);
    virtual void In(ifstream *ifst) = 0;
    static Text *StaticInRnd();
    virtual void InRnd() = 0;
    virtual void Out(ofstream *ofst) = 0;
    virtual double Div() = 0;
};
#endif
