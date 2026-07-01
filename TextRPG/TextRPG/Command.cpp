#include "Command.h"

#include <algorithm>
#include <cctype>
#include <string>

std::string ToLower(std::string text)
{
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char ch)
        {
            return static_cast<char>(std::tolower(ch));
        });

    return text;
}

CommandType ParseCommand(const std::string& input)
{
    std::string command = ToLower(input);

    if (command == "help")
    {
        return CommandType::Help;
    }
    if (command == "look")
    {
        return CommandType::Look;
    }
    if (command == "status")
    {
        return CommandType::Status;
    }
    if (command == "quit")
    {
        return CommandType::Quit;
    }

    return CommandType::Unknown;
}
