#pragma once
#include <string>

class OllamaClient
{
public:
    std::string Generate(const std::string& prompt);
};