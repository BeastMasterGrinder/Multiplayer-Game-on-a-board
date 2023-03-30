#include <SFML/Graphics.hpp>
#include<iostream>


class PlayerTexture{


public:

    static sf::Texture PlayerTexture::loadTexture(std::string path){
        sf::Texture temp;
        if (!temp.loadFromFile(path))
            std::cout<<"Error Loading picture file \n";
    }

    static sf::Texture player1;
    static sf::Texture player2;



};
    sf::Texture PlayerTexture::player1 = PlayerTexture::loadTexture("images/player1.jpg");
    sf::Texture PlayerTexture::player2 = PlayerTexture::loadTexture("images/player1.jpg");