#include "head.h"

int main(void) {
	int menuNum = 0;  //�ʱ�ȭ�� Ŀ���� ��ġ �� ���� ����
	char cursor;  //������� Ű���� �Է��� ������ ����
	int login = 0;  // �α��� �� �������� Ȯ���ϴ� ����
	struct member mp;
	int y = 6;
	while (1) {
		if (!login) {
			system("cls");
			y = renderTitle(y);
		}
		else {
			system("cls");
			y = renderLoginTitle(&mp, y);
		}
		if (!login) {
			switch (y) {
			case 10:
				system("cls");
				mp = renderLogin(&login);
				break;
			case 12:
				system("cls");
				renderSignup();
				break;
			case 14:
				system("cls");
				renderFindPw();
				break;
			case 16:
				system("cls");
				printf("���α׷��� ���� �մϴ�.");
				exit(0);
				break;
			}
		}
		else {
			switch (y) {
			case 10:
				system("cls");
				renderMain(&mp);
				break;
			case 12:
				system("cls");
				profile(&mp, &login);
				break;
			case 14:
				login = 0;
				break;
				system("cls");
				renderFindPw();
				break;
			case 16:
				system("cls");
				option();
				break;
			case 18:
				system("cls");
				printf("���α׷��� ���� �մϴ�.");
				exit(0);
				break;
			}
		}
	}
	return 0;
}