#include <stdio.h>

int renderTitle(char ch) {
	static int point = -1;  //함수가 종료돼도 유지하도록 static 선언
	static int menuNum = -1;

	if (point == -1) {
		point = 10;  //맨 처음에만 커서를 1로 설정한다.
	}
	if (menuNum == -1) {
		menuNum = 1;
	}

	switch (ch) {
		//위쪽 방향키
	case 72:
		//이미 커서가 맨 위일때는 커서 안움직임
		if (point == 10) {
			return menuNum;
			break;
		}
		//재 렌더링
		system("cls");
		//point값 감소
		point-= 2;
		menuNum--;
		gotoxy(54, 4);
		printf("To Do List");
		gotoxy(56, 10);
		printf("로그인\n");
		gotoxy(55, 12);
		printf("회원가입\n");
		gotoxy(55, 14);
		printf("계정찾기\n");
		gotoxy(55, 16);
		printf("종    료\n");
		gotoxy(66, point);
		printf("◀");
		return menuNum;
		break;

		//아래쪽 방향키
	case 80:
		//이미 커서가 맨 아래일때는 커서 안움직임
		if (point == 16) {
			return menuNum;
			break;
		}
		//재 렌더링
		system("cls");
		//point값 증가
		point+= 2;
		menuNum++;
		gotoxy(54, 4);
		printf("To Do List");
		gotoxy(56, 10);
		printf("로그인\n");
		gotoxy(55, 12);
		printf("회원가입\n");
		gotoxy(55, 14);
		printf("계정찾기\n");
		gotoxy(55, 16);
		printf("종    료\n");
		gotoxy(66, point);
		printf("◀");
		return menuNum;
		break;
	}
}