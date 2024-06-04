#include "head.h"

void renderMain(struct member *mp) {
	int y = 2;
	int cursor;


	TODO doArr[3] = { 0 };   //할일 리스트를 저장할 배열
	TODO* tp = doArr;
	TODO t1 = {0, ""};
	TODO* t1p = &t1;
	struct todo* t2;
	int count = 0;   //항목 갯수 저장 변수

	t2 = todo(mp, tp, t1p, &count);

	while (1) {
		for (int i = 0; i < sizeof(doArr)-1; i++) {
			y += 2;
			gotoxy(20, y);
			printf("%s", t2->content);
		}
	}

	gotoxy(77, y);
	printf("◀");
	gotoxy(60, 2);
	printf("뒤로");
	gotoxy(58, 4);
	printf("로그아웃");
	gotoxy(60, 8);
	printf("추가");
	gotoxy(50, 6);
	printf("│");
	gotoxy(50, 5);
	printf("┌───────────────────────┐");
	gotoxy(50, 7);
	printf("└───────────────────────┘");
	gotoxy(74, 6);
	printf("│");
	while (1) {
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			cursor = _getch();  // 입력된 키를 읽음
			if (cursor == 0 || cursor == 224) {
				cursor = _getch();
				switch (cursor) {
					if (cursor == 0 || cursor == 224) {
						cursor = _getch();
						switch (cursor) {
						case 72: // 위쪽 화살표
							if (y > 2) {
								gotoxy(87, y);
								printf("  "); // 현재 위치의 화살표 지우기
								y -= 2;
							}
							break;
						case 80: // 아래쪽 화살표
							if (y < 4) {
								gotoxy(87, y);
								printf("  "); // 현재 위치의 화살표 지우기
								y += 2;
							}
							break;
						}
						gotoxy(87, y);
						printf("◀");
					}
					else {
						// 일반 키 입력 처리
						switch (cursor) {
						case 13: // 엔터
							if (y == 2) {
								system("cls");
								return;
							}
							else if (y == 8) {
								gotoxy(53, 20);
								//이전의 메세지 지우기 
								printf("                                         ");
							}
							break;
						}
					}
				}
			}
		}
	}
}