#include "head.h"

int main(void) {
	int menuNum;  //초기화면 커서의 위치 값 저장 변수
	char cursor;  //사용자의 키보드 입력을 저장할 변수

	//맨 처음 렌더링
	gotoxy(0, 1);
	printf("1. 로그인\n");
	printf("2. 회원가입\n");
	printf("3. 게임시작\n");
	printf("4. 게임설명\n");
	printf("5. 게임종료\n");
	gotoxy(14, 1);
	printf("◀");
	while (1) {
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			cursor = _getch();  // 입력된 키를 읽음
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
					printf("게임을 종료 합니다.");
					exit(0);
					break;

				}
			}
			menuNum = renderTitle(cursor);   // int renderTitle(사용자 키보드 입력 값);
		}
	}
	return 0;
}