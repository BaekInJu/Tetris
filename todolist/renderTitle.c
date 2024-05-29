#include <stdio.h>

int renderTitle(char ch) {
	static int point = -1;  //함수가 종료돼도 유지하도록 static 선언

	if (point == -1) {
		point = 1;  //맨 처음에만 커서를 1로 설정한다.
	}

	switch (ch) {
		//위쪽 방향키
	case 72:
		//이미 커서가 맨 위일때는 커서 안움직임
		if (point <= 1) {
			return point;
			break;
		}
		//재 렌더링
		system("cls");
		//point값 감소
		point--;
		gotoxy(0, 1);
		printf("1. 로그인\n");
		printf("2. 회원가입\n");
		printf("3. 게임시작\n");
		printf("4. 게임설명\n");
		printf("5. 게임종료\n");
		gotoxy(14, point);
		printf("◀");
		return point;
		break;

		//아래쪽 방향키
	case 80:
		//이미 커서가 맨 아래일때는 커서 안움직임
		if (point >= 5) {
			return point;
			break;
		}
		//재 렌더링
		system("cls");
		//point값 증가
		point++;
		gotoxy(0, 1);
		printf("1. 로그인\n");
		printf("2. 회원가입\n");
		printf("3. 게임시작\n");
		printf("4. 게임설명\n");
		printf("5. 게임종료\n");
		gotoxy(14, point);
		printf("◀");
		return point;
		break;

		//엔터키
	case 13:
		printf("%d", point);
	}
}