#include <iostream>
#include <Windows.h>
using namespace std;
class Screen {
    HANDLE hwnd;
    public:
    Screen() {
        hwnd = GetstdHandle(STD_OUTPUT_HANDLE);
    }
    Screen& SetColor(int text, int background = 0) {
        SetConsoleTextAttribute(hwnd, (background << 4) | text);
        return *this;
    }
    Screen& SetCursorPos(int x, int y) {
        COORD pt = { x, y};
        SetConsoleCursorPosition( hwnd, pt);
        return *this;
    }

    template <class T>
    Screen& Write(const, T& obj) {
        cout << obj;
        return *this;
    }
};

Screen screen;
int main() {
    screen.SetColor(10).SetCursorPos(20, 5).Write("hello");
    
}