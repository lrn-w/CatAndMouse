#ifndef MAZE_H
#define MAZE_H
#include <list>
#include <Cat.h>
#include <iostream>


class Maze
{
    public:

        std::list<std::pair<double,double>> waterCoordinates;
        std::list<std::pair<double,double>> cheeseCoordinates;
        Cat *catObj;

        Maze(Cat *cat_obj)
        {
            waterCoordinates.push_back(std::pair(0.5,0.5));
            cheeseCoordinates.push_back(std::pair(1,1));
            catObj = cat_obj;
        }

        void sendMouseLocation(double position_x, double postion_y) // include arg with mouse coordinates
        {
            // send mouse location to cat
            std::cout << "Maze: Sending Mouse's coordinates to the cat!" << std::endl;
            catObj->checkLocation(position_x,postion_y);

        }

        std::list<std::pair<double,double>> getCheeseCoordinates()
        {
            return this->cheeseCoordinates;
        }

};

#endif