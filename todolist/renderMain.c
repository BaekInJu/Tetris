#include "head.h"

void renderMain(struct member *mp) {
	MEMBER members[100] = { 0 };
	int recordNum = 0;
	int membersNum = 0;
	int y = 10;

	getMembers(members, &membersNum);
	gotoxy(53, 4);
	printf("Member Manager");
	gotoxy(80, y);
	printf("��");
	gotoxy(60, 21);
	printf("�ڷ�");

	for (int i = 0; i < membersNum; i++) {
		gotoxy(33, y);
		printf("�̸��� : %s", members[i].email);
		gotoxy(70, y);
		printf("�̸� : %s", members[i].name);
		y++;
	}
	while (1) {
		//Ű���� �Է��� ���������� Ŀ���� �����̸� �� ������
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			return;
		}
	}
}