#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void renderLogin() {
	int y = 6;  //Ŀ���� y���� ����
	int cursor;   //�Էµ� Ű���� ���� ����

	char email[30];
	char pw[30];
	char buffer[70];
	int i = 0;   //�ε����� �����ϱ� ���� ����
	char ptPw[30];

	//�α��� ��û�� ���� ������ ���� ����
	int status = 0;
	//1: ����
	//2: ���� �̸���
	//3: ��й�ȣ ����ġ

	//�� ó�� ȣ�� �Ǿ����� ������
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
	printf("��й�ȣ");
	gotoxy(50, 9);
	printf("��");
	gotoxy(50, 8);
	printf("����������������������������������������������������������������������");
	gotoxy(50, 10); 
	printf("����������������������������������������������������������������������");
	gotoxy(84, 9);
	printf("��");

	gotoxy(59, 12);
	printf("�α���");
	gotoxy(60, 15);
	printf("�ڷ�");

	gotoxy(52, 6);
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
						status = signup();
					}
					break;
				case 8:   //BackSpace�� �������� ��� �׸� �ʱ�ȭ
					printf("%c", cursor);
					for (int j = 0; j < sizeof(email); j++) {
						email[j] = 0;
						pw[j] = 0;
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
					printf("��й�ȣ");
					gotoxy(50, 9);
					printf("��");
					gotoxy(50, 8);
					printf("����������������������������������������������������������������������");
					gotoxy(50, 10);
					printf("����������������������������������������������������������������������");
					gotoxy(84, 9);
					printf("��");

					gotoxy(59, 12);
					printf("�α���");
					gotoxy(60, 15);
					printf("�ڷ�");
					break;
				default: // �ٸ� �Է��� �̸��� �߰�
					if (y == 6 && strlen(email) < 29) {
						email[i] = cursor;
						email[i + 1] = '\0';
						gotoxy(52, 6);
						printf("%-29s", email);
					}
					else if (y == 9 && strlen(pw) < 29) {
						pw[i] = cursor;
						pw[i + 1] = '\0';
						ptPw[i] = '*';
						ptPw[i + 1] = '\0';
						gotoxy(52, 9);
						printf("%-29s", ptPw);
					}
					i++;
					break;
				}
			}
		}

	}
}
