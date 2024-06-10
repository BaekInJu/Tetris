#include "head.h"

int renderTitle(char ch) {

	int y = 10;
	char cursor;
	
	gotoxy(53, 4);
	printf("Member Manager");
	gotoxy(56, 10);
	printf("로그인\n");
	gotoxy(55, 12);
	printf("회원가입\n");
	gotoxy(55, 14);
	printf("계정찾기\n");
	gotoxy(55, 16);
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
				if (y < 16) {
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