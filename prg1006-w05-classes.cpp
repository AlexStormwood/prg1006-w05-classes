#include <iostream>


struct PlayerStruct {
    unsigned __int8 health;
    unsigned int score;
    std::string name;
};

class PlayerClass {
// intentionally state private even though it's private by default
// so that any other devs know that this is in purpose
private: 
    unsigned __int8 health;
    unsigned int score;
    std::string name;

public: 
    // instead of redeclaring a variable to make it public,
    // we should use getters and setters!


    int getHealth() {
        // explicit casting:
        // return static_cast<int>(health);
        // implicit casting:
        return health;
    }
    void setHealth(unsigned __int8 newHealth){
        health = newHealth;
    }
};


int main()
{
    // Instances of the struct and class:
    PlayerStruct structPlayer;
    PlayerClass classPlayer;
    structPlayer.health = 100;
    //classPlayer.health = 100; // error because by default, it's private
    classPlayer.setHealth(100);
    std::cout << classPlayer.getHealth() << std::endl;
}

