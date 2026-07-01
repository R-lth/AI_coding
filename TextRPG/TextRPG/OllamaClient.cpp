#include "OllamaClient.h"
#include <cpr/cpr.h>

std::string OllamaClient::Generate(const std::string& prompt)
{
    cpr::Response response = cpr::Post(
        cpr::Url{ "http://localhost:11434/api/generate" },
        cpr::Body{ "{}" }
    );

    if (response.error)
    {
        return "Ollama 연결 실패";
    }

    return response.text;
}