#include "Menu.h"

Menu::Menu(float width, float height){
    if(!font.loadFromFile("Fuentes/Retro Gaming.ttf")){
        cout <<"No existe la fuente";
    }

    //Jugar
    menu[0].setFont(font);
    menu[0].setFillColor(Color::Green);
    menu[0].setString("Jugar");
    menu[0].setCharacterSize(70);
    menu[0].setPosition(300,200);
    //Como jugar
    menu[1].setFont(font);
    menu[1].setFillColor(Color::Green);
    menu[1].setString("Como Jugar");
    menu[1].setCharacterSize(70);
    menu[1].setPosition(300,300);
    //Sobre nosotros
    menu[2].setFont(font);
    menu[2].setFillColor(Color::Green);
    menu[2].setString("Sobre Nostros");
    menu[2].setCharacterSize(70);
    menu[2].setPosition(300,400);
    //Salir
    menu[3].setFont(font);
    menu[3].setFillColor(Color::Green);
    menu[3].setString("Salir");
    menu[3].setCharacterSize(70);
    menu[3].setPosition(300,500);

    MenuSelected=-1;
}
Menu::~Menu()
{

}
//Draw Menu
void Menu::draw(RenderWindow& window){
    for (int i = 0; i< Max_menu; i++){
        window.draw(menu[i]);
    }
}
//Move up
void Menu::MoveUp(){
    if(MenuSelected -1 >= 0){
        menu[MenuSelected].setFillColor(Color::Green);
        MenuSelected--;
        if(MenuSelected == -1){
            MenuSelected = 3;
        }
        menu[MenuSelected].setFillColor(Color::White);
    }
}

//Move down
void Menu::MoveDown(){
    if(MenuSelected + 1 <= Max_menu){
        menu[MenuSelected].setFillColor(Color::Green);;
        MenuSelected++;
        if(MenuSelected == 4){
            MenuSelected = 0;
        }
        menu[MenuSelected].setFillColor(Color::White);
    }

}

void Aplicacion(){
//Inicializa el programa
    RenderWindow MENU(VideoMode(1500, 900), "TYPERACER", Style::Default);
    Menu menuprincipal(MENU.getSize().x,MENU.getSize().y);
    //Game Loop
    while (MENU.isOpen())
    {
       Event event;
       while(MENU.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                MENU.close();
            }
            if(event.type == Event::KeyReleased)
            {
                if(event.key.code == Keyboard::Up)
                {
                   menuprincipal.MoveUp();
                   break;
                }
                 if(event.key.code == Keyboard::Down)
                {
                   menuprincipal.MoveDown();
                   break;
                }
                 if(event.key.code == Keyboard::Return)
                {
                   RenderWindow Play(VideoMode(920,720),"JUGAR");
                   RenderWindow ComoJugar(VideoMode(920,720),"COMO JUGAR");
                   RenderWindow SobreNosotros(VideoMode(920,720),"Sobre Nostros");
                   RenderWindow Salir(VideoMode(920,720),"SALIR");
                   int x = menuprincipal.MenuPressed();

                   if (x == 0)
                   {
                       while(Play.isOpen())
                        {
                        Event aevent;
                        while(Play.pollEvent(aevent)){
                            if(aevent.type == Event::Closed)
                                {
                                Play.close();
                                }
                            if (aevent.type == Event::KeyPressed)
                            {
                              if(aevent.key.code == Keyboard::Escape)
                              {
                                Play.close();
                              }
                            }
                        }
                       ComoJugar.close();
                       SobreNosotros.close();
                       Salir.close();
                       Play.clear();
                       Play.display();
                       }
                   }
                    if (x == 1)
                   {
                       while(ComoJugar.isOpen())
                        {
                        Event aevent;
                        while(ComoJugar.pollEvent(aevent)){
                            if(aevent.type == Event::Closed)
                                {
                                ComoJugar.close();
                                }
                            if (aevent.type == Event::KeyPressed)
                            {
                              if(aevent.key.code == Keyboard::Escape)
                              {
                                ComoJugar.close();
                              }
                            }
                        }
                       Play.close();
                       SobreNosotros.close();
                       Salir.close();
                       ComoJugar.clear();
                       ComoJugar.display();
                       }
                   }
                    if (x == 2)
                   {
                       while(SobreNosotros.isOpen())
                        {
                        Event aevent;
                        while(SobreNosotros.pollEvent(aevent)){
                            if(aevent.type == Event::Closed)
                                {
                                Play.close();
                                }
                            if (aevent.type == Event::KeyPressed)
                            {
                              if(aevent.key.code == Keyboard::Escape)
                              {
                                SobreNosotros.close();
                              }
                            }
                        }
                       Play.close();
                       ComoJugar.close();
                       Salir.close();
                       SobreNosotros.clear();
                       SobreNosotros.display();
                       }
                   }
                    if (x == 3)
                   {
                      MENU.close();
                      break;
                   }
                }
            }
       }
       MENU.clear();
       menuprincipal.draw(MENU);
       MENU.display();
    }

}

