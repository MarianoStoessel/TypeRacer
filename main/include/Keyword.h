#pragma once
#ifndef KEYWORD_H
#define KEYWORD_H
#include <SFML/Graphics.hpp>
class Keyword
{
    private:
        char *_p;
        int _tam;
        sf::Text text;
        sf::Font font;

    public:
        Keyword(const char *ini = "En tu cara kloster");
        const char *getP();
        int getTam();
        void draw(sf::RenderWindow& window);
        void setP(const char *p);

        virtual ~Keyword();
};

#endif // KEYWORD_H
