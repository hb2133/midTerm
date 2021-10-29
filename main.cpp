#include <SDL.h>
#include "Game.h"
#include <iostream>

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
  if(TheGame::Instance()->init("Chapter 1",100,100,640,480,false))
  {
    while(TheGame::Instance()->running())
    {
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      SDL_Delay(10);
    }
  
  }
    else{
      std::cout << "game init failure" <<SDL_GetError()<<"\n";
      return -1;
    }
    TheGame::Instance()->clean();
    return 0;
}