#pragma once
#ifndef KEYWORD_H
#define KEYWORD_H

class Keyword
{
    private:
        char _palabra[10]; //memoria dinamica, num 10 auxiliar

    public:
        Keyword();

        const char *getPalabra();
        void setPalabra(const char *p);
};

#endif // KEYWORD_H
