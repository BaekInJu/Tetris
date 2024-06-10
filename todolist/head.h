#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")   //�߰����Ӽ� ���� �Է��ϴ°Ͱ� ���� ���

//����Ű
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

//mysql ����
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "1234"
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
    int member_id;
    char title[30];
    char content[350];
    char until[30];
}TODO;

//������ ����ü ����
typedef struct message {
    int id;
    int sender_id;
    int receiver_id;
    char reciever[30];
    char content[100];
}MESSAGE;


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
struct todo* getTodo(struct member*, struct member[]);

//������ �Լ�
void profile(struct memebr*, int*);

//������Ʈ �Լ�
int update(struct member*);

//���� ���� �Լ�
void delete(struct member*);

//�α��ε� Ÿ��Ʋ ȭ��
int renderLoginTitle(struct member*, int);

//�ɼ� �Լ�
void option(void);

//��ȭ ��� �������� �Լ�
void getRecord(struct member*, struct message*, int *);

//ȸ���� �������� �Լ�
void getMembers(struct member*, int *);




