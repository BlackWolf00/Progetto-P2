#ifndef MENSILE_H
#define MENSILE_H

#include "rivista.h"

using std::string;

class Mensile : public Rivista
{
private:

public:
    Mensile(string t, string g, double p, int u, string e);
};

#endif // MENSILE_H
