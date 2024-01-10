#pragma once

#include "../actors/Actor.hpp"

class Command {
  public:
    virtual ~Command(){};

    virtual void execute(Actor &actor) = 0;
};
