#ifndef SETTIMANALE_H
#define SETTIMANALE_H

#include "rivista.h"

using std::string;

class Settimanale : public Rivista
{
private:

public:
    Settimanale(string t, string g, double p, int u, string e);
};

#endif // SETTIMANALE_H
