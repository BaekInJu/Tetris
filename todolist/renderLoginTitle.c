#include "head.h"

int renderLoginTitle(struct member *mp, char ch) {
	int y = 10;
	char cursor;
	
	gotoxy(53, 4);
	printf("Member Manager");
	gotoxy(52, 6);
	printf("%s�� �ȳ��ϼ���!", mp->name);
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

	while (1) {
		//Ű���� �Է��� ���������� Ŀ���� �����̸� �� ������
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
			switch (cursor) {
			case UP:
				if (y > 10) {
					gotoxy(66, y);
					printf("  "); // ���� ��ġ�� ȭ��ǥ �����
					y -= 2;
					gotoxy(66, y);
					printf("��");
				}
				break;
			case DOWN:
				if (y < 18) {
					gotoxy(66, y);
					printf("  "); // ���� ��ġ�� ȭ��ǥ �����
					y += 2;
					gotoxy(66, y);
					printf("��");
				}
				break;
			case ENTER:
				return y;
			}
		}
	}
}