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

#pragma once

#include <termios.h>

class KeyBoard {
   public:
    /**
     * @brief 創建時設定終端為非規範模式
     *
     */
    KeyBoard();

    /**
     * @brief 結束時規範回來
     *
     */
    ~KeyBoard();

    /**
     * @brief 取得當前終端機的設定
     *
     * @param set 需要取得的設定
     * @return true
     * @return false
     */
    bool GetTerminoSet(termios &set);

    /**
     * @brief 將原有的終端設定改成非規範式的, 不用輸入迴車鍵, 也不顯式輸入的字符
     *
     * @param originSet
     * @return true
     * @return false
     */
    bool SetNoneCanonicalMode(const termios &originSet);

    /**
     * @brief 將終端設定改回原本的模式
     *
     * @param originSet
     * @return true
     * @return false
     */
    bool SetCanonicaMode(const termios &originSet);

    /**
     * @brief 方向鍵讀取為三個字符, 用三個字符讀取代表方向鍵
     *
     * @param head \033
     * @param skip [
     * @param arrow A up, B dn, C right, D left
     * @return true
     * @return false
     */
    bool DetectArrowKeys(const char &head, const char &skip, const char &arrow);

    /**
     * @brief 一直偵測方向鍵, 直到不是輸入方向鍵
     *
     * @return true
     * @return false
     */
    bool WhileDetectArrowKeys();

    /**
     * @brief 清除同一行的所有文字
     *
     */
    void ClearLine();

   private:
    termios originSet{};  // 記錄預設的鍵盤設定
};
