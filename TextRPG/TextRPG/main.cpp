#include <iostream>
#include "OllamaClient.h"

int main()
{
    OllamaClient llm;

    std::string npcLine = llm.Generate(
        "너는 던전 입구의 경비병 NPC다. 20자 이내로 인사하라."
    );

    std::cout << "NPC: " << npcLine << std::endl;

    return 0;
}