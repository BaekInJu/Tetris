#include "head.h"

void renderMain(struct member *mp) {
	int y = 10;
	char cursor;

	TODO todo[100] = {0};
	TODO* to;
	to = getTodo(&mp, todo);
	gotoxy(54, 4);
	printf("To Do List");
	gotoxy(52, 6);
	printf("%s", to->title);
	gotoxy(55, 10);
	printf("메인화면\n");
	gotoxy(55, 12);
	printf("계정설정\n");
	gotoxy(55, 14);
	printf("로그아웃\n");
	gotoxy(55, 16);
	printf("설    정\n");
	gotoxy(55, 18);
	printf("종    료\n");
	gotoxy(66, y);
	printf("◀");
}