#include <stdio.h>

int renderTitle(char ch) {
	static int point = -1;  //�Լ��� ����ŵ� �����ϵ��� static ����
	static int menuNum = -1;

	if (point == -1) {
		point = 10;  //�� ó������ Ŀ���� 1�� �����Ѵ�.
	}
	if (menuNum == -1) {
		menuNum = 1;
	}

	switch (ch) {
		//���� ����Ű
	case 72:
		//�̹� Ŀ���� �� ���϶��� Ŀ�� �ȿ�����
		if (point == 10) {
			return menuNum;
			break;
		}
		//�� ������
		system("cls");
		//point�� ����
		point-= 2;
		menuNum--;
		gotoxy(54, 4);
		printf("To Do List");
		gotoxy(56, 10);
		printf("�α���\n");
		gotoxy(55, 12);
		printf("ȸ������\n");
		gotoxy(55, 14);
		printf("����ã��\n");
		gotoxy(55, 16);
		printf("��    ��\n");
		gotoxy(66, point);
		printf("��");
		return menuNum;
		break;

		//�Ʒ��� ����Ű
	case 80:
		//�̹� Ŀ���� �� �Ʒ��϶��� Ŀ�� �ȿ�����
		if (point == 16) {
			return menuNum;
			break;
		}
		//�� ������
		system("cls");
		//point�� ����
		point+= 2;
		menuNum++;
		gotoxy(54, 4);
		printf("To Do List");
		gotoxy(56, 10);
		printf("�α���\n");
		gotoxy(55, 12);
		printf("ȸ������\n");
		gotoxy(55, 14);
		printf("����ã��\n");
		gotoxy(55, 16);
		printf("��    ��\n");
		gotoxy(66, point);
		printf("��");
		return menuNum;
		break;
	}
}