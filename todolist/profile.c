#include "head.h"

void profile(struct member* mpp, int* cp) {
	int y = 9;  //Ŀ���� y���� ����
	int cursor;   //�Էµ� Ű���� ���� ����

	MEMBER m1 = *mpp;  //�Ѿ�� ������ ������� ����ü
	MEMBER* mp = &m1;

	MEMBER m2 = { 0 };   //���ο� ������ ������ ����ü
	MEMBER* mp2 = &m2;

	strcpy(m2.email, m1.email);
	strcpy(m2.name, m1.name);
	strcpy(m2.pw, m1.pw);

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
	gotoxy(58, 1);
	printf("��������");
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
	gotoxy(52, 6);
	printf("%s", mpp->email);

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
	gotoxy(52, 9);
	printf("%s", mpp->name);

	gotoxy(33, 12);
	printf("��й�ȣ");
	gotoxy(50, 12);
	printf("��");
	gotoxy(50, 11);
	printf("����������������������������������������������������������������������");
	gotoxy(50, 13);
	printf("����������������������������������������������������������������������");
	gotoxy(84, 12);
	printf("��");
	gotoxy(52, 12);
	printf("%s", mpp->pw);

	gotoxy(60, 15);
	printf("����");

	gotoxy(60, 18);
	printf("����");

	gotoxy(60, 21);
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
					if (y > 9) {
						gotoxy(87, y);
						printf("  "); // ���� ��ġ�� ȭ��ǥ �����
						y -= 3;
						i = 0;   //�ε��� �ʱ�ȭ
					}
					break;
				case 80: // �Ʒ��� ȭ��ǥ
					if (y < 21) {
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
					if (y == 21) {
						system("cls");
						return;
					}
					else if (y == 18) {
						gotoxy(53, 20);
						//������ �޼��� ����� 
						printf("                                         ");
						delete(&m1);  //���� ���� �Լ� ȣ��
						gotoxy(58, 26);
						printf("���� �Ϸ�");
						Sleep(2000);
						*cp = 0;
						system("cls");
						return;
					}
					else if (y == 15) {
						gotoxy(53, 20);
						//������ �޼��� ����� 
						printf("                                         ");
						status = update(mp2);
						if ((!strcmp(m1.name, m2.name))&&(!strcmp(m1.pw, m2.pw))) {
							status = 2;
						}
						switch (status) {
						case 1:
							gotoxy(50, 26);
							printf("���� �Ϸ� (�ٽ� �α��� ���ּ���)");
							Sleep(2000);
							system("cls");
							*cp = 0;
							return mp;
							break;
						case 2:
							gotoxy(56, 26);
							printf("�ٲ� ������ ����");
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
					y = 9;
					system("cls");
					gotoxy(87, y);
					printf("��");
					gotoxy(58, 1);
					printf("��������");
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
					gotoxy(52, 6);
					printf("%s", mpp->email);

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
					gotoxy(52, 9);
					printf("%s", mpp->name);

					gotoxy(33, 12);
					printf("��й�ȣ");
					gotoxy(50, 12);
					printf("��");
					gotoxy(50, 11);
					printf("����������������������������������������������������������������������");
					gotoxy(50, 13);
					printf("����������������������������������������������������������������������");
					gotoxy(84, 12);
					printf("��");
					gotoxy(52, 12);
					printf("%s", mpp->pw);

					gotoxy(60, 15);
					printf("����");

					gotoxy(60, 18);
					printf("����");

					gotoxy(60, 21);
					printf("�ڷ�");
					break;
				default: // �ٸ� �Է��� �̸��� �߰�
					if (y == 6 && strlen(m2.email) < 29) {
						m2.email[i] = cursor;
						m2.email[i + 1] = '\0';
						gotoxy(52, 6);
						printf("%-29s", m2.email);
					}
					else if (y == 9 && strlen(m2.name) < 29) {
						m2.name[i] = cursor;
						m2.name[i + 1] = '\0';
						gotoxy(52, 9);
						printf("%-29s", m2.name);
					}
					else {
						m2.pw[i] = cursor;
						m2.pw[i + 1] = '\0';
						gotoxy(52, 12);
						printf("%-29s", m2.pw);
					}
					i++;
					break;
				}
			}
		}

	}
}
