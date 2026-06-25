#include <iostream>


struct PlayerStruct {
    unsigned __int8 health;
    unsigned int score;
    std::string name;
};

class PlayerClass {
    unsigned __int8 health;
    unsigned int score;
    std::string name;
};


int main()
{
    PlayerStruct structPlayer;
    PlayerClass classPlayer;
    structPlayer.health = 100;
    //classPlayer.health = 100; // error because by default, it's private

}

