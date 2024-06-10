#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")   //추가종속성 직접 입력하는것과 같은 기능

//방향키
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

//mysql 정보
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "1234"
#define DB_NAME "todolist"
#define CHOP(x) x[strlen(x) - 1] = ' '  //마지막 엔터를 공백으로 바꿔줄 함수

//회원 정보 구조체 선언
typedef struct member {
    int id;
    char email[30];
    char name[30];
    char pw[30];
    char chPw[30];
}MEMBER;


//할일 목록 구조체 선언
typedef struct todo {
    int id;
    int member_id;
    char title[30];
    char content[350];
    char until[30];
}TODO;

//메제시 구조체 선언
typedef struct message {
    int id;
    int sender_id;
    int receiver_id;
    char reciever[30];
    char content[100];
}MESSAGE;


//gotoxy
void gotoxy(int, int);

//타이틀 화면 렌더 함수
int renderTitle(char);

//로그인 화면 렌더 함수
struct member renderLogin(void);

//회원가입 렌더 함수
void renderSignup(void);

//비밀번호 찾기 렌더 함수
void renderFindPw(void);

//회원가입 함수
int signup(struct member*);

//로그인 함수
int login(struct member*);

//메인페이지 렌더 함수
void renderMain(struct member*);

//비밀번호 찾기 함수
int findPw(struct member*);

//할일 목록 불러오는 함수
struct todo* getTodo(struct member*, struct member[]);

//프로필 함수
void profile(struct memebr*, int*);

//업데이트 함수
int update(struct member*);

//계정 삭제 함수
void delete(struct member*);

//로그인된 타이틀 화면
int renderLoginTitle(struct member*, int);

//옵션 함수
void option(void);

//대화 기록 가져오기 함수
void getRecord(struct member*, struct message*, int *);

//회원들 가져오기 함수
void getMembers(struct member*, int *);




