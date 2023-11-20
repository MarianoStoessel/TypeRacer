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
    Menu menu(_window.getSize().x, _window.getSize().y);

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
                if(menu.getState())
                {
                    int x = menu.getSelected();

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

                                        if(y == 0)
                                        {
                                            closeMenuNivel = true;
                                            break;
                                        }
                                        else
                                        {
                                            Gameplay gameplay(resolucion, *_window, nivel);
                                            if(gamePlay.getGameOver())
                                            {
                                                salirAlMenu=true;
                                            }
                                            if(gamePlay.getLevelUp()==true)
                                            {
                                                nivel++;
                                            }
                                        }





                                        ///CREAR PANTALLA TRANSICION

                                        ///CREAR CLASE NIVEL

                                        niv.cargarNivel(y); ///CREAR CLASE NIVEL PARA SUBIR ESCENARIOS

                                        /*                                      switch(y)
                                                                                {
                                                                                case 0: //Volver
                                                                                    closeMenuNivel = true;
                                                                                    break;
                                                                                case 1: //Niveles
                                                                                {
                                                                                    sf::RectangleShape fondo;
                                                                                    fondo.setSize(sf::Vector2f(1500,900));
                                                                                    sf::Texture menutextura;
                                                                                    menutextura.loadFromFile("Imagenes/Escenario.jpg");
                                                                                    fondo.setTexture(&menutextura);
                                                                                    sf::Font font;
                                                                                    sf::Text text;
                                                                                    font.loadFromFile("Fuentes/Retro Gaming.ttf");
                                                                                    Leo Pj;
                                                                                    Anonymous Eny;
                                                                                    Gusavirus Gus;
                                                                                    Keyword palabra;
                                                                                    text.setFont(font);
                                                                                    text.setFillColor(sf::Color::White);
                                                                                    text.setString(palabra.getP());
                                                                                    text.setCharacterSize(15);
                                                                                    text.setPosition(Gus.getposx(),Gus.getposy());

                                                                                    //Game Loop
                                                                                    while(_window.isOpen())
                                                                                    {
                                                                                        sf::Event event;
                                                                                        while(_window.pollEvent(event))
                                                                                        {
                                                                                            if(event.type == sf::Event::Closed)
                                                                                                _window.close();
                                                                                        }
                                                                                        text.setPosition(Gus.getposx(),Gus.getposy());

                                                                                        //CMD
                                                                                        Pj.cmd();
                                                                                        Eny.cmd();

                                                                                        //Update - Actualiza los estados del juego
                                                                                        Pj.update();
                                                                                        Eny.update();
                                                                                        Gus.update();

                                                                                        _window.clear();

                                                                                        //Draw
                                                                                        _window.draw(fondo);
                                                                                        _window.draw(Pj);
                                                                                        _window.draw(Eny);
                                                                                        _window.draw(Gus);
                                                                                        _window.draw(text);

                                                                                        //Display - Flip
                                                                                        _window.display();
                                                                                    }
                                                                                }
                                                                                break;
                                                                                case 2:
                                                                                    break;
                                                                                case 3:
                                                                                    break;
                                                                                }
                                        */
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
        menu.cmd();

        //Update - Actualiza los estados del juego
        menu.update();

        _window.clear();

        //Draw
        _window.draw(fondo);
        menu.draw(_window);

        //Display - Flip
        _window.display();
    }
}
Aplicacion::~Aplicacion() //dtor
{

}
