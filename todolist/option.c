#include "head.h"

void option(void) {

	int y = 12;
	int idx = 0;
	int color[] = { 15, 1, 2, 3, 5 };
	char colorName[10][10] = {"흰색", "파랑", "초록", "하늘", "보라"};
	char cursor;

	gotoxy(55, 4);
	printf("옵션");
	gotoxy(55, 10);
	printf("색깔\n");
	gotoxy(55, 12);
	printf("흰색");
	gotoxy(53, 12);
	printf("◀");
	gotoxy(60, 12);
	printf("▶");

	while (1) {
		//키보드 입력이 있을때마다 커서가 움직이며 재 렌더링
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			cursor = _getch();  // 입력된 키를 읽음
			switch (cursor) {
			case LEFT:
				idx--;
				if (idx == -1) {
					idx = 4;
				}
				gotoxy(55, 12);
				printf("  ");
				gotoxy(55, 12);
				printf("%s", colorName[idx]);
				break;
			case RIGHT:
				idx++;
				if (idx == 5) {
					idx = 0;
				}
				gotoxy(55, 12);
				printf("  ");
				gotoxy(55, 12);
				printf("%s", colorName[idx]);
				break;
			case ENTER:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[idx]);
				return;

			}
		}
	}
}