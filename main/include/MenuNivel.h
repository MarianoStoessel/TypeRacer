#ifndef MENUNIVEL_H
#define MENUNIVEL_H

#include <SFML/Graphics.hpp>
#include<iostream>
#define Max_menu 4
#include "Menu.h"

using namespace std;
using namespace sf;

class MenuNivel: public Menu //Rehacer
{
    private:
        int _MenuSelected;
        Font _font;
        Text _menu[Max_menu];

    public:
        MenuNivel(float width, float height);
        void draw(RenderWindow& window);

        ~MenuNivel();
};

#endif // MENUNIVEL_H
