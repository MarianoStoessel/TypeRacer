#include "Gameplay.h"
#include <iostream>
#include <conio.h>

Gameplay::Gameplay() //ctor
{
    _exitoPalabra = false;

}
Gameplay::Gameplay(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window)
{
    _window = window;
    _resolucion = resolucion;
    _nivel = nivel;

    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(resolucion->x, resolucion->y));
    sf::Texture menutextura;
    menutextura.loadFromFile("Imagenes/Escenario.jpg");
    fondo.setTexture(&menutextura);

    sf::Font font;
    sf::Text text;
    font.loadFromFile("Fuentes/Retro Gaming.ttf");

    Leo Pj;
    Anonymous Eny;
    Gusavirus Gus;
    Keyword palabra;

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

        //CMD
        Pj.cmd();
        Eny.cmd();
        Gus.cmd();
        if(Gus.getposx()==1000){Gus.setmuriendo();}
        //Update - Actualiza los estados del juego
        Pj.update();
        Eny.update();
        Gus.update();

        _window->clear();

        //Draw
        _window->draw(fondo);
        _window->draw(Pj);
        _window->draw(Eny);
        _window->draw(Gus);
        _window->draw(text);

        //Display - Flip
        _window->display();
    }
}
bool Gameplay::getGameOver()
{

}
int Gameplay::getLevelUp()
{
    return _nivel;
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
