#include "MenuNivel.h"

MenuNivel::MenuNivel(float width, float height) //ctor
{
    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf")){
        cout <<"No existe la fuente";
    }

    //Volver
    _menu[0].setFont(_font);
    _menu[0].setFillColor(Color::White);
    _menu[0].setString("Volver");
    _menu[0].setCharacterSize(50);
    _menu[0].setPosition(600,230);
    //Nivel 1
    _menu[1].setFont(_font);
    _menu[1].setFillColor(Color::White);
    _menu[1].setString("Nivel 1");
    _menu[1].setCharacterSize(50);
    _menu[1].setPosition(600,290);
    //Nivel 2
    _menu[2].setFont(_font);
    _menu[2].setFillColor(Color::White);
    _menu[2].setString("Nivel 2");
    _menu[2].setCharacterSize(50);
    _menu[2].setPosition(600,350);
    //Nivel 3
    _menu[3].setFont(_font);
    _menu[3].setFillColor(Color::White);
    _menu[3].setString("Nivel 3");
    _menu[3].setCharacterSize(50);
    _menu[3].setPosition(600,410);

    _MenuSelected=-1;
}
void MenuNivel::draw(RenderWindow& window)
{
    for (int i = 0; i< Max_menu; i++)
    {
        window.draw(_menu[i]);
    }
}

MenuNivel::~MenuNivel()
{
    //dtor
}
