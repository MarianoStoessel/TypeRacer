#include "Keyword.h"
#include<iostream>
#include<cstring>
#include<conio.h>
#include <locale.h>
//constructor
Keyword::Keyword(){}
Keyword::Keyword(int niv)
{
    _nivel.setnivel(niv);

    if(niv==1){strcpy( _nombre , "Nivel1" );}
    if(niv==2){strcpy( _nombre , "Nivel2" );}
    if(niv==3){strcpy( _nombre , "Nivel3" );}
    if(niv==4){strcpy( _nombre , "Nivel4" );}
    if(niv==5){strcpy( _nombre , "Nivel5" );}
    if(niv==6){strcpy( _nombre , "Nivel6" );}
    if(niv==7){strcpy( _nombre , "Nivel7" );}
    if(niv==8){strcpy( _nombre , "Nivel8" );}
    if(niv==9){strcpy( _nombre , "Nivel9" );}

    ArchivoKeyword archi(_nombre);

    /*_tam = strlen(ini)+1;
    _p = new char [_tam];
    if(_p == NULL){
        std::cout << "ERROR DE ASIGNACION DE MEMORIA" << std::endl;
        exit(1);
    }
    strcpy(_p, ini);
    _p[_tam-1] = '\0';*/
}

//getters
const char *Keyword::getP()
{
    return _keyword;
}
int Keyword::getTam()
{
    return _tam;
}

//setters
void Keyword::setP(const char *p)
{
    strcpy(_keyword, p);
}

//desstructor
Keyword::~Keyword()
{
    delete _keyword;
}

                ///CLASE ARCHIVOS
    ArchivoKeyword::ArchivoKeyword(const char *n){
        strcpy(_nombre, n);
    }

    Keyword ArchivoKeyword::leerRegistro(int pos){
        Keyword reg();
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    int ArchivoKeyword::contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Keyword);
    }

    bool ArchivoKeyword::grabarRegistro(Keyword reg){
        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};
