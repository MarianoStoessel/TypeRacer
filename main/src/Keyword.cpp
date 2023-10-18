#include "Keyword.h"
#include <cstring>

Keyword::Keyword()
{
    //ctor
}
const char *Keyword::getPalabra()
{
    return _palabra;
}
void Keyword::setPalabra(const char *p)
{
    strcpy(_palabra, p);
}
