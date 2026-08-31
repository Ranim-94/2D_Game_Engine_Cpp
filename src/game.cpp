

#include"game.h"

#include<SDL2/SDL.h>


#include <iostream>


Game::Game(){

    std::cout<<"\t -> Game constructor called"<<std::endl;

}


Game::~Game(){

    std::cout<<"\t -> Game destructor called"<<std::endl;

}


void Game::init(){

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0 ){

        // Here means some error happen
        std::cerr<<"Error in initializing SDL "<<std::endl;

        return;

    }


    SDL_Window* window = SDL_CreateWindow(NULL, // No title 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,// width
        600,// height
        SDL_WINDOW_BORDERLESS);
    /*
        Here we are retruning a raw pointer to the 
        struct "window"
        
        This is cheaper and faster then returning (copying)
        the whole structture

    */

    // Checking error
    if(!window){

        std::cerr<<"Error creating SDL window"<<std::endl;
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);

    /*
        window: attache the window to the renderer
        -1: give me the default monitor I use
        0: I don't have any special flags, so I put "0"
    
    */

    // Checking error
    if(!renderer){

        std::cerr<<"Error creating SDL renderer"<<std::endl;
        return;
    }


}// End init()