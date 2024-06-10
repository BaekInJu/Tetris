#include "head.h"

int renderLoginTitle(struct member *mp, char ch) {
	int y = 10;
	char cursor;
	
	gotoxy(53, 4);
	printf("Member Manager");
	gotoxy(52, 6);
	printf("%s님 안녕하세요!", mp->name);
	gotoxy(55, 10);
	printf("메인화면\n");
	gotoxy(55, 12);
	printf("계정설정\n");
	gotoxy(55, 14);
	printf("로그아웃\n");
	gotoxy(55, 16);
	printf("설    정\n");
	gotoxy(55, 18);
	printf("종    료\n");
	gotoxy(66, y);
	printf("◀");

	while (1) {
		//키보드 입력이 있을때마다 커서가 움직이며 재 렌더링
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			cursor = _getch();  // 입력된 키를 읽음
			switch (cursor) {
			case UP:
				if (y > 10) {
					gotoxy(66, y);
					printf("  "); // 현재 위치의 화살표 지우기
					y -= 2;
					gotoxy(66, y);
					printf("◀");
				}
				break;
			case DOWN:
				if (y < 18) {
					gotoxy(66, y);
					printf("  "); // 현재 위치의 화살표 지우기
					y += 2;
					gotoxy(66, y);
					printf("◀");
				}
				break;
			case ENTER:
				return y;
			}
		}
	}
}