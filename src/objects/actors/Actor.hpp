#pragma once

class Actor {
  public:
    virtual ~Actor(){};

    virtual void up() = 0;
    virtual void down() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
};