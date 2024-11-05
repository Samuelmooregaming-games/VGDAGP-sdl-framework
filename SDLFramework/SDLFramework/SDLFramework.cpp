#include <iostream>
#include <SDL.h>

int main(int argc, char* args[])
{

    //initialize SDL subsystems
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
        //failed to initialize
        std::cerr << "SDL could not initialize! SDL error"<<SDL_GetError() << std::endl;
        return -1;
    }

    //terminate SDL subsystems
    SDL_Quit();
    return 0;
}
