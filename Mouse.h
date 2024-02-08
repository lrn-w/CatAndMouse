#include <string>
#include <Animal.h>
#include <Maze.h>
#include <iostream>
using namespace std;

class Mouse: public Animal
{
    public:
        Maze *mazeObj;
        Mouse(Maze *maze_obj)
        {
            name = "Mouse";
            location.position_x = 0.0;
            location.position_y = 0.0;
            mazeObj = maze_obj;
        }

        void run(double positionX, double positionY)
        {        
            // increment/decrement mouse coordinates
            this->location.position_x += positionX;
            this->location.position_y += positionY;
            cout << "Mouse running!! Coordinates(" << this->location.position_x  << "," << this->location.position_y <<  ")" << endl;

            // call checkLocation to verify if mouse is as cheese or stuck at dead end
            checkLocation();

            // notifty Maze and consumers of Mouse's location
            this->mazeObj->sendMouseLocation(this->location.position_x,this->location.position_y);
            cout << "*************************************************************" << endl;
        }

        void checkLocation()
        {
            // check if mouse is at a coordinate for cheese
            std::list<std::pair<double,double>> cheese_coordinates = mazeObj->getCheeseCoordinates();
            std::pair<double, double> mouseCoordinates (location.position_x, location.position_y);
            std::list<std::pair<double,double>>::iterator it = std::find(cheese_coordinates.begin(), cheese_coordinates.end(), mouseCoordinates);

            if(it != cheese_coordinates.end())
            {
                std::cout << "Mouse found cheese! Game over" << endl;
            }

            /* Future developments: 
            Check if mouse is at dead end (placed in a stuck state, Cat can win)
            or at a water spot (Mouse can escape Cat)*/


        }
};