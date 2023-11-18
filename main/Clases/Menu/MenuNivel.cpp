#include "MenuNivel.h"

MenuNivel::MenuNivel()
{

}
MenuNivel::MenuNivel(float width, float height) //ctor
{
    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf")){
        cout <<"No existe la fuente";
    }

    //Volver
    _menu[0].setFont(_font);
    _menu[0].setFillColor(sf::Color::White);
    _menu[0].setString("Volver");
    _menu[0].setCharacterSize(50);
    _menu[0].setPosition(600,230);
    //Nivel 1
    _menu[1].setFont(_font);
    _menu[1].setFillColor(sf::Color::White);
    _menu[1].setString("Nivel 1");
    _menu[1].setCharacterSize(50);
    _menu[1].setPosition(600,290);
    //Nivel 2
    _menu[2].setFont(_font);
    _menu[2].setFillColor(sf::Color::White);
    _menu[2].setString("Nivel 2");
    _menu[2].setCharacterSize(50);
    _menu[2].setPosition(600,350);
    //Nivel 3
    _menu[3].setFont(_font);
    _menu[3].setFillColor(sf::Color::White);
    _menu[3].setString("Nivel 3");
    _menu[3].setCharacterSize(50);
    _menu[3].setPosition(600,410);

    _menuSelected = 0;
    _state = MenuNivelState::Idle;
}
void MenuNivel::cmd() //Cmd
{
    _state = MenuNivelState::Idle;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _state = MenuNivelState::Up;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _state = MenuNivelState::Down;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        _state = MenuNivelState::Select;
    }
}

void MenuNivel::update()
{
    _menu[_menuSelected].setFillColor(sf::Color::White); //Inicio
    switch(_state)
    {
    case MenuNivelState::Up:
        if(_clock.getElapsedTime().asMilliseconds() > 20)
        {
            _menuSelected--;
            if(_menuSelected < 0)
            {
                _menuSelected = 3;
            }
            _state = MenuNivelState::Idle;
        }
        _clock.restart();
        break;
    case MenuNivelState::Down:
        if(_clock.getElapsedTime().asMilliseconds() > 20)
        {
            _menuSelected++;
            if(_menuSelected > Max_menu-1)
            {
                _menuSelected = 0;
            }
            _state = MenuNivelState::Idle;
        }
        _clock.restart();
        break;
    }
    _menu[_menuSelected].setFillColor(sf::Color::Green); //Select
}

void MenuNivel::draw(sf::RenderWindow& window) //Draw Menu
{
    for (int i = 0; i< Max_menu; i++)
    {
        window.draw(_menu[i]);
    }
    window.draw(_sprite);
}

bool MenuNivel::getState()
{
    if(_state == MenuNivelState::Select)
    {
        return true;
    }
    return false;
}

int MenuNivel::getSelected()
{
    return _menuSelected;
}
MenuNivel::~MenuNivel()
{
    //dtor
}
