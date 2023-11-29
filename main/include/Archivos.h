#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <cstring>

class Archivos
{
    private:
    char _keyword[35];

public:
    void setKeyword(const char *k);
    const char *getKeyword();

    void Cargar();
    void Mostrar();

    void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=std::cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
};

#endif // ARCHIVOS_H
