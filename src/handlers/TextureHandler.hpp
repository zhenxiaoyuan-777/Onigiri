#pragma once

#include <map>
#include <string>

#include "SDL/SDL.h"

#include "../components/Sprite.hpp"

class TextureHandler {
  public:
    TextureHandler(TextureHandler &other) = delete;
    void operator=(const TextureHandler &) = delete;

    static TextureHandler *Instance();

    void init();
    void draw(const Sprite sprite);

  private:
    static TextureHandler *instance;

    void load(std::string name, std::string path, int width, int height);
    void clean(std::string id);

    std::map<std::string, SDL_Texture *> texture_map;

    TextureHandler() {}
    ~TextureHandler();
};
