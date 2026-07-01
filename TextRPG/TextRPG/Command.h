#pragma once

#include <string>

enum class CommandType
{
    Help,
    Look,
    Status,
    Quit,
    Unknown
};

CommandType ParseCommand(const std::string& input);
