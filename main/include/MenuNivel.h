#ifndef MENUNIVEL_H
#define MENUNIVEL_H
#define Max_menu 4

#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum class MenuNivelState{Idle, Up, Down, Select};

class MenuNivel //Rehacer
{
    private:
        sf::Font _font;
        sf::Text _menu[Max_menu];
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Clock _clock;

        int _menuSelected;
        MenuNivelState _state;

    public:
        MenuNivel();
        MenuNivel(float width, float height);
        void cmd();
        void update();
        void draw(sf::RenderWindow& window);

        int getSelected();
        bool getState();

        ~MenuNivel();
};

#endif // MENUNIVEL_H
