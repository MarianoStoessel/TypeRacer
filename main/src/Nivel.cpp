#include "Nivel.h"

using namespace std;

Nivel::Nivel() //ctor
{

}
Nivel::Nivel(int nivel)
{
    _nivel = nivel;
    string strNivel = std::to_string(_nivel);

    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout <<"No existe la fuente";
    }
    //Nivel
    _nivNiv.setFont(_font);
    _nivNiv.setFillColor(sf::Color::Black);
    _nivNiv.setString(strNivel);
    _nivNiv.setCharacterSize(30);
    _nivNiv.setPosition(1187,771);
}
int Nivel::getnivel(){return _nivel;}
void Nivel::setnivel(int niv){_nivel=niv;}
void Nivel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_nivNiv, states);
}
Nivel::~Nivel() //dtor
{

}
