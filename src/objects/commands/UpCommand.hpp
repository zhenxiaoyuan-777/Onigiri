#pragma once

#include "Command.hpp"

class UpCommand : public Command {
  public:
    virtual void execute(Actor &actor) { actor.up(); }
};
