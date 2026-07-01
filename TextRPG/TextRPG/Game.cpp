#include "Game.h"

#include <iostream>
#include <string>
#include <windows.h>

#include "Command.h"

Game::Game() : isRunning(true)
{
}

void Game::Run()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    PrintIntro();

    while (isRunning)
    {
        std::cout << "\n> ";
        std::string input;
        std::getline(std::cin, input);

        ProcessInput(input);
    }
}

void Game::PrintIntro()
{
    std::cout << "=== MUD Text RPG ===" << std::endl;
    std::cout << "명령어를 입력해 주세요." << std::endl;
    std::cout << "help, look, status, quit" << std::endl;
}

void Game::ProcessInput(const std::string& input)
{
    if (input.empty())
    {
        return;
    }

    CommandType type = ParseCommand(input);

    switch (type)
    {
    case CommandType::Help:
        std::cout << "help: 도움말 출력" << std::endl;
        std::cout << "look: 현재 위치 설명 출력" << std::endl;
        std::cout << "status: 플레이어 상태 출력" << std::endl;
        std::cout << "quit: 게임 종료" << std::endl;
        break;

    case CommandType::Look:
        std::cout << "당신은 어두운 던전 입구에 서 있습니다." << std::endl;
        break;

    case CommandType::Status:
        std::cout << "이름: " << player.getName() << std::endl;
        std::cout << "HP: " << player.getHp() << std::endl;
        std::cout << "공격력: " << player.getAttack() << std::endl;
        break;

    case CommandType::Quit:
        std::cout << "게임을 종료합니다." << std::endl;
        isRunning = false;
        break;

    case CommandType::Unknown:
    default:
        std::cout << "알 수 없는 명령어입니다. help를 입력해 보세요." << std::endl;
        break;
    }
}
