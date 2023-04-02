
#include<SFML/Graphics.hpp>
#include<string>
#include<vector>
#include"texture.h"


//Made only for 2 players where player 1 is False and player 2 is True
class PlayerData : public sf::Drawable{
    sf::Sprite m_sprite;
    int m_position;
    float pos_x, pos_y;
    bool player, m_moved;
    
    

    void setTexture(){  //the image for players
        m_sprite = sf::Sprite();
        //for spider man
        //if player is false then player 1 else player 2
        // m_sprite.setTexture(player ? p1 : p2);
        
    }
          
    void move(){        //move the player to the position   //assuming the board size is 15*15
        if(m_position < 1 || m_position >= 225){
            m_position = 0;
        }
    
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {   target.draw(m_sprite);  }


public:

    //Constructor
    PlayerData(int pos =0, bool player =false, int x=0, int y=0){
        m_position = 0;
        m_moved = false;
        player = player;
        pos_x = x;
        pos_y = y;
        setTexture();
    }

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

    void setpositionX(float x){ pos_x = x; }
    void setpositionY(float y){ pos_y = y; }
    //getters of posx and posy
    float getpositionX(){ return pos_x; }
    float getpositionY(){ return pos_y; }


};
