// サンプルプログラム:
// SDL2でアプリケーションウィンドウを生成する
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include "Lib/Geometry2D/Geometry2D.h"
#include "Lib/Collision2D/Collision2D.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
//Starts up SDL and creates window
bool init();
void Input();
void Update();
void Draw();
//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// The Window renderer
SDL_Renderer* gRenderer = NULL;

const Uint8* state;

Circle circle;

int main(int argc, char* argv[]) {
    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
        return -1;
    }

    // Main Loop flag
    bool quit = false;
   
    // Event Handler
    SDL_Event eHandle;

    //Handle events on queue
    while (!SDL_PollEvent(&eHandle)||eHandle.type != SDL_QUIT)
    {
        Input();
        Update();
        Draw();
    }

    //Free resources and close SDL
    close();
    
    return 0;

}
bool init()
{
    //Initialization flag
    auto func = [&]() {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    };

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)func();
    //Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    gWindow == NULL ? func() : 0;

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    //Get window surface
    gScreenSurface = SDL_GetWindowSurface(gWindow);

    //Initialize render color
    SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);

    circle = Circle(Vector2(40, 53), 25, RGBA{0xff,0xff,0xff,0xff}, true);
    return true;
}

void Input()
{
    state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
    }
    if (state[SDL_SCANCODE_LEFT]) {
    }
    if (state[SDL_SCANCODE_DOWN]) {
    }
    if (state[SDL_SCANCODE_RIGHT]) {
    }
}

void Update()
{
}

void Draw()
{
    // ClearScreen
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xff, 0xff);
    SDL_RenderClear(gRenderer);

    // 
    circle.Draw(gRenderer);
    //UpdateScreen
    SDL_RenderPresent(gRenderer);
}

void close()
{

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
