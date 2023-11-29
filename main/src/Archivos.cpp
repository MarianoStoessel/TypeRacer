#include<iostream>
#include "Archivos.h"

using namespace std;

void Archivos::setKeyword(const char *key)
{
    strcpy(_keyword, key);
}
const char *Archivos::getKeyword()
{
    return _keyword;
}
void Archivos::Cargar(){
    cout << "- Keyword: ";
    cargarCadena(_keyword,34);
    cout << endl;
}
void Archivos::Mostrar(){
    cout << "- Keyword: " << _keyword << endl;
}
