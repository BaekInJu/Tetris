#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")   //�߰����Ӽ� ���� �Է��ϴ°Ͱ� ���� ���

//�����¿� Ű�� ����
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTRE 13
#define SPACE 32

//mysql ����
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "asd123"
#define DB_NAME "phone"
#define CHOP(x) x[strlen(x) - 1] = ' '  //������ ���͸� �������� �ٲ��� �Լ�

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//Ÿ��Ʋ ȭ�� ���� �Լ�
int renderTitle(char);

//�α��� ȭ�� ���� �Լ�
void renderLogin(void);

//ȸ������ ���� �Լ�
void renderSignup(void);

//��й�ȣ ã�� ���� �Լ�
void renderFindPw(void);

//ȸ������ �Լ�
void signup(void);