

#pragma once

class Game{

private:


public:

    Game();
    ~Game();


    void init();
    void run();

    // fame functions
    void process_input();
    void update();
    void render();
    
    void free_resrc();



}; // End "Game" class


