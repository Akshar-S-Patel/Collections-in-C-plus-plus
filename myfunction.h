#ifndef _myfunction_h
#define _myfunction_h

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>

using namespace std;


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void clrscr() {
    system("cls");
}


void ChangeColor(int Text,int Bg) {
    /**
    0 black , 1 blue , 2 green , 3 cyan , 4 red , 5 magenta , 6 brown , 7 light gray ,
    8 lark gray , 9 light blue , 10 light green , 11 light cyan , 12 light red ,
    13 light magenta , 14 yellow , 15 white
    */
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ( Text + (Bg * 16)));
}

#endif /// _myfunction_h
