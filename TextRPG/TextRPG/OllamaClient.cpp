#include "OllamaClient.h"

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string OllamaClient::Generate(const std::string& prompt)
{
    json requestBody =
    {
        {"model", "qwen2.5:3b"},
        {"prompt", prompt},
        {"stream", false}
    };

    cpr::Response response = cpr::Post(
        cpr::Url{ "http://localhost:11434/api/generate" },
        cpr::Header{ {"Content-Type", "application/json; charset=utf-8"} },
        cpr::Body{ requestBody.dump() }
    );

    if (response.error)
    {
        return "Ollama 연결 실패";
    }

    if (response.status_code >= 400)
    {
        return "Ollama 서버 응답 오류";
    }

    if (response.text.empty())
    {
        return "응답이 비어 있습니다";
    }

    try
    {
        json responseJson = json::parse(response.text);

        if (!responseJson.contains("response"))
        {
            return "response 값 없음";
        }

        return responseJson["response"].get<std::string>();
    }
    catch (const json::parse_error&)
    {
        return "응답 파싱 실패";
    }
}