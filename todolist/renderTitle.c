#include <stdio.h>

int renderTitle(char ch) {
	static int point = -1;  //�Լ��� ����ŵ� �����ϵ��� static ����

	if (point == -1) {
		point = 1;  //�� ó������ Ŀ���� 1�� �����Ѵ�.
	}

	switch (ch) {
		//���� ����Ű
	case 72:
		//�̹� Ŀ���� �� ���϶��� Ŀ�� �ȿ�����
		if (point <= 1) {
			return point;
			break;
		}
		//�� ������
		system("cls");
		//point�� ����
		point--;
		gotoxy(0, 1);
		printf("1. �α���\n");
		printf("2. ȸ������\n");
		printf("3. ���ӽ���\n");
		printf("4. ���Ӽ���\n");
		printf("5. ��������\n");
		gotoxy(14, point);
		printf("��");
		return point;
		break;

		//�Ʒ��� ����Ű
	case 80:
		//�̹� Ŀ���� �� �Ʒ��϶��� Ŀ�� �ȿ�����
		if (point >= 5) {
			return point;
			break;
		}
		//�� ������
		system("cls");
		//point�� ����
		point++;
		gotoxy(0, 1);
		printf("1. �α���\n");
		printf("2. ȸ������\n");
		printf("3. ���ӽ���\n");
		printf("4. ���Ӽ���\n");
		printf("5. ��������\n");
		gotoxy(14, point);
		printf("��");
		return point;
		break;

		//����Ű
	case 13:
		printf("%d", point);
	}
}