
#include "SDL/SDL_image.h"

#include "../Application.hpp"
#include "../Constant.hpp"
#include "TextureHandler.hpp"

TextureHandler *TextureHandler::instance = nullptr;
TextureHandler *TextureHandler::Instance() {
    if (instance == nullptr) {
        instance = new TextureHandler();
    }
    return instance;
}

void TextureHandler::init() {
    load("characters", CHARACTER_SPRITESHEET_PATH, NULL, NULL);
}

void TextureHandler::draw(const Sprite sprite) {
    SDL_Rect src_rect, dst_rect;

    src_rect.x = sprite.x;
    src_rect.y = sprite.y;
    src_rect.w = sprite.width;
    src_rect.h = sprite.height;

    dst_rect.x = 200;
    dst_rect.y = 200;
    dst_rect.w = sprite.width;
    dst_rect.h = sprite.height;

    SDL_RenderCopyEx(Application::Instance()->get_renderer(),
                     texture_map[sprite.name], &src_rect, &dst_rect, NULL, NULL,
                     SDL_FLIP_NONE);
}

void TextureHandler::load(std::string name, std::string path, int width,
                          int height) {
    SDL_Texture *texture =
        IMG_LoadTexture(Application::Instance()->get_renderer(), path.c_str());
    if (!texture) {
        SDL_Log("IMG_LoadTexture failed: %s. \n", SDL_GetError());
        return;
    }

    if (SDL_QueryTexture(texture, NULL, NULL, &width, &height) < 0) {
        SDL_Log("SDL_QueryTexture failed: %s. \n", SDL_GetError());
    }

    texture_map[name] = texture;
}

void TextureHandler::clean(std::string id) {
    SDL_DestroyTexture(texture_map[id]);
    texture_map.erase(id);
}

TextureHandler::~TextureHandler() {
    for (auto it : texture_map) {
        SDL_DestroyTexture(it.second);
    }
    delete instance;
}