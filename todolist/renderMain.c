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
	printf("����ȭ��\n");
	gotoxy(55, 12);
	printf("��������\n");
	gotoxy(55, 14);
	printf("�α׾ƿ�\n");
	gotoxy(55, 16);
	printf("��    ��\n");
	gotoxy(55, 18);
	printf("��    ��\n");
	gotoxy(66, y);
	printf("��");
}