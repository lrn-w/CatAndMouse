#ifndef MAIN_H
#define MAIN_H
#include <SFML\Graphics.hpp>

#include <Mouse.h>
#include <Cat.h>
#include <Maze.h>

#include <iostream>

/*
Process arrow key movements to set Mouse coordinates.
*/
void processMove(sf::Event event, Mouse *mouse)
{
    double x_position, y_position;
    x_position = 0.0;
    y_position = 0.0;

    switch (event.key.code)
    {
    case sf::Keyboard::Left:
        mouse->run(-1.0, 0.0);
        break;
    case sf::Keyboard::Right:
        mouse->run(1.0, 0.0);
        break;
    case sf::Keyboard::Up:
        mouse->run(0.0, 1.0);
        break;
    case sf::Keyboard::Down:
        mouse->run(0.0, -1.0);
        break;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Cat and Mouse");
    sf::Event event;

    // Create an event for each manual key press, not repeated events for key hold
    window.setKeyRepeatEnabled(false);

    Cat cat;
    Maze maze(&cat);
    Mouse mouse(&maze);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // window closed
            case sf::Event::Closed:
                cout << "Window closing" << endl;
                window.close();
                break;

            // key pressed
            case sf::Event::KeyPressed:
                processMove(event, &mouse);
                break;

            // we don't process other types of events
            default:
                break;
            }

            window.clear();
            window.display();
        } // innerWhile
    }     // outerWhile

    return 0;
}
#endif