#include <iostream>
#include <fstream> // this enables file IO
#include <string>

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
    // Classic constructor style:
    PlayerClass (std::string newPlayerName, int newPlayerHealth) {
        // health = 100;
        // Sanitisation:
        if (newPlayerHealth > 100) {
            health = 100;
        }
        else {
            health = newPlayerHealth;
        }
        
        name = newPlayerName;
        loadPlayerName();
        std::cout << "Player has been instantiated! They have health of " << static_cast<int>(health) << std::endl;
    }
    // Initialisation list style:
    /*PlayerClass(std::string newPlayerName, int newPlayerHealth) :
        name(newPlayerName), health(newPlayerHealth) {
        std::cout << "Player has been instantiated! They have health of " << static_cast<int>(health) << std::endl;
    }*/

    ~PlayerClass() {
        std::cout << name << " has been destroyed!" << std::endl;
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

    void savePlayerName() {
        // ofstream comes from fstream, make sure we include that!!!
        // "#include <fstream>;" to make this work!!!
        // ofstream by default will create the file if it doesn't exist
        std::ofstream playerSaveFile("savedata.txt");
        // If we don't provide "something", then "nothing" will be saved
        // and the default ofstream config will replace all existing contents
        // with the nothing or the something
        playerSaveFile << name;
        // Close the file stream to be extra safe about any other code
        // accidentally editing the file
        playerSaveFile.close();

    }

    void loadPlayerName() {
        std::ifstream existingSaveFile("savedata.txt");
        // "#include <string>;" to make the getline work:
        std::getline(existingSaveFile, name);
        std::cout << name << std::endl;
    }

};


int main()
{
    welcomeTheUser();
    // inline keyword replaces the function call with the function contents:
    // std::cout << "Welcome to the app!" << std::endl;

    // Instances of the struct and class:
    PlayerStruct structPlayer;
    PlayerClass classPlayer("Player Name Here", 200);
    structPlayer.health = 100;
    //classPlayer.health = 100; // error because by default, it's private
    classPlayer.setHealth(20);
    std::cout << classPlayer.getHealth() << std::endl;

    classPlayer.savePlayerName();

    /*PlayerClass player2;
    player2.setHealth(50);*/
}

