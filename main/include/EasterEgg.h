#ifndef EASTEREGG_H
#define EASTEREGG_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class StateEasterEgg {Idle, View};

class EasterEgg: public sf::Drawable
{
   private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    float _frame=0;

    bool _pos = false;
    StateEasterEgg _state;
public:
    EasterEgg();

    void setPosicion(bool pos);

    bool getPosicion();
    sf::Sprite getSprite();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // EASTEREGG_H
