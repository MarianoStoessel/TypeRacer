#include "Gusavirus.h"

Gusavirus::Gusavirus() //ctor
{
    _frame=0;
    y=615;
    x=1200;
    SeeligeColor();

    _texture.loadFromFile("Imagenes/gusavirus.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({430,_color,108,65});
    _sprite.setPosition(x,y);
}
bool Gusavirus::setmurio(){
    murio=true;
}

bool Gusavirus::setmuriendo(){
    muriendo=true;
}

int Gusavirus::getposx(){
    return x;
}
int Gusavirus::getposy(){
    return y;
}
bool Gusavirus::getmurio(){
    return murio;
}

bool Gusavirus::getmuriendo(){
    return muriendo;
}
//cmd
void Gusavirus::cmd(){
    if(muriendo==true){
        _state = GusavirusState::Mueriendo;
        _frame=0;
    }
    if(murio==true){
        _state = GusavirusState::Muerto;
    }


}

void Gusavirus::update()
{
    switch (_state)
    {

    case GusavirusState::Vivo:

        _frame+=0.08;
        if(_frame>4){
            _frame=0;
        }
        _sprite.setTextureRect({440+int(_frame)*110,_color,108,62});
        if(x>278)
        _sprite.setPosition((x),(y));


        if(x<278){
            _sprite.setScale(0.3,0.3);
            _sprite.setPosition(x,y+40);
        }
        if(x>145){
            x-=1*_velocity;
        }
        if(x<=145 && y>=360){
            y-=1*(_velocity-(_velocity*0.5));
            _sprite.setRotation(90);
            _sprite.setPosition(x+20,y+20);
        }
        if(y<360){
            _sprite.setPosition(x+25,y+40);
        }

        break;

        case GusavirusState::Mueriendo:
            _frame+=0.10;
            _sprite.setTextureRect({895+int(_frame)*92,_color,92,62});
            if(_frame==4)murio=true;

        break;
        case GusavirusState::Muerto:
        break;
    }

}
void Gusavirus::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite,states);
}

void Gusavirus::SeeligeColor(){
    int tam;
    int vec[7]={8,78,148,221,293,367,440};
    tam = rand() % 8;
    _color = vec[tam];
}

