#include "head.h"

void option(void) {

	int y = 12;
	int idx = 0;
	int color[] = { 15, 1, 2, 3, 5 };
	char colorName[10][10] = {"���", "�Ķ�", "�ʷ�", "�ϴ�", "����"};
	char cursor;

	gotoxy(55, 4);
	printf("�ɼ�");
	gotoxy(55, 10);
	printf("����\n");
	gotoxy(55, 12);
	printf("���");
	gotoxy(53, 12);
	printf("��");
	gotoxy(60, 12);
	printf("��");

	while (1) {
		//Ű���� �Է��� ���������� Ŀ���� �����̸� �� ������
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
			switch (cursor) {
			case LEFT:
				idx--;
				if (idx == -1) {
					idx = 4;
				}
				gotoxy(55, 12);
				printf("  ");
				gotoxy(55, 12);
				printf("%s", colorName[idx]);
				break;
			case RIGHT:
				idx++;
				if (idx == 5) {
					idx = 0;
				}
				gotoxy(55, 12);
				printf("  ");
				gotoxy(55, 12);
				printf("%s", colorName[idx]);
				break;
			case ENTER:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[idx]);
				return;

			}
		}
	}
}