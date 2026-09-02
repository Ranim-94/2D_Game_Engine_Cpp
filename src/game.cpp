

#include"game.h"
#include <iostream>


Game::Game(){

    std::cout<<"\t -> Game constructor called"<<std::endl;

    this->m_app_run = false;
    /*
        intialize "m_app_run" to false initiallu
        this means when calling the constructor
        and instating the game, I don't run the game 
        directly,
    */

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

    // screen resolution 
    SDL_GetCurrentDisplayMode(0,&this->m_display_mode);
    // pass "display_mode" struct as reference
    // this will make the SDL_GetCurrentDisplayMode() to infer the characteristics
    // of our resolution of the screen (width, height,...) and update their values
    // directly in the display_mode struct
    // this is a very common practice in C, to pass a struct instance by ref and let the function
    // do its work, then update the parameters of the struct directly so we can use them


     this->m_window = SDL_CreateWindow(NULL, // No title 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->m_display_mode.w,// width screen
        this->m_display_mode.h,// height screen
        SDL_WINDOW_BORDERLESS);
    /*
        Here we are retruning a raw pointer to the 
        struct "window"
        
        This is cheaper and faster then returning (copying)
        the whole structture

    */

    // to make the video driver actually set it as full screen
    SDL_SetWindowFullscreen(this->m_window,SDL_WINDOW_FULLSCREEN);

    // Checking error
    if(!this->m_window){

        std::cerr<<"Error creating SDL window"<<std::endl;
        return;
    }

     this->m_renderer = SDL_CreateRenderer(this->m_window,-1,0);

    /*
        window: attache the window to the renderer
        -1: give me the default monitor I use
        0: I don't have any special flags, so I put "0"
    
    */

    // Checking error
    if(!this->m_renderer){

        std::cerr<<"Error creating SDL renderer"<<std::endl;
        return;
    }

    // Once everyting is ok, at this stage of the code
    // we can set "m_app_run" to true

    this->m_app_run = true;


}// End init()


void Game::free_resrc(){

    SDL_DestroyRenderer(this->m_renderer);
    SDL_DestroyWindow(this->m_window);
    SDL_Quit(); // opposite of SDL_init()

// Note: the sequence of operation above are in the reverse order
// done in the code before SDL_init(), SDL_CreateWindow(),
// SDL_CreateRenderer(), then color buffer


}// End free_resrc()


void Game::run(){


    while(this->m_app_run){

        process_input();
        
        update();
        
        render();

    } // End while()

}// End run()


void Game::update(){

// TODO

} // End update()


void Game::render(){

    SDL_SetRenderDrawColor(this->m_renderer, 
    255, 0, 0, 255);
    // the order of DrawColor() RGB, then transparency
    
    /*
        In my example I said I want full red, since
        the other 2 parameters are setting to "0"
    */


    SDL_RenderClear(this->m_renderer);


    // update the buffer responsible for renderer with suitable operations
    // in other words, display the color inside the render struct
    SDL_RenderPresent(this->m_renderer);


}// End render()



void Game::process_input(){

    SDL_Event event; // we create some event structure

    // we pass by reference this event structure is SDL_PollEvent()
    // SDL_PollEvent() enable SDL to read and process this event (pressing the mouse, a button on the keyboard,...)
    SDL_PollEvent(&event);

     // once SDL reads the "event", we check its type
    switch (event.type){

    case SDL_QUIT: // the SDL_QUI is the close (x) we see on any window to close it
            // this means we close on x, we set the bool "m_app_run" to false

    	this->m_app_run = false;

    	break;

    case SDL_KEYDOWN: // here this means we press down some key
            // but we want to know what key we have pressed (is it Esc or not)
            // Note that SDL give us some alias to the button and keys
            // Esc <-> SDLK_ESCAPE so we don't to have to memorize its code and value

    	if (event.key.keysym.sym == SDLK_ESCAPE)
            	this->m_app_run = false;

    	break;

    } // End switch case


}// End process_input()




