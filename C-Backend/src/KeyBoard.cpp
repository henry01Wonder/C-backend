/* MIT License

Copyright (c) [2024] [Henry01]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "KeyBoard.hpp"

#include <unistd.h>
#include <iostream>

KeyBoard::KeyBoard()
{
    GetTerminoSet(originSet);
    SetNoneCanonicalMode(originSet);
    std::cout << "Set none canonica mode" << std::endl;
}

KeyBoard::~KeyBoard()
{
    SetCanonicaMode(originSet);
    std::cout << "Set canoica mode" << std::endl;
}

bool KeyBoard::GetTerminoSet(termios& set)
{
    tcgetattr(STDIN_FILENO, &set);  // 獲取當前終端屬性
    return true;
}

bool KeyBoard::SetNoneCanonicalMode(const termios& originSet)
{
    termios tmpSet = originSet;
    tmpSet.c_lflag &= ~(ICANON | ECHO);  // 將迴車跟回顯去掉
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tmpSet);
    return true;
}

bool KeyBoard::SetCanonicaMode(const termios& originSet)
{
    termios tmpSet = originSet;
    tmpSet.c_lflag |= (ICANON | ECHO);  // 將迴車跟回顯設定回來
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tmpSet);
    return true;
}

bool KeyBoard::DetectArrowKeys(const char& head, const char& skip, const char& arrow)
{
    if (head != '\033')
    {
        return false;
    }

    if (skip != '[')
    {
        return false;
    }

    switch (arrow)
    {
        case 'A': {
            ClearLine();
            std::cout << "Up";
        }
        break;
        case 'B': {
            ClearLine();
            std::cout << "Dn";
        }
        break;
        case 'C': {
            ClearLine();
            std::cout << "Right";
        }
        break;
        case 'D': {
            ClearLine();
            std::cout << "Left";
        }
        break;
    }

    return true;
}

bool KeyBoard::WhileDetectArrowKeys()
{
    char head{};   // 紀錄開頭
    char skip{};   // 紀錄 skip
    char arrow{};  // 紀錄 方向;

    while (true)
    {
        head = getchar();
        if (head == 'q')
        {
            std::cout << std::endl;
            break;
        }

        if (head != '\033')
        {
            continue;
        }

        skip  = getchar();
        arrow = getchar();
        if (!DetectArrowKeys(head, skip, arrow))
        {
            continue;
        }
    }
    return false;
}

void KeyBoard::ClearLine()
{
    std::cout << "\r\033[K";
}
