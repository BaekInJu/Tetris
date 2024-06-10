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
	printf("◀");
	gotoxy(60, 21);
	printf("뒤로");

	for (int i = 0; i < membersNum; i++) {
		gotoxy(33, y);
		printf("이메일 : %s", members[i].email);
		gotoxy(70, y);
		printf("이름 : %s", members[i].name);
		y++;
	}
	while (1) {
		//키보드 입력이 있을때마다 커서가 움직이며 재 렌더링
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			return;
		}
	}
}