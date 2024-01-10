#pragma once

#include "Command.hpp"

class LeftCommand : public Command {
  public:
    virtual void execute(Actor &actor) { actor.left(); }
};
