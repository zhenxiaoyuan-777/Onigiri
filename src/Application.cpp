#include "Application.hpp"
#include "handlers/InputHandler.hpp"
#include "handlers/TextureHandler.hpp"

Application *Application::instance = nullptr;
Application *Application::Instance() {
    if (instance == nullptr) {
        instance = new Application();
    }
    return instance;
}

void Application::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
        running = false;
    }
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT,
                                    SDL_WINDOW_SHOWN, &window, &renderer) < 0) {
        SDL_Log("SDL_CreateWindowAndRenderer failed: %s\n", SDL_GetError());
        running = false;
    }

    SDL_SetWindowTitle(window, "Onigiri");
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);

    TextureHandler::Instance()->init();

    running = true;
}

void Application::run() {
    Uint32 frame_start, frame_time;

    while (running) {
        frame_start = SDL_GetTicks();

        events();
        update();
        render();

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_time < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frame_time));
        }
    }
}

void Application::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::quit() { this->running = false; }

SDL_Renderer *Application::get_renderer() { return this->renderer; }

void Application::events() {
    Command *command = InputHandler::Instance()->keyboard_pressed();
    if (command) {
        command->execute(player);
    }
}

void Application::update() {}

void Application::render() {
    SDL_RenderClear(renderer);

    TextureHandler::Instance()->draw(pink_body_squircle);

    SDL_RenderPresent(renderer);
}

Application::~Application() {
    clean();
    delete instance;
}