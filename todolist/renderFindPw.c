#include "head.h"

void renderFindPw() {
	int y = 6;  //Ŀ���� y���� ����
	int cursor;   //�Էµ� Ű���� ���� ����
	int i = 0;
	MEMBER m1 = { "", "", "", "" };
	MEMBER* mp = &m1;

	int status;
	// 1. ���� ��й�ȣ ��ȯ
	// 2. email�� ����
	// 3. email�� �̸��� �ٸ�

	//�� ó�� ȣ�� �Ǿ����� ������
	gotoxy(77, y);
	printf("��");
	gotoxy(55, 1);
	printf("��й�ȣ ã��");
	gotoxy(33, 6);
	printf("�̸���");
	gotoxy(50, 6);
	printf("��");
	gotoxy(50, 5);
	printf("��������������������������������������������������");
	gotoxy(50, 7);
	printf("��������������������������������������������������");
	gotoxy(74, 6);
	printf("��");

	gotoxy(33, 9);
	printf("�̸�");
	gotoxy(50, 9);
	printf("��");
	gotoxy(50, 8);
	printf("��������������������������������������������������");
	gotoxy(50, 10);
	printf("��������������������������������������������������");
	gotoxy(74, 9);
	printf("��");

	gotoxy(60, 12);
	printf("ã��");

	gotoxy(60, 15);
	printf("�ڷ�");


	while (1) {
		//Ű���� �Է��� ���������� Ŀ���� �����̸� �� ������
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
			if (cursor == 0 || cursor == 224) {
				cursor = _getch();
				switch (cursor) {
				case 72: // ���� ȭ��ǥ
					if (y > 6) {
						gotoxy(87, y);
						printf("  "); // ���� ��ġ�� ȭ��ǥ �����
						y -= 3;
						i = 0;   //�ε��� �ʱ�ȭ
					}
					break;
				case 80: // �Ʒ��� ȭ��ǥ
					if (y < 15) {
						gotoxy(87, y);
						printf("  "); // ���� ��ġ�� ȭ��ǥ �����
						y += 3;
						i = 0;   //�ε��� �ʱ�ȭ
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
					if (y == 15) {
						system("cls");
						return;
					}
					else if (y == 12) {
						gotoxy(53, 20);
						//������ �޼��� ����� 
						printf("                                         ");
						status = findPw(mp);   //���¿� ��й�ȣ�� ���Ϲ޴´�.

						switch (status) {
						case 1:
							gotoxy(57, 20);
							printf("%s", m1.pw);
							Sleep(2000);
							system("cls");
							return;
							break;
						case 2:
							gotoxy(56, 20);
							printf("���� �̸���");
							break;
						case 3:
							gotoxy(53, 20);
							printf("�̸� ����ġ");
							break;
						}
					}
					break;
				case 8:   //BackSpace�� �������� ��� �׸� �ʱ�ȭ
					printf("%c", cursor);
					for (int j = 0; j < sizeof(m1.email); j++) {
						m1.email[j] = 0;
						m1.pw[j] = 0;
					}
					y = 6;
					system("cls");
					gotoxy(87, y);
					printf("��");
					gotoxy(59, 1);
					printf("�α���");
					gotoxy(33, 6);
					printf("�̸���");
					gotoxy(50, 6);
					printf("��");
					gotoxy(50, 5);
					printf("����������������������������������������������������������������������");
					gotoxy(50, 7);
					printf("����������������������������������������������������������������������");
					gotoxy(84, 6);
					printf("��");

					gotoxy(33, 9);
					printf("�̸�");
					gotoxy(50, 9);
					printf("��");
					gotoxy(50, 8);
					printf("����������������������������������������������������������������������");
					gotoxy(50, 10);
					printf("����������������������������������������������������������������������");
					gotoxy(84, 9);
					printf("��");

					gotoxy(60, 12);
					printf("ã��");

					gotoxy(60, 15);
					printf("�ڷ�");
					break;
				default: // �ٸ� �Է��� �̸��� �߰�
					if (y == 6 && strlen(m1.email) < 29) {
						m1.email[i] = cursor;
						m1.email[i + 1] = '\0';
						gotoxy(52, 6);
						printf("%-29s", m1.email);
					}
					else if (y == 9 && strlen(m1.name) < 29) {
						m1.name[i] = cursor;
						m1.name[i + 1] = '\0';
						gotoxy(52, 9);
						printf("%-29s", m1.name);
					}
					i++;
					break;
				}
			}
		}
	}
}
