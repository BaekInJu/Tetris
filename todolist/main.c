#include "head.h"

int main(void) {
	int menuNum = 0;  //초기화면 커서의 위치 값 저장 변수
	char cursor;  //사용자의 키보드 입력을 저장할 변수
	int login = 0;  // 로그인 된 상태인지 확인하는 변수
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
				printf("프로그램을 종료 합니다.");
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
				printf("프로그램을 종료 합니다.");
				exit(0);
				break;
			}
		}
	}
	return 0;
}