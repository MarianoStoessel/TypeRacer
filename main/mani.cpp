#include "librariesMain.h"

/// MAIN PRINCIPAL
/*
int main()
{
    Aplicacion();
    return 0;
}
*/

/// MAIN DE PRUEBAS - MECANICA PRINCIPAL DEL JUEGO

int main()
{
    Keyword aux("hola mundo");
    Gameplay prueba;

    //revision del valor de la variable palabra
    cout << "- PALABRA:    " <<aux.getP() << endl;
    cout << "- CARACTERES: " <<aux.getTam()-1 << endl;
    cout << endl;
    cout << "ESCRIBA CORRECTAMENTE LA PALABRA VISTA ANTERIORMENTE:\n";
    cout << endl;

    //revision de la funcion de la clase gameplay
    prueba.compararKeyWord(aux);

    system("pause");
    return 0;
}
