#include "Gusavirus.h"

Gusavirus::Gusavirus()
{
    y=600;
    x=1200;
    _texture.loadFromFile("Imagenes/gusavirus.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(x,y);
    //ctor
}
void Gusavirus::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite,states);
}

void Gusavirus::update()
{
    if(x>278)
    _sprite.setPosition((x),(y));

    if(x<278){
        _sprite.setScale(0.5,0.5);
        _sprite.setPosition(x,y+40);
    }
    if(x>145){
        x-=1*_velocity;
    }
    if(x<=145 && y>=360){
        y-=1*(_velocity-3);
        _sprite.setRotation(90);
        _sprite.setPosition(x+40,y+40);
    }
    if(y<360){
        _sprite.setPosition(x+40,y+40);
    }

}
