#include "Aplicacion.h"

Aplicacion::Aplicacion(sf::Vector2u resolucion) // ctor
{
    //Inicializacion programa
    sf::RenderWindow _window(sf::VideoMode(resolucion.x,resolucion.y), "TYPERACER", sf::Style::Default);
    _window.setFramerateLimit(60);

    //set fondo
    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(resolucion.x,resolucion.y));
    sf::Texture menuTexture;
    menuTexture.loadFromFile("Imagenes/FondoMain.jpg");
    fondo.setTexture(&menuTexture);

    //inicializar menu
    Menu _menu(_window.getSize().x, _window.getSize().y);

    //Game Loop (update del juego)
    while(_window.isOpen())
    {
        while(_window.pollEvent(_event))
        {
            if(_event.type == sf::Event::Closed)
            {
                _window.close();
            }
            if(_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Enter)
            {
                if(_menu.getState())
                {
                    int x = _menu.getSelected();

                    switch(x)
                    {
                    case 0:  //Jugar
                    {
                        //set fondo
                        sf::RectangleShape fondo;
                        fondo.setSize(sf::Vector2f(resolucion.x,resolucion.y));
                        sf::Texture menuTexture;
                        menuTexture.loadFromFile("Imagenes/FondoMain.jpg");
                        fondo.setTexture(&menuTexture);

                        //inicializar menu Niveles
                        MenuNivel _menuNivel(_window.getSize().x, _window.getSize().y);
                        bool closeMenuNivel = false;

                        while(_window.isOpen())
                        {

                            sf::Event event2;
                            while(_window.pollEvent(event2))
                            {
                                if(event2.type == sf::Event::Closed)
                                {
                                    _window.close();
                                }
                                if(event2.type == sf::Event::KeyReleased && event2.key.code == sf::Keyboard::Enter)
                                {
                                    if(_menuNivel.getState())
                                    {
                                        int y = _menuNivel.getSelected();

                                        switch(y)
                                        {
                                        case 0:
                                            closeMenuNivel = true;
                                            break;
                                        case 1:

                                            break;
                                        case 2:
                                            break;
                                        case 3:
                                            break;
                                        }
                                    }
                                }
                            }
                            if(closeMenuNivel)
                            {
                                break;
                            }

                            _menuNivel.cmd();
                            _menuNivel.update();

                            _window.clear();

                            _window.draw(fondo);
                            _menuNivel.draw(_window);

                            _window.display();
                        }

                    }
                    break;
                    case 1: //Como Jugar

                        break;
                    case 2: //Nosotros

                        break;
                    case 3: //Salir
                        _window.close();
                        break;
                    }
                }
            }
        }
        //CMD - Joy
        _menu.cmd();

        //Update - Actualiza los estados del juego
        _menu.update();

        _window.clear();

        //Draw
        _window.draw(fondo);
        _menu.draw(_window);

        //Display - Flip
        _window.display();
    }
}
Aplicacion::~Aplicacion() //dtor
{

}

/*
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
                   RenderWindow Play(VideoMode(1500, 900),"JUGAR");
                   RenderWindow ComoJugar(VideoMode(1500, 900),"COMO JUGAR");
                   RenderWindow SobreNosotros(VideoMode(1500, 900),"Sobre Nostros");
                   RenderWindow Salir(VideoMode(1500, 900),"SALIR");
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

       //Draw
       MENU.draw(fondo);
       menuprincipal.draw(MENU);


       //Display - Flip
       MENU.display();
    }

}*/

/* //Inicializacion programa
                sf::RenderWindow Escenario(sf::VideoMode(1500, 900), "LEO PRUEBA");
                Escenario.setFramerateLimit(60);

                //set fondo
                sf::RectangleShape fondo;
                fondo.setSize(sf::Vector2f(1500,900));
                sf::Texture menutextura;
                menutextura.loadFromFile("Imagenes/Escenario.jpg");
                fondo.setTexture(&menutextura);

                Leo Pj;
                Anonymous Eny;
                Gusavirus Gus;

                //Game Loop (update del juego

                while(Escenario.isOpen())
                {
                    //ReadInput - Actualizar los estados de los perisfericos de entrada
                    //Leer la cola de mensajes
                    sf::Event event;
                    while(Escenario.pollEvent(event))
                    {
                        if(event.type == sf::Event::Closed)
                            Escenario.close();
                    }

                    //CMD - Joy
                    Pj.cmd();
                    Eny.cmd();

                    //Update - Actualiza los estados del juego
                    Pj.update();
                    Eny.update();
                    Gus.update();

                    Escenario.clear();

                    //Draw
                    Escenario.draw(fondo);
                    Escenario.draw(Pj);
                    Escenario.draw(Eny);
                    Escenario.draw(Gus);

                    //Display - Flip
                    Escenario.display();
                } */


