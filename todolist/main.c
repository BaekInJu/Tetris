#include "head.h"

int main(void) {

	int menuNum = 0;  //�ʱ�ȭ�� Ŀ���� ��ġ �� ���� ����
	char cursor;  //������� Ű���� �Է��� ������ ����
	boolean login = 0;  // �α��� �� �������� Ȯ���ϴ� ����
	struct member mp;

	//�� ó�� ������
	gotoxy(52, 4);
	printf("Member Manager");
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
					mp = renderLogin(&login);
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
		if (login) {
			system("cls");
			profile(&mp, &login);
			gotoxy(52, 4);
			printf("Member Manager");
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
		}
	}
	return 0;
}