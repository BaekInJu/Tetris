#include "head.h"

int main(void) {
	int menuNum;  //�ʱ�ȭ�� Ŀ���� ��ġ �� ���� ����
	char cursor;  //������� Ű���� �Է��� ������ ����

	//�� ó�� ������
	gotoxy(0, 1);
	printf("1. �α���\n");
	printf("2. ȸ������\n");
	printf("3. ���ӽ���\n");
	printf("4. ���Ӽ���\n");
	printf("5. ��������\n");
	gotoxy(14, 1);
	printf("��");
	while (1) {
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
			if (cursor == 13) {
				switch (menuNum) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					system("cls");
					printf("������ ���� �մϴ�.");
					exit(0);
					break;

				}
			}
			menuNum = renderTitle(cursor);   // int renderTitle(����� Ű���� �Է� ��);
		}
	}
	return 0;
}