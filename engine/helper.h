#ifndef F_ENGINE_GAME_HELPER_H_
#define F_ENGINE_GAME_HELPER_H_

#include "vector"
#include "iostream"
#if _WIN32
#include <windows.h>
#endif
std::vector<std::string> Split(std::string text, std::string delimiter)
{
    std::vector<std::string> parts;
    size_t pos = 0;
    std::string token;
    while ((pos = text.find(delimiter)) != std::string::npos)
    {
        token = text.substr(0, pos);
        parts.push_back(token);
        text.erase(0, pos + delimiter.length());
    }
    parts.push_back(text);
    return parts;
}

// Trims a string & returns it.
std::string Trim(std::string text)
{
    std::string out = "";
    uint64_t len = text.length();

    for (uint64_t i = 0; i < len; i++)
    {
        if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n' || text[i] == '\r')
        {
            continue;
        }
        out += text[i];
    }
    return out;
}
bool StartsWith(std::string text, std::string part)
{
    if (part.length() > text.length())
    {
        return false;
    }
    for (uint16_t i = 0; i < part.length(); i++)
    {
        if (part[i] != text[i])
        {
            return false;
        }
    }
    return true;
}
void PlaySound()
{
#if _WIN32

   Beep(500,40);
#endif
}

#endif