#include "head.h"

int main(void) {

	int menuNum = 0;  //초기화면 커서의 위치 값 저장 변수
	char cursor;  //사용자의 키보드 입력을 저장할 변수
	boolean login = 0;  // 로그인 된 상태인지 확인하는 변수
	struct member mp;

	//맨 처음 렌더링
	gotoxy(52, 4);
	printf("Member Manager");
	gotoxy(56, 10);
	printf("로그인\n");
	gotoxy(55, 12);
	printf("회원가입\n");
	gotoxy(55, 14);
	printf("계정찾기\n");
	gotoxy(55, 16);
	printf("종    료\n");
	gotoxy(66, 10);
	printf("◀");
	while (1) {
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			cursor = _getch();  // 입력된 키를 읽음
			if (cursor == 13) { //엔터 입력이 있을 시 해당 페이지로 이동
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
					printf("프로그램을 종료 합니다.");
					exit(0);
					break;
				}
			}
			menuNum = renderTitle(cursor);   // int renderTitle(사용자 키보드 입력 값);
		}
		if (login) {
			system("cls");
			profile(&mp, &login);
			gotoxy(52, 4);
			printf("Member Manager");
			gotoxy(56, 10);
			printf("로그인\n");
			gotoxy(55, 12);
			printf("회원가입\n");
			gotoxy(55, 14);
			printf("계정찾기\n");
			gotoxy(55, 16);
			printf("종    료\n");
			gotoxy(66, 10);
			printf("◀");
		}
	}
	return 0;
}