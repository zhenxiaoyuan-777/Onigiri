#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "entt/entt.hpp"

#include "Constant.hpp"
#include "objects/actors/Player.hpp"

class Application {
  public:
    static Application *Instance();

    void init();
    void run();
    void clean();
    void quit();

  private:
    static Application *instance;

    const int DELAY_TIME = 1000.0f / FPS;

    void events();
    void update();
    void render();

    SDL_Window *window = 0;
    SDL_Renderer *renderer = 0;

    bool running = false;

    Player player;

    // entt
    entt::registry registry;

    ~Application();
};