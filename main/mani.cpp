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
/*
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
*/

/// MAIN PRUEBAS - LEO SPRITE
int main(){
    //Inicializacion programa
    sf::RenderWindow window(sf::VideoMode(1500, 900), "LEO PRUEBA");
    window.setFramerateLimit(60);

    //set fondo
    RectangleShape fondo;
    fondo.setSize(Vector2f(1500,900));
    Texture menutextura;
    menutextura.loadFromFile("Imagenes/Escenario.jpg");
    fondo.setTexture(&menutextura);

    Leo Pj;

    //Game Loop (update del juego

    while(window.isOpen())
    {
        //ReadInput - Actualizar los estados de los perisfericos de entrada
        //Leer la cola de mensajes
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        //CMD - Joy
        Pj.cmd();

        //Update - Actualiza los estados del juego
        Pj.update();

        window.clear();

        //Draw
        window.draw(fondo);
        window.draw(Pj);

        //Display - Flip
        window.display();
    }

    //Liberacion programa

    return 0;
}
