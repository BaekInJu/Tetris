#include "head.h"

int main(void) {
	int menuNum;  //�ʱ�ȭ�� Ŀ���� ��ġ �� ���� ����
	char cursor;  //������� Ű���� �Է��� ������ ����

	//�� ó�� ������
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
	gotoxy(66, 10);
	printf("��");
	while (1) {
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
			if (cursor == 13) { //���� �Է��� ���� �� �ش� �������� �̵�
				switch (menuNum) {
				case 1:
					system("cls");
					renderLogin();
					break;
				case 2:
					system("cls");
					renderSignup();
					break;
				case 3:
					system("cls");
					renderFindPw();
					break;
				case 4:
					system("cls");
					printf("���α׷��� ���� �մϴ�.");
					exit(0);
					break;
				}
			}
			menuNum = renderTitle(cursor);   // int renderTitle(����� Ű���� �Է� ��);
		}
	}
	return 0;
}