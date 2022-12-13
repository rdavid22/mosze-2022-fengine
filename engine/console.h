#ifndef consoleheader
#define consoleheader
#include <iostream>
#include <time.h>

#if _WIN32
#include <windows.h>
#else
#endif
/**
 * @brief Crossplatform console colors.
 * 
 */
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

namespace console
{
    /**
     * @brief Prints without animation and color.
     * 
     * @param text 
     */
    void print(std::string text);
    /**
     * @brief Prints without animation and color in new line.
     * 
     * @param text 
     */
    void printLine(std::string text);
     /**
     * @brief Prints with animation.
     * 
     * @param text 
     */
    void printAnim(std::string text);
     /**
     * @brief Prints with animation in new line.
     * 
     * @param text 
     */
    void printLineAnim(std::string text);

    /**
     * @brief Sets console cursor position.
     * 
     * @param x 
     * @param y 
     */
    void setPos(uint32_t x, uint32_t y);
    /**
     * @brief Gets current console cursor position
     * 
     * @param x 
     * @param y 
     */
    void getPos(uint32_t &x, uint32_t &y);

    /**
     * @brief Clear console.
     * 
     */
    void clear();

    /**
     * @brief Set the console color.
     * 
     * @param color 
     */
    void setColor(colors color);

    //void interpretText(bool anim = true);

    /**
     * @brief Delay between displaying characters to console.
     * 
     */
    const uint32_t animWriteDelay = 10;

/**
 * @brief Change characters on writing to screen except a specific character.
 * 
 * @param text 
 * @param except 
 * @param iteration 
 * @param delayMS 
 */
    void changeCharsRandomExcept(std::string text,char except,uint64_t iteration,uint32_t delayMS);
    /**
     * @brief Crossplatform delay.
     * 
     * @param ms 
     */
    void sleep(uint64_t ms);

    /**
     * @brief Get the currently set color.
     * 
     * @return colors 
     */
    colors getColor();

    /**
     * @brief Prints with animation and color.
     * 
     * @param color 
     * @param text 
     */
    
    void printAnim(colors color,std::string text);
    /**
     * @brief Prints with animation and color in new line
     * 
     * @param color 
     * @param text 
     */
    void printLineAnim(colors color,std::string text);
    /**
     * @brief Prints with color.
     * @param color 
     * @param text 
     */
    void print(colors color,std::string text);
    /**
     * @brief Prints lines with color.
     * 
     * @param color 
     * @param text 
     */
    void printLine(colors color,std::string text);
    /**
     * @brief Gets input from user.
     * 
     * @return std::string 
     */
    std::string input();
}
#endif