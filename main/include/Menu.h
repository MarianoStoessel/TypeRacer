#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include<iostream>
#define Max_menu 4
using namespace std;
using namespace sf;

class Menu
{
    public:
        Menu(float width, float height);

        void draw(RenderWindow& window);
        void MoveUp();
        void MoveDown();
        int MenuPressed(){
            return MenuSelected;
        }
        ~Menu();
    private:
        int MenuSelected;
        Font font;
        Text menu[Max_menu];

};
//Funciones menu
void Aplicacion();
#endif // MENU_H
