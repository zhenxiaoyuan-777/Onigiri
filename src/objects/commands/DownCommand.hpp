#pragma once

#include "Command.hpp"

class DownCommand : public Command {
  public:
    virtual void execute(Actor &actor) { actor.down(); }
};
