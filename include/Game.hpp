#include <Pet.hpp>
#include <Clock.hpp>

#ifndef GAME_HPP
#define GAME_HPP

class Game{
    
    Pet pet;
    Clock clock;
    bool _exitFlag;
    void draw();
    void handleEvents();
    void onExit();
    public:
    Game(const int hoursPerSkip): clock(hoursPerSkip), pet(0,0,0,0){
        cout<< "Welcome to your personal digital pet!" <<endl;
    }
    
    
    void run();
};

#endif //GAME_HPP