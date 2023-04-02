#include <SFML/Graphics.hpp>
#include<iostream>


class PlayerTexture{


public:

    static sf::Texture loadTexture(std::string path){
        sf::Texture temp;
        if (!temp.loadFromFile(path))
            std::cout<<"Error Loading picture file \n";
        return temp;
    }

    // static sf::Texture p1;
    // static sf::Texture p2;



};
    // sf::Texture PlayerTexture::p1 = PlayerTexture::loadTexture("images/player1.png");
    // sf::Texture PlayerTexture::p2 = PlayerTexture::loadTexture("images/player2.png");
