#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")   //추가종속성 직접 입력하는것과 같은 기능

//상하좌우 키값 저장
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTRE 13
#define SPACE 32

//mysql 정보
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "asd123"
#define DB_NAME "phone"
#define CHOP(x) x[strlen(x) - 1] = ' '  //마지막 엔터를 공백으로 바꿔줄 함수

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//타이틀 화면 렌더 함수
int renderTitle(char);

//로그인 화면 렌더 함수
void renderLogin(void);

//회원가입 렌더 함수
void renderSignup(void);

//비밀번호 찾기 렌더 함수
void renderFindPw(void);

//회원가입 함수
void signup(void);