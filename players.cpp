#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#include<vector>
#include"texture.h"


//Made only for 2 players where player 1 is False and player 2 is True
class Players : public sf::Drawable{
    sf::Sprite m_sprite;
    int m_position;
    bool player, m_moved;
    
    void setTexture(){  //the image for players
        m_sprite = sf::Sprite();
        //for spider man
        //if player is false then player 1 else player 2
        m_sprite.setTexture(player ? PlayerTexture::player1 : PlayerTexture::player2);
        
    }
          
    void move(){        //move the player to the position
        if(m_position < 1 || m_position >= 64){
            m_position = 0;
        }
    
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {   target.draw(m_sprite);  }


public:

    void setplayer(bool player, int position, bool moved=false){
        setPlayer(player);
        setposition(position);
        setmoved(moved);
    }

    void setPlayer(bool pl){player = pl; setTexture();}
    bool getPlayer()       {return player;}

    void setposition(int pos){  m_position = pos; move();}
    int getposition(){  return m_position; }

    void setmoved(bool mv){ m_moved = mv; move();}
    bool getmoved(){ return m_moved; }  
};