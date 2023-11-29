#include "Gameplay.h"
#include <iostream>
using namespace std;

//Constructor
Gameplay::Gameplay() {}

//Constructor 2
Gameplay::Gameplay(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window)
{
    _window = window;
    _resolucion = resolucion;
    _nivel = nivel;

    //int cantenem = 0;

    //set fondo
    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(resolucion->x, resolucion->y));
    sf::Texture menutextura;
    menutextura.loadFromFile("Imagenes/Escenario.jpg");
    fondo.setTexture(&menutextura);

    //set rectangulo Negro
    sf::RectangleShape rectangulo(sf::Vector2f(76, 76));
    rectangulo.setFillColor(sf::Color::Black);
    rectangulo.setPosition(202, 600);

    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout << "No existe la fuente";
    }
    //TextoPantalla
    _textPan.setFont(_font);
    _textPan.setFillColor(sf::Color::Black);
    _textPan.setCharacterSize(30);
    _textPan.setPosition(241,747);

    //llamo clases
    Nivel Niv(_nivel);
    Leo Pj;
    Anonymous Eny;
    Gusavirus Gus;
    Keyword palabra;
    Score Sco;
    Vida Vid;

    //Archivo de Keywords
    ArchivosEditor archEditor("Archivos/nivel9.dat");
    int cantRegistros = archEditor.contarRegistros();

    Archivos vec[30];
    if(cantRegistros > 0)
    {
        for(int i=0; i<30; i++)
        {
            vec[i] = archEditor.leerRegistro(i);
            cout << vec[i].getKeyword() << endl;
        }
    }

    //muestro palabra Gusavirus por pantalla
    sf::Text text;
    palabra.setP(vec[rand()%29].getKeyword());

    text.setFont(_font);
    text.setFillColor(sf::Color::White);
    text.setString(palabra.getP());
    text.setCharacterSize(15);
    text.setPosition(Gus.getposx(),Gus.getposy());

    cout << palabra.getP(); //Keyword del Gusavirus
    cout << endl;

    //Game Loop
    while(_window->isOpen())
    {
        sf::Event event;
        while(_window->pollEvent(event))
        {
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == 8 || event.text.unicode == 13 || event.text.unicode == 27) // Backspace, Enter y Escape
                {
                    //Se puede agregar restricciones o no
                }
                else if (event.text.unicode < 128)
                {

                    //Agregar caracter
                    _textoPantalla = _textPan.getString();
                    _textoPantalla += static_cast<char>(event.text.unicode);
                    _textPan.setString(_textoPantalla);

                    //Comparacion - Mecanica principal del juego
                    if(verifica && auxTam < palabra.getTam()-1)
                    {
                        _caracter = static_cast<char>(event.text.unicode);
                        cout << _caracter;

                        int comparacion = palabra.getP()[auxTam] - _caracter;
                        if(comparacion != 0)
                        {
                            verifica = false;
                            _textPan.setString("");
                            _caracter = 0;
                            auxTam = 0;
                        }
                        else
                        {
                            auxTam++;
                        }
                    }
                    if(!verifica)
                    {
                        cout << endl;
                        cout << "VUELVE A INTENTARLO... \n"; //Agregar en pantalla de juego
                        verifica = true;

                        _textPan2.setFont(_font);
                        _textPan2.setFillColor(sf::Color::Black);
                        _textPan2.setString("Error al ingresar datos...");
                        _textPan2.setCharacterSize(36);
                        _textPan2.setPosition(32,827);
                    }
                    else
                    {
                        verifica = true;
                    }
                    if(verifica && auxTam == palabra.getTam()-1)
                    {
                        cout << endl;
                        cout << "VIRUS HECHO PELOTA" << endl;

                        _textPan2.setFont(_font);
                        _textPan2.setFillColor(sf::Color::Black);
                        if(_clock2.getElapsedTime().asSeconds() > 2)
                        {
                            _textPan2.setString("Datos correctamente ingresados...");
                        }
                        _textPan2.setCharacterSize(36);
                        _textPan2.setPosition(32,827);

                        _textPan.setString("");
                        _caracter = 0;
                        auxTam = 0;
                        Gus.setmuriendo();
                        Sco.sumarScore();
                    }
                }
            }
            if(event.type == sf::Event::Closed)
                _window->close();
        }
        text.setPosition(Gus.getposx(),Gus.getposy());

        if(Gus.getposy() == 360 )
        {
            Gus.setposy(1500);
            cout<<"ee"<<endl;
            Gus.setmuriendo();
            text.setString("");


            for(int i=0; i<=3; i++)
            {
                if(Vid.getVida() == i)
                {
                    Vid.setVIda(i-1);
                    Pj.setGolpe(true);
                    _clock.restart();

                    if(Vid.getVida() == 0)
                    {
                        Pj.setMuriendo(true);
                    }
                }
            }
        }
        if(_clock.getElapsedTime().asSeconds() > 2 && Pj.getGolpe() == true)
        {
            Pj.setGolpe(false);
        }
        if(Gus.getmurio()==true)
        {
            Gus.respawn();
            palabra.setP(vec[rand()%29].getKeyword());
            text.setPosition(Gus.getposx(),Gus.getposy());
            text.setString(palabra.getP());
        }
        //CMD
        Pj.cmd();
        Eny.cmd();
        Gus.cmd();

        //Update - Actualiza los estados del juego
        Pj.update();
        Eny.update();
        Gus.update();
        Vid.update();

        _window->clear();

        //Draw
        _window->draw(fondo);
        _window->draw(Niv);
        _window->draw(Sco);
        _window->draw(Vid);
        _window->draw(Pj);
        _window->draw(Eny);
        _window->draw(Gus);
        _window->draw(rectangulo);
        _window->draw(text);
        _window->draw(_textPan);
        _window->draw(_textPan2);

        //Display - Flip
        _window->display();
    }
}
/*void Gameplay::compararKeyWord(Keyword* kw)
{
    Keyword* keyword = kw;
    thread t([this, keyword]()
    {
        cout << keyword->getP(); //Keyword del Gusavirus
        cout << endl;

        while(!_exitoPalabra) //forma de aplicar la mecanica
        {
            cout << "A" << endl;
            bool verifica = true;
            int auxTam = 0;

            while(verifica && auxTam < keyword->getTam()-1)
            {
                cout << "A" << endl;
                cout << _caracter << endl;

                _caracter = getch();
                std::cout << _caracter;

                int comparacion = keyword->getP()[auxTam] - _caracter;
                if(comparacion != 0)
                {
                    verifica = false;
                    _caracter = NULL;
                }
                auxTam++;
            }
            std::cout << std::endl << std::endl;

            if(!verifica)
            {
                std::cout << "VUELVE A INTENTARLO \n";
                std::cout << std::endl;
            }
            else
            {
                _exitoPalabra = 1;
                std::cout<< "EXCELENTE \n\n";
            }
        }
    });
    t.detach();
}*/
void Gameplay::logicajuego()  ///Maneja la logica del juego
{
    /*
    //respaw si muere;
    if(compararKeyWord()==true){Gus.setmuriendo();score+=100;}
    //si murio respawnea
    if(Gus[cantenem].getmurio()==true && Gus[cantenem-1]){Gus[cantenem].respawn(); palabra[cantenem].reasignaP();}//codear la funcion respawn
    //si llega a x punto aparece 1 enemigo mas
    if(Gus[cantenem].getposx()==900){Gus[cantenem+1];palabra[cantenem+1].reasignaP();}
    //si gusavirus llega a leo baja vida y respawn
    if(Gus[cantenem].getposy()== 330){vida--;Gus[cantenem].respawn();palabra[cantenem]reasignaP()}//330=posy de leo
    //si leo erra palabra le incrementa la velocidad al gusano
    //si leo junta 1000puntos termina nivel
    if(score==1000){nivel.sumarnivel();}/*si sube de nivel tiene q haber transicion y mueren todos los gusanos en
                                        pantalla*/
    /*
    //si vidas=0 leo muere y gameover
    if(vida==0){gameover}
    //si toca la puerta aparece foto de braian diciendo tremendo
    */
    /*funcion que restree donde se hace click si es en la parte de la puerta aparece*/
}

/*void Gameplay::Renderizar()///En esta funcion van todos los draws
{
    _window->clear();

    //Draw
    _window->draw(fondo);
    _window->draw(Pj);
    _window->draw(Eny);
    for(int i=0;i<canE;i++)
        {
            _window->draw(Gus[i]);

        }
    _window->draw(text);

    //Display - Flip
    _window->display();
}*/
