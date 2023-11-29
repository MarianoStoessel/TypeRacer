#pragma once
#ifndef KEYWORD_H
#define KEYWORD_H
#include <SFML/Graphics.hpp>
class Keyword
{
private:
    char *_p;
    int _tam;

public:
    Keyword();
    Keyword(const char *ini);
    const char *getP();
    int getTam();
    void setP(const char *p);

    virtual ~Keyword();
};

#endif // KEYWORD_H
