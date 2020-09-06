#include <stdio.h>
#include <windows.h>
#include <conio.h>

void draw_ship(int, int);
void E_ship(int, int);
void gotoxy(int, int);
bool wall(int, int, char);


int main() {
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);
    do {
        if (_kbhit)
        {
            ch = _getch();
            if (ch == 'a' && !wall(x, y, 'L')) {
                E_ship(x, y);
                draw_ship(--x, y);
            }
            if (ch == 'd' && !wall(x, y, 'R')) {
                E_ship(x, y);
                draw_ship(++x, y);
            }
            if (ch == 'w' && !wall(x, y, 'U')) {
                E_ship(x, y);
                draw_ship(x, --y);
            }
            if (ch == 's' && !wall(x, y, 'D')) {
                E_ship(x, y);
                draw_ship(x, ++y);
            }
            fflush(stdin);
        }
        Sleep(100);
    } while (ch != 'x');

    return 0;
}


void draw_ship(int x, int y) {
    gotoxy(x, y);
    printf("<-0-> ");
}

void E_ship(int x, int y) {
    gotoxy(x, y);
    printf("      ");
}

void gotoxy(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool wall(int x, int y, char direction) {
    switch (direction) {
    case 'U':
        if (y <= 0) return 1;
        else return 0;
    case 'D':
        if (y >= 20) return 1;
        else return 0;
    case 'R':
        if (x >= 80) return 1;
        else return 0;
    case 'L':
        if (x <= 0) return 1;
        else return 0;
    }
}
