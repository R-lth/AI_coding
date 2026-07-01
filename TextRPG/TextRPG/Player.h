#pragma once

#include <string>

class Player
{
public:
    Player();

public:
    std::string getName() { return name; }
    int getHp() { return hp; }
    int getAttack() { return attack; }

private:
    std::string name;
    int hp;
    int attack;
};
