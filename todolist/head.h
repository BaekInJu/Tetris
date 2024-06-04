#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")   //�߰����Ӽ� ���� �Է��ϴ°Ͱ� ���� ���

//mysql ����
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "asd123"
#define DB_NAME "todolist"
#define CHOP(x) x[strlen(x) - 1] = ' '  //������ ���͸� �������� �ٲ��� �Լ�

//ȸ�� ���� ����ü ����
typedef struct member {
    int id;
    char email[30];
    char name[30];
    char pw[30];
    char chPw[30];
}MEMBER;

//���� ��� ����ü ����
typedef struct todo {
    int id;
    char content[30];
}TODO;


//gotoxy
void gotoxy(int, int);

//Ÿ��Ʋ ȭ�� ���� �Լ�
int renderTitle(char);

//�α��� ȭ�� ���� �Լ�
struct member renderLogin(void);

//ȸ������ ���� �Լ�
void renderSignup(void);

//��й�ȣ ã�� ���� �Լ�
void renderFindPw(void);

//ȸ������ �Լ�
int signup(struct member*);

//�α��� �Լ�
int login(struct member*);

//���������� ���� �Լ�
void renderMain(struct member*);

//��й�ȣ ã�� �Լ�
int findPw(struct member*);

//���� ��� �ҷ����� �Լ�
struct todo* todo(struct member*, struct todo[], struct todo*, int*);

//������ �Լ�
void profile(struct memebr*);

//������Ʈ �Լ�
int update(struct member*);

//���� ���� �Լ�
void delete(struct member*);

