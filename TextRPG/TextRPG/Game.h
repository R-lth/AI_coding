#pragma once

#include <string>

#include "Player.h"

class Game
{
public:
    Game();
    void Run();

private:
    void PrintIntro();
    void ProcessInput(const std::string& input);

public:
    Player player; // 임시

private:
    bool isRunning;
};
