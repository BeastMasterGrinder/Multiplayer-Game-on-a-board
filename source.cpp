#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "board.h"

using namespace std;
using namespace sf;

int board_size(){
    int size = (rand() % 89) + 10;
    size *= 6;      //my last digit of roll number is 0 so using the second last digit
    int rollNum = 660;
    size = rollNum / size;
    size = size % 25;
    if(size<10)
        size += 10;
    return size;
}



int main()
{

    srand(time(NULL));

    int num_blocks = board_size();

    //max size of the board = 26
    //min size of the board = 40

    RenderWindow window(
        VideoMode(640, 640),
        "Hello World");
    CircleShape shape(320);
 
    while (window.isOpen())
    {
        Event event;
        while (
            window.pollEvent(event))
            if (event.type ==
            Event::Closed)
                window.close();
 
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}