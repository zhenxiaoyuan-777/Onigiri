#pragma once

#include "Command.hpp"

class RightCommand : public Command {
  public:
    virtual void execute(Actor &actor) { actor.right(); }
};
