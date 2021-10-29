#include <SDL.h>
#include "Game.h"

Game* g_game = 0;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos,int height,int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow(title,xpos,ypos,height,width,flags);
    if(g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,0);
    }
  }
  else{
    return false;
  }
  SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);

  return true;
}

void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[])
{
  g_game = new Game();
  g_game -> init("Game Class",100,100,640,480,0);
  while(g_game->running())
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    SDL_Delay(10);
  }
  g_game->clean();

    return 0;
}