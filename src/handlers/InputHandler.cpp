#include "InputHandler.hpp"
#include "../Application.hpp"

InputHandler *InputHandler::instance = nullptr;
InputHandler *InputHandler::Instance() {
    if (instance == nullptr) {
        instance = new InputHandler();
    }
    return instance;
}

Command *InputHandler::keyboard_pressed() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            Application::Instance()->quit();
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_w:
                return up;
            case SDLK_s:
                return down;
            case SDLK_a:
                return left;
            case SDLK_d:
                return right;

            default:
                break;
            }
        default:
            break;
        }
    }

    return nullptr;
}

InputHandler::~InputHandler() {
    delete up;
    delete down;
    delete left;
    delete right;
    delete instance;
}
