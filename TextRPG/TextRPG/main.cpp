#include <iostream>
#include <windows.h>

#include "OllamaClient.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    OllamaClient llm;

    std::string npcLine = llm.Generate(
        "너는 던전 입구의 경비병 NPC다. "
        "반드시 한국어만 사용한다. "
        "20자 이내로 인사하라."
    );

    std::cout << "NPC: " << npcLine << std::endl;

    return 0;
}