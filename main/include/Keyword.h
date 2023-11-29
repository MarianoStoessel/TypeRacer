#pragma once
#ifndef KEYWORD_H
#define KEYWORD_H
#include <SFML/Graphics.hpp>
#include "Nivel.h"
class Keyword
{
    private:
        char *_keyword;
        int _tam;
        char _nombre[30];
        Nivel _nivel;

    public:
        Keyword();
        Keyword(int niv);
        const char *getP();
        int getTam();
        void setP(const char *p);

        ///Metodos para archivo
        bool grabarEnDisco();
        bool leerDeDisco(int pos);// para leer un registro del archivo
        virtual ~Keyword();
};
class ArchivoKeyword{
private:
    char _nombre[30];
public:
    ArchivoKeyword(const char *n);
    Keyword leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Keyword reg);

};

#endif // KEYWORD_H
