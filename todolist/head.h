#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

//상하좌우 키값 저장
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTRE 13
#define SPACE 32

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//타이틀 화면 렌더 함수
int renderTitle(char);