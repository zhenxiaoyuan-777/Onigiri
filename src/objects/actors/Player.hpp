#pragma once

#include <iostream>

#include "Actor.hpp"

class Player : public Actor {
  public:
    void up() { std::cout << "Up" << std::endl; }
    void down() { std::cout << "Down" << std::endl; }
    void left() { std::cout << "Left" << std::endl; }
    void right() { std::cout << "Right" << std::endl; }
};
