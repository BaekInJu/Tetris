#include <stdio.h>

void renderSignup() {
	int y = 6;  //Ŀ���� y���� ����
	int cursor;   //�Էµ� Ű���� ���� ����

	//���� ���ڸ� �ϳ��� ���� �� ���� ����
	char inp;
	//�� ������ ���� ���ڹ迭
	char name[20];
	char email[30];
	char pw[30];
	char checkPw[30];

	//�迭�� ���ڸ� �ϳ��� ���� �� �ű� ������ �ε����� ������ ���� ����
	int i = 0;

	//������ �ѹ��� ������ ����
	char buffer[200];

	//�� ó�� ȣ�� �Ǿ����� ������
	gotoxy(77, y);
	printf("��");
	gotoxy(59, 1);
	printf("ȸ������");
	gotoxy(33, 6);
	printf("�̸�");
	gotoxy(50, 6);
	printf("��");
	gotoxy(50, 5);
	printf("��������������������������������������������������");
	gotoxy(50, 7);
	printf("��������������������������������������������������");
	gotoxy(74, 6);
	printf("��");

	gotoxy(33, 9);
	printf("�̸���");
	gotoxy(50, 9);
	printf("��");
	gotoxy(50, 8);
	printf("��������������������������������������������������");
	gotoxy(50, 10);
	printf("��������������������������������������������������");
	gotoxy(74, 9);
	printf("��");

	gotoxy(33, 12);
	printf("��й�ȣ");
	gotoxy(50, 12);
	printf("��");
	gotoxy(50, 11);
	printf("��������������������������������������������������");
	gotoxy(50, 13);
	printf("��������������������������������������������������");
	gotoxy(74, 12);
	printf("��");

	gotoxy(33, 15);
	printf("��й�ȣ Ȯ��");
	gotoxy(50, 15);
	printf("��");
	gotoxy(50, 14);
	printf("��������������������������������������������������");
	gotoxy(50, 16);
	printf("��������������������������������������������������");
	gotoxy(74, 15);
	printf("��");

	gotoxy(60, 18);
	printf("����");

	gotoxy(60, 21);
	printf("�ڷ�");
	
	
	while (1) {
		//Ű���� �Է��� ���������� Ŀ���� �����̸� �� ������
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
			switch (cursor) {
			case 72:
				if (y == 6) {
					continue;
				}
				else {
					y -= 3;
				}
				break;
			case 80:
				if (y == 21) {
					continue;
				}
				else {
					y += 3;
				}
				break;
			case 13:
				if (y == 21) {
					system("cls");
					return;
				}
				break;
				//Ű���� ��, �Ʒ�, ���͸� ������ �Է��� ������ ��
			default:
				name[i] = cursor;
				name[i + 1] = '\0';
				i++;
				break;
			}
			
			system("cls");
			gotoxy(77, y);
			printf("��");
			gotoxy(59, 1);
			printf("ȸ������");
			gotoxy(33, 6);
			printf("�̸�");
			gotoxy(50, 6);
			printf("��");
			gotoxy(50, 5);
			printf("��������������������������������������������������");
			gotoxy(50, 7);
			printf("��������������������������������������������������");
			gotoxy(74, 6);
			printf("��");
			gotoxy(52, 6);
			printf("%s", name);

			gotoxy(33, 9);
			printf("���̵�");
			gotoxy(50, 9);
			printf("��");
			gotoxy(50, 8);
			printf("��������������������������������������������������");
			gotoxy(50, 10);
			printf("��������������������������������������������������");
			gotoxy(74, 9);
			printf("��");

			gotoxy(33, 12);
			printf("��й�ȣ");
			gotoxy(50, 12);
			printf("��");
			gotoxy(50, 11);
			printf("��������������������������������������������������");
			gotoxy(50, 13);
			printf("��������������������������������������������������");
			gotoxy(74, 12);
			printf("��");

			gotoxy(33, 15);
			printf("��й�ȣ Ȯ��");
			gotoxy(50, 15);
			printf("��");
			gotoxy(50, 14);
			printf("��������������������������������������������������");
			gotoxy(50, 16);
			printf("��������������������������������������������������");
			gotoxy(74, 15);
			printf("��");

			gotoxy(60, 18);
			printf("����");

			gotoxy(60, 21);
			printf("�ڷ�");
		}
	}
}