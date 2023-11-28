#include "Transicion.h"

using namespace std;

Transicion::Transicion() //ctor
{

}
Transicion::Transicion(int nivel, sf::RenderWindow* window)
{
    _window = window;
    string strNivel = std::to_string(nivel);

    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout <<"No existe la fuente";
    }
    _tranNiv.setFont(_font);
    _tranNiv.setFillColor(sf::Color::White);
    _tranNiv.setString("Nivel " + strNivel);
    _tranNiv.setCharacterSize(50);
    _tranNiv.setPosition(645,400);

    while(_window->isOpen())
    {
        if(_clock.getElapsedTime().asSeconds() > 2)
        {
            break;
        }
        _window->clear();

        //Draw
        _window->draw(_tranNiv);

        //Display - Flip
        _window->display();
    }
    cout << "Cambio de escena - Entrando al gameplay" << endl;
}

Transicion::~Transicion() //dtor
{

}
