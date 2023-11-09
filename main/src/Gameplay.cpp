#include "Gameplay.h"
#include <iostream>
#include <conio.h>

Gameplay::Gameplay() //ctor
{
    _exito = false;

}

void Gameplay::compararKeyWord(Keyword kw)
{
    //forma de aplicar la mecanica

	while(!_exito){

	    bool verifica = true;
        char caracter;
        int auxTam = 0;

        while(verifica && auxTam < kw.getTam()-1){
            caracter = getch();
            std::cout << caracter;

            int comparacion = kw.getP()[auxTam] - caracter;
            if(comparacion != 0){
                verifica = false;
            }
            auxTam++;
        }
        std::cout << std::endl << std::endl;

        if(!verifica){
            std::cout << "VUELVE A INTENTARLO \n";
            std::cout << std::endl;
        }
        else {
            _exito = 1;
            std::cout<< "EXCELENTE \n\n";
        }
	}
}
