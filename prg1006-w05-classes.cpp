#include <iostream>


// function to welcome the user to the app
// literally just show a string to the screen
// nice and simple for inlining 

inline void welcomeTheUser() {
    std::cout << "Welcome to the app!" << std::endl;
}


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
    PlayerClass () {
        health = 100;
        std::cout << "Player has been instantiated! They have health of " << static_cast<int>(health) << std::endl;
    }

    // instead of redeclaring a variable to make it public,
    // we should use getters and setters!

    int getHealth() {
        // explicit casting:
        // return static_cast<int>(health);
        // implicit casting:
        return health;
    }
    void setHealth(unsigned __int8 newHealth){
        /*health = newHealth; */
        if (newHealth > 100){
            // do not set the health, health is already high enough
        }
        else {
            health = newHealth;
        }
        
    }
};


int main()
{
    welcomeTheUser();
    // inline keyword replaces the function call with the function contents:
    // std::cout << "Welcome to the app!" << std::endl;

    // Instances of the struct and class:
    PlayerStruct structPlayer;
    PlayerClass classPlayer;
    structPlayer.health = 100;
    //classPlayer.health = 100; // error because by default, it's private
    classPlayer.setHealth(20);
    std::cout << classPlayer.getHealth() << std::endl;

    PlayerClass player2;
    player2.setHealth(50);
}

