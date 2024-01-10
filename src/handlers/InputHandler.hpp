#pragma once

#include "SDL/SDL.h"

#include "../objects/commands/DownCommand.hpp"
#include "../objects/commands/LeftCommand.hpp"
#include "../objects/commands/RightCommand.hpp"
#include "../objects/commands/UpCommand.hpp"

// #include "../objects/commands/Command.hpp"

class InputHandler {
  public:
    static InputHandler *Instance();

    Command *keyboard_pressed();

  private:
    static InputHandler *instance;

    Command *up = new UpCommand();
    Command *down = new DownCommand();
    Command *left = new LeftCommand();
    Command *right = new RightCommand();

    ~InputHandler();
};
