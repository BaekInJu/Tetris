#include "head.h"

void renderMain(struct member *mp) {
	int y = 2;
	int cursor;


	TODO doArr[3] = { 0 };   //���� ����Ʈ�� ������ �迭
	TODO* tp = doArr;
	TODO t1 = {0, ""};
	TODO* t1p = &t1;
	struct todo* t2;
	int count = 0;   //�׸� ���� ���� ����

	t2 = todo(mp, tp, t1p, &count);

	while (1) {
		for (int i = 0; i < sizeof(doArr)-1; i++) {
			y += 2;
			gotoxy(20, y);
			printf("%s", t2->content);
		}
	}

	gotoxy(77, y);
	printf("��");
	gotoxy(60, 2);
	printf("�ڷ�");
	gotoxy(58, 4);
	printf("�α׾ƿ�");
	gotoxy(60, 8);
	printf("�߰�");
	gotoxy(50, 6);
	printf("��");
	gotoxy(50, 5);
	printf("��������������������������������������������������");
	gotoxy(50, 7);
	printf("��������������������������������������������������");
	gotoxy(74, 6);
	printf("��");
	while (1) {
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
			if (cursor == 0 || cursor == 224) {
				cursor = _getch();
				switch (cursor) {
					if (cursor == 0 || cursor == 224) {
						cursor = _getch();
						switch (cursor) {
						case 72: // ���� ȭ��ǥ
							if (y > 2) {
								gotoxy(87, y);
								printf("  "); // ���� ��ġ�� ȭ��ǥ �����
								y -= 2;
							}
							break;
						case 80: // �Ʒ��� ȭ��ǥ
							if (y < 4) {
								gotoxy(87, y);
								printf("  "); // ���� ��ġ�� ȭ��ǥ �����
								y += 2;
							}
							break;
						}
						gotoxy(87, y);
						printf("��");
					}
					else {
						// �Ϲ� Ű �Է� ó��
						switch (cursor) {
						case 13: // ����
							if (y == 2) {
								system("cls");
								return;
							}
							else if (y == 8) {
								gotoxy(53, 20);
								//������ �޼��� ����� 
								printf("                                         ");
							}
							break;
						}
					}
				}
			}
		}
	}
}