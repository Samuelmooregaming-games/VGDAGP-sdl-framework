#include <iostream>
#include <SDL.h>

bool quit = false;

int main(int argc, char* args[])
{

    //initialize SDL subsystems
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
        //failed to initialize
        std::cerr << "SDL could not initialize! SDL error" << SDL_GetError() << std::endl;
        return -1;
    }
    window = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        //failed to create window
        std::cerr << "unable to create a window! SDL_ERROR!" << SDL_GetError() << std::endl;
        }
//anything after this can assume window succsessfully create itself
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "unable to get renderer. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    //main game loop
    SDL_SetRenderDrawColor(renderer, 193, 255, 0, 0.8);
    SDL_Event events = {};
    while(!quit) {
        while (SDL_PollEvent(&events)) {
            //event polling loop
            //handle every event to look for
            switch (events.type) {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }
        //draw code goes down here
        SDL_RenderFillRect(renderer, nullptr);
        SDL_RenderPresent(renderer);
    
    }

    //destroy the renderer
    SDL_DestroyRenderer(renderer);
   // destroys the window
    SDL_DestroyWindow(window);

    //terminate SDL subsystems
    SDL_Quit();
    return 0;
} 
