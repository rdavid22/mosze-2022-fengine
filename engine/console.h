#ifndef FENGINE_CONSOLE_H_
#define FENGINE_CONSOLE_H_
#include <iostream>
#include <time.h>
#include <string>
#if _WIN32
#include <windows.h>

#else
#include <unistd.h>
#include <termios.h>
#endif
void SleepMS(uint64_t ms)
{
#if _WIN32
    Sleep(ms);
#else
    uint64_t val = ms * 1000;
    usleep(val);
#endif
}
enum colors
{
#if _WIN32
    DEFAULT = 7,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    RED = 12,
    PURPLE = 13,
    YELLOW = 14,
    WHITE = 15,
#else
    DEFAULT = 0,
    BLUE = 34,
    GREEN = 32,
    CYAN = 36,
    RED = 31,
    PURPLE = 35,
    YELLOW = 33,
    WHITE = 37,
#endif
};

class MConsole
{
private:
#if _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
    void SetColor(colors color)
    {
#if _WIN32
        SetConsoleTextAttribute(hConsole, color);
#else
        printf("\033[;%dm", color);
#endif
    }

public:
    void Write(std::string text, colors color = DEFAULT, bool animate = false)
    {
        if (color != DEFAULT)
        {
            SetColor(color);
        }
        if (animate)
        {
            uint64_t len = text.length();
            for (uint64_t i = 0; i < len; i++)
            {
#if _WIN32
                std::cout << text[i];
#else
                std::cout << text[i] << std::flush;
#endif
                SleepMS(5);
            }
        }
        else
        {
            std::cout << text;
        }
        SetColor(DEFAULT);
    }
    void WriteLine(std::string text, colors color = DEFAULT, bool animate = false)
    {
        Write(text, color, animate);
        std::cout << std::endl;
    }
    void GetCursorPosition(uint32_t &x, uint32_t &y)
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
    void Clear()
    {
#if _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
    void SetCursorPosition(uint32_t x, uint32_t y)
    {
#if _WIN32
        COORD pos = {(SHORT)x, (SHORT)y};
        SetConsoleCursorPosition(hConsole, pos);
#else
        printf("\033[%d;%df", y, x);
#endif
    }
    std::string ReadLine()
    {
        std::string in;
        Write("\nparancs: ", YELLOW, true);
        std::getline(std::cin, in);
        return in;
    }
};

static MConsole Console = MConsole();

#endif