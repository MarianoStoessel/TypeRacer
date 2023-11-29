#include "librariesMain.h"

#include "ArchivosEditor.h"
#include "Archivos.h"


// MAIN PRINCIPAL
int main()
{
    srand((unsigned)time(0));
    Aplicacion(sf::Vector2u(1500,900));
    return 0;
}

/*int main()
{
    srand((unsigned)time(0));
    cout << "ARCHIVOS GUARDADOS, REVISE QUE ESTE TODO CORRECTO..." << endl << endl;

    ArchivosEditor archEditor("Archivos/nivel1.dat");
    int cantRegistros = archEditor.contarRegistros();

    Archivos * vec;
    if(cantRegistros > 0)
    {
        vec = new Archivos[cantRegistros];
        if(vec == NULL)
        {
            cout << "Error de asignacion de memoria.";
            return -1;
        }
        for(int i=0; i<cantRegistros; i++)
        {
            vec[i] = archEditor.leerRegistro(i);
            //vec[i].Mostrar();
            cout << vec[i].getKeyword() << endl;

            cout << endl;
        }
    }
    Keyword palabra;

    cout << endl;
    cout << palabra.getP();

    palabra.setP(vec[rand()%29].getKeyword());

    cout << endl;
    cout << palabra.getP();
    cout << endl;

    //delete vec;

    system("pause");

    return 0;
}*/
