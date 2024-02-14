#ifndef CAT_H
#define CAT_H
#include <string>
#include <Animal.h>
#include <cmath>
#include <iostream>


const double PI = 3.14159265358979323846;

class Cat : public Animal
{
public:
    Cat()
    {
        name = "Cat";
        location.position_x = 0.0;
        location.position_y = 0.0;
    }

    void attack(double mousePositionX, double mousePositionY, int distance)
    {
        // Cat chasing mouse
        std::cout << "Mouse is nearby! Distance:" << distance << std::endl;

        // move cats position
        double angle = (atan2(mousePositionY - this->location.position_y, mousePositionX - this->location.position_x)) * 180 / PI;
        double xPosition = (double)(cos(angle) * distance);
        double yPosition = (double)(sin(angle) * distance);      

        this->location.position_x += xPosition;
        this->location.position_y += yPosition;
        std::cout << "Cat coordinates: (" << this->location.position_x << "," << this->location.position_y << ")" << std::endl;
    }

    void checkLocation(double mousePositionX, double mousePositionY)
    {
        // check if Mouse's coordinates are near the cat
        int distance = std::sqrt(std::pow((this->location.position_x - mousePositionX), 2) + std::pow((this->location.position_y - mousePositionY), 2));

        // check if Cat's distance from Mouse is at least 3 units away
        if (distance <= 3)
        {
            // if distance is zero, Cat is very close to mouse
            if (distance == 0)
            {
                std::cout << "Cat got mouse! GAME OVER!" << std::endl;
            }
            else
            {
                // continue following mouse
                attack(mousePositionX, mousePositionY, distance);
            }
        }

        /* Future developments:
        Check if the mouse is nearby and near water, the cat will abort the attack.
        Check if the mouse is near a dead end, if so, the cat will attack.
        */
    }
};
#endif