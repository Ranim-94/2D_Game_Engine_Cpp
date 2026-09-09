

#pragma once

#include<SDL2/SDL.h>

class Game{

private:
    
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    // to infer screen resolution
    SDL_DisplayMode m_display_mode;

    bool m_app_run;


public:

    Game();
    ~Game();


    void init();
    void run();

    // frame functions
    void process_input();
    void update();
    void render();
    
    void free_resrc();



}; // End "Game" class


