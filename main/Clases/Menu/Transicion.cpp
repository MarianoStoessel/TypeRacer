#include "Transicion.h"

using namespace std;

Transicion::Transicion() //ctor
{

}
Transicion::Transicion(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window)
{
    nivel = 0;
    _window = window;
    string strNivel = std::to_string(nivel);

    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout <<"No existe la fuente";
    }
    //set fondo
    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(resolucion->x, resolucion->y));
    sf::Texture menutextura;
    menutextura.loadFromFile("Imagenes/Escenario.jpg");
    fondo.setTexture(&menutextura);

    //Transicion dependiendo del retorno de gameplay
    if(nivel <= 0)
    {
        _tranNiv.setFont(_font);
        _tranNiv.setFillColor(sf::Color::White);
        _tranNiv.setString("Perdiste");
        _tranNiv.setCharacterSize(75);
        _tranNiv.setPosition(530,250);
    }
    else if(nivel <= 9)
    {
        _tranNiv.setFont(_font);
        _tranNiv.setFillColor(sf::Color::White);
        _tranNiv.setString("Nivel " + strNivel);
        _tranNiv.setCharacterSize(75);
        _tranNiv.setPosition(580,250);
    }
    else
    {
        _tranNiv.setFont(_font);
        _tranNiv.setFillColor(sf::Color::White);
        _tranNiv.setString("Ganaste");
        _tranNiv.setCharacterSize(150);
        _tranNiv.setPosition(350,300);
    }

    while(_window->isOpen())
    {
        if(_clock.getElapsedTime().asSeconds() > 2)
        {
            break;
        }
        _window->clear();

        //Draw
        _window->draw(fondo);
        _window->draw(_tranNiv);

        //Display - Flip
        _window->display();
    }
    cout << "Cambio de escena - Entrando al gameplay" << endl;
}
Transicion::~Transicion() //dtor
{

}
