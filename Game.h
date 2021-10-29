#ifndef __Game__
#define __Game__
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>

class Game{
  public:
    Game(){}
    ~Game(){}

    bool init(const char *title,int xpos,int ypos, int width, int height,int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    int m_currentFrame;

    GameObject m_go;
    Player m_player;
    std::vector<GameObject*> m_gameObjects;
};

#endif