#pragma once
#ifndef KEYWORD_H
#define KEYWORD_H

class Keyword
{
    private:
        char *_p;
        int _tam;

    public:
        Keyword(const char *ini = "NULL");

        const char *getP();
        int getTam();

        void setP(const char *p);

        virtual ~Keyword();
};

#endif // KEYWORD_H
