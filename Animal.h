#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal
{
   struct Location {
    double position_x;
    double position_y;
};
    public:
      std::string name;
      Location location;
        
      // constructor
      Animal()
      {
          name = "Animal";
          location.position_x = 0.0;
          location.position_y = 0.0;
      }

      void checkLocation()
      {
          //Default check location"
      }
};

#endif