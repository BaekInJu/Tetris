#include "head.h"

struct member renderLogin(int* cp) {
	int y = 6;  //Ŀ���� y���� ����
	int cursor;   //�Էµ� Ű���� ���� ����

	MEMBER m1 = { "", "", "", "" };
	MEMBER* mp = &m1;

	
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
						*cp = 0;
						return m1;
					}
					else if (y == 12) {
						gotoxy(53, 20);
						//������ �޼��� ����� 
						printf("                                         ");
						status = login(mp);
						switch (status) {
						case 1:
							gotoxy(57, 20);
							printf("�α��� ����");
							*cp = 1;
							Sleep(2000);
							system("cls");
							return m1;
							break;
						case 2:
							gotoxy(56, 20);
							printf("���� �̸���");
							break;
						case 3:
							gotoxy(53, 20);
							printf("��й�ȣ ����ġ");
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
					if (y == 6 && strlen(m1.email) < 29) {
						m1.email[i] = cursor;
						m1.email[i + 1] = '\0';
						gotoxy(52, 6);
						printf("%-29s", m1.email);
					}
					else if (y == 9 && strlen(m1.pw) < 29) {
						m1.pw[i] = cursor;
						m1.pw[i + 1] = '\0';
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
