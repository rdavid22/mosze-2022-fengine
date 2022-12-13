#include "console.h"
#include <cstdio>
#include <iostream>
#if _WIN32

#include <windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#else
#include <unistd.h>
#include <termios.h>
#endif

colors lastColor = DEFAULT;

void console::print(std::string text)
{
    std::cout << text;
}
void console::printAnim(std::string text)
{
    uint64_t len = text.length();
    for (uint64_t i = 0; i < len; i++)
    {
#if _WIN32
        std::cout << text[i];
#else
        std::cout << text[i] << std::flush;
#endif
        console::sleep(10);
    }
}
void console::printLineAnim(std::string text)
{
    uint64_t len = text.length();
    for (uint64_t i = 0; i < len; i++)
    {
#if _WIN32
        std::cout << text[i];
#else
        std::cout << text[i] << std::flush;
#endif
        console::sleep(20);
    }
    std::cout << std::endl;
}
void console::printLine(std::string text)
{
    std::cout << text << std::endl;
}
void console::setColor(colors color)
{
    lastColor = color;
#if _WIN32
    SetConsoleTextAttribute(hConsole, color);
#else
    printf("\033[;%dm", color);
#endif
}
void console::getPos(uint32_t &x, uint32_t &y)
{
#if _WIN32
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsole, &cbsi))
    {
        COORD coord = cbsi.dwCursorPosition;
        x = coord.X;
        y = coord.Y;
    }
#else // i have no idea :)
    char buf[30] = {0};
    int ret, i, pow;
    char ch;

    y = 0;
    x = 0;

    struct termios term, restore;

    tcgetattr(0, &term);
    tcgetattr(0, &restore);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);

    write(1, "\033[6n", 4);

    for (i = 0, ch = 0; ch != 'R'; i++)
    {
        ret = read(0, &ch, 1);
        if (!ret)
        {
            tcsetattr(0, TCSANOW, &restore);
            return;
        }
        buf[i] = ch;
    }

    if (i < 2)
    {
        tcsetattr(0, TCSANOW, &restore);
        return;
    }

    for (i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
    {

        x = x + (buf[i] - '0') * pow;
    }
    for (i--, pow = 1; buf[i] != '['; i--, pow *= 10)
    {

        y = y + (buf[i] - '0') * pow;
    }
    tcsetattr(0, TCSANOW, &restore);
#endif
}
void console::clear()
{
#if _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void console::setPos(uint32_t x, uint32_t y)
{
#if _WIN32
    COORD pos = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hConsole, pos);
#else
    printf("\033[%d;%df", y, x);
#endif
}
void console::changeCharsRandomExcept(std::string text, char except, uint64_t iteration, uint32_t delayMS)
{
    srand((unsigned)time(0));

    // std::string chars = "~ˇ^˘°˛`˙´´˝¨×÷Í€ÄäđĐ[]íłŁ$ß*>;<}{@&#";
    std::string chars = "&@{}][123456789asbcdep";
    uint32_t randomLen = chars.length();
    uint64_t len = text.length();
    for (uint64_t iter = 0; iter < iteration; iter++)
    {
        console::setColor(colors((rand() % 5)));
        console::print(text);
        for (uint64_t i = 0; i < len; i++)
        {
            if (text[i] != except && text[i] != '\n' && text[i] != '\r')
            {
                int random = rand() % randomLen;
                text[i] = chars[random];
            }
        }
        console::setPos(0, 0);
        console::sleep(delayMS);
        // graphics::clear();
    }
}
void console::sleep(uint64_t ms)
{
#if _WIN32
    Sleep(ms);
#else
    uint64_t val = ms * 1000;
    usleep(val);
#endif
}

colors getColor()
{
    return lastColor;
}

void console::printAnim(colors color, std::string text)
{
    colors c = lastColor;
    console::setColor(color);
    console::printAnim(text);
    console::setColor(c);
}
void console::printLineAnim(colors color, std::string text)
{
    colors c = lastColor;
    console::setColor(color);
    console::printLineAnim(text);
    console::setColor(c);
}
void console::print(colors color, std::string text)
{
    colors c = lastColor;
    console::setColor(color);
    console::print(text);
    console::setColor(c);
}
void console::printLine(colors color, std::string text)
{
    colors c = lastColor;
    console::setColor(color);
    console::printLine(text);
    console::setColor(c);
}
std::string console::input()
{
    std::string in;
    std::cin >> in;
    return in;
}

void console::PrintError(uint16_t error_message)
{
    switch (error_message)
    {
    case kErrorInputWasString:
        console::printLineAnim(RED, "Nem lehet szöveget beírni.");
        break;
    case kErrorOptionDoesNotExist:
        console::printLineAnim(RED, "Nem létezik ilyen választási lehetőség.");
        break;
    case kErrorPlayerAlreadyExist:
        console::printLineAnim(RED, "Egy ilyen nevű játékos már létezik!");
        break;
    case kErrorPlayerDoesNotExist:
        console::printLineAnim(RED, "A kiválaszott játékos nem létezik!");
        break;
    default:
        break;
    }
}