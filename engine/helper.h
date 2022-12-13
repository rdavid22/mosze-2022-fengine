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

    Beep(262, 800);
    Beep(262, 400);
    Beep(262, 600);
    Beep(262, 1600);
    Beep(262, 400);
    Beep(294, 800);
    Beep(294, 800);
    Beep(330, 400);
    Beep(330, 600);
    Beep(330, 1600);
    Beep(330, 400);
    Beep(330, 800);
    Beep(330, 800);
    Beep(330, 400);
    Beep(349, 800);
    Beep(349, 800);
    Beep(349, 400);
    Beep(349, 800);
    Beep(392, 800);
    Beep(392, 400);
    Beep(392, 800);
    Beep(392, 800);
    Beep(392, 200);
    Beep(392, 400);
    Beep(392, 600);
    Beep(392, 1600);
    Beep(392, 400);
    Beep(392, 800);
    Beep(392, 800);
    Beep(392, 400);
    Beep(392, 600);
    Beep(392, 1600);
    Beep(392, 400);
    Beep(440, 800);
    Beep(440, 800);
    Beep(440, 400);
    Beep(440, 600);
    Beep(440, 1600);
    Beep(440, 400);
    Beep(440, 600);
    Beep(440, 1600);
    Beep(440, 400);
    Beep(440, 600);
    Beep(440, 1600);
    Beep(440, 800);
    Beep(440, 800);
    Beep(440, 800);
    Beep(440, 800);
    Beep(440, 200);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 300);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 200);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 800);
    Beep(494, 300);
    Beep(494, 800);
    Beep(523, 800);
    Beep(523, 800);
    Beep(523, 800);
    Beep(523, 800);
    Beep(523, 400);
    Beep(523, 600);
    Beep(523, 1600);
    Beep(523, 400);
    Beep(523, 600);
    Beep(523, 1600);
    Beep(523, 400);
    Beep(523, 800);
    Beep(523, 800);
    Beep(523, 200);
    Beep(523, 200);
    Beep(523, 800);
    Beep(523, 800);
    Beep(587, 800);
    Beep(587, 800);
    Beep(587, 300);
    Beep(587, 800);
    Beep(587, 200);
    Beep(587, 200);
    Beep(587, 800);
    Beep(587, 800);
    Beep(659, 800);
    Beep(659, 800);
    Beep(659, 300);
    Beep(659, 800);

#endif
}

#endif