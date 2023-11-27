#include "Gameplay.h"
#include <iostream>
#include <conio.h>
//Constructor
Gameplay::Gameplay(){_exitoPalabra = false;}

//Constructor 2
Gameplay::Gameplay(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window)
{
    _window = window;
    _resolucion = resolucion;
    _nivel = nivel;
    //int cantenem = 0;
    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(resolucion->x, resolucion->y));
    sf::Texture menutextura;
    menutextura.loadFromFile("Imagenes/Escenario.jpg");
    fondo.setTexture(&menutextura);

    sf::Font font;
    sf::Text text;
    font.loadFromFile("Fuentes/Retro Gaming.ttf");

    //llamo clases
    Nivel Niv(_nivel);
    Score Sco;
    Vida Vid;
    Leo Pj;
    Anonymous Eny;
    Gusavirus Gus;
    Keyword palabra;

    //muestro palabra por pantalla
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setString(palabra.getP());
    text.setCharacterSize(15);
    text.setPosition(Gus.getposx(),Gus.getposy());

    //Game Loop
    while(_window->isOpen())
    {
        sf::Event event;
        while(_window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                _window->close();
        }

        text.setPosition(Gus.getposx(),Gus.getposy());

        if(Gus.getposx()==1300){Gus.setmuriendo();text.setString("");}
        if(Gus.getmurio()==true){Gus.respawn();text.setPosition(Gus.getposx(),Gus.getposy());text.setString("Hola");}

        //CMD
        Pj.cmd();
        Eny.cmd();
        Gus.cmd();

        //Update - Actualiza los estados del juego
        Sco.update();
        Vid.update();
        Pj.update();
        Eny.update();
        Gus.update();

        _window->clear();

        //Draw
        _window->draw(fondo);
        _window->draw(Niv);
        _window->draw(Sco);
        _window->draw(Vid);
        _window->draw(Pj);
        _window->draw(Eny);
        _window->draw(Gus);
        _window->draw(text);

        //Display - Flip
        _window->display();
    }
}
void Gameplay::compararKeyWord(Keyword kw)
{
    //forma de aplicar la mecanica

    while(!_exitoPalabra)
    {

        bool verifica = true;
        char caracter;
        int auxTam = 0;

        while(verifica && auxTam < kw.getTam()-1)
        {
            caracter = getch();
            std::cout << caracter;

            int comparacion = kw.getP()[auxTam] - caracter;
            if(comparacion != 0)
            {
                verifica = false;
            }
            auxTam++;
        }
        std::cout << std::endl << std::endl;

        if(!verifica)
        {
            std::cout << "VUELVE A INTENTARLO \n";
            std::cout << std::endl;
        }
        else
        {
            _exitoPalabra = 1;
            std::cout<< "EXCELENTE \n\n";
        }
    }
}
void Gameplay::logicajuego(){ ///Maneja la logica del juego
        /*
        //respaw si muere;
        if(compararKeyWord()==true){Gus.setmuriendo();score+=100;}
        //si murio respawnea
        if(Gus[cantenem].getmurio()==true && Gus[cantenem-1]){Gus[cantenem].respawn(); palabra[cantenem].reasignaP();}//codear la funcion respawn
        //si llega a x punto aparece 1 enemigo mas
        if(Gus[cantenem].getposx()==900){Gus[cantenem+1];palabra[cantenem+1].reasignaP();}
        //si gusavirus llega a leo baja vida y respawn
        if(Gus[cantenem].getposy()== 330){vida--;Gus[cantenem].respawn();palabra[cantenem]reasignaP()}//330=posy de leo
        //si leo erra palabra le incrementa la velocidad al gusano
        //si leo junta 1000puntos termina nivel
        if(score==1000){nivel.sumarnivel();}/*si sube de nivel tiene q haber transicion y mueren todos los gusanos en
                                            pantalla*/
        /*
        //si vidas=0 leo muere y gameover
        if(vida==0){gameover}
        //si toca la puerta aparece foto de braian diciendo tremendo
        */
        /*funcion que restree donde se hace click si es en la parte de la puerta aparece*/
}

/*void Gameplay::Renderizar()///En esta funcion van todos los draws
{
    _window->clear();

    //Draw
    _window->draw(fondo);
    _window->draw(Pj);
    _window->draw(Eny);
    for(int i=0;i<canE;i++)
        {
            _window->draw(Gus[i]);

        }
    _window->draw(text);

    //Display - Flip
    _window->display();
}*/
