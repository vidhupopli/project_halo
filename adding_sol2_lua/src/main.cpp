#include <SDL2/SDL.h>
#include <emscripten.h>
#include <iostream>
#include "sol/sol.hpp"

SDL_Window *pWindow(nullptr);
SDL_Renderer *pRenderer(nullptr);
sol::state *lua(nullptr);

bool InitSDL()
{
    std::cout << "Initialising SDL2...\n";
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL Initialisation failed: " << SDL_GetError() << "\n";
        return false;
    }

    // Creation of window
    pWindow = SDL_CreateWindow("SDL2 and Emscripten Test",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 800,
                               600,
                               SDL_WINDOW_SHOWN);
    if (!pWindow)
    {
        std::cerr << "Failed to create window" << SDL_GetError() << "\n";
    }

    // Creation of renderer
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!pRenderer)
    {
        std::cerr << "Failed to create renderer" << SDL_GetError() << "\n";
    }

    return true;
}

void CleanUp()
{
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    if (lua)
        delete lua;
}

void GameLoop()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            // exit the loop
            emscripten_cancel_main_loop();
        }
    }

    // Drawing rectangle.
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);

    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_Rect box{50, 50, 50, 50}; // Struct variable creation: x, y, width, height
    SDL_RenderFillRect(pRenderer, &box);

    SDL_RenderPresent(pRenderer);
}

int main()
{
    std::cout << "Starting game...\n";

    if (!InitSDL())
    {
        return 1;
    }

    // Initialize Lua
    std::cout << "Creating Lua state...\n";
    lua = new sol::state();
    std::cout << "Lua state created\n";

    lua->open_libraries(sol::lib::base);
    std::cout << "Lua libraries opened successfully\n";

    // Load and execute the Lua script
    std::cout << "Loading Lua script...\n";
    auto result = lua->safe_script_file("assets/scripts/main.lua");
    if (!result.valid())
    {
        sol::error err = result;
        std::cerr << "Lua script error: " << err.what() << "\n";
    }
    else
    {
        std::cout << "Lua script executed successfully\n";
    }

    std::cout << "Entering game loop...\n";
    emscripten_set_main_loop(GameLoop, 0, 1);

    CleanUp();

    return 0;
}