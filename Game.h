#ifndef __Game__
#define __Game__
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>

class Game{
  public:
    ~Game(){}
      static Game* Instance()
      {
        if(s_pInstance == 0)
        {
          s_pInstance = new Game();
          return s_pInstance;
        }
        return s_pInstance;
      }
            SDL_Renderer* getRenderer() const{return m_pRenderer;}

    bool init(const char *title,int xpos,int ypos, int width, int height,int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

  private:
      Game(){}
      static Game* s_pInstance;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    int m_currentFrame;

    GameObject m_go;
    Player m_player;
    std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif