#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void renderLogin() {
	int y = 6;  //커서의 y값을 저장
	int cursor;   //입력된 키보드 값을 저장

	char email[30];
	char pw[30];
	char buffer[70];
	int i = 0;   //인덱스를 저장하기 위한 변수
	char ptPw[30];

	//로그인 요청후 상태 저장을 위한 변수
	int status = 0;
	//1: 성공
	//2: 없는 이메일
	//3: 비밀번호 불일치

	//맨 처음 호출 되었을때 렌더링
	gotoxy(87, y);
	printf("◀");
	gotoxy(59, 1);
	printf("로그인");
	gotoxy(33, 6);
	printf("이메일");
	gotoxy(50, 6);
	printf("│");
	gotoxy(50, 5);
	printf("┌─────────────────────────────────┐");
	gotoxy(50, 7);
	printf("└─────────────────────────────────┘");
	gotoxy(84, 6);
	printf("│");

	gotoxy(33, 9);
	printf("비밀번호");
	gotoxy(50, 9);
	printf("│");
	gotoxy(50, 8);
	printf("┌─────────────────────────────────┐");
	gotoxy(50, 10); 
	printf("└─────────────────────────────────┘");
	gotoxy(84, 9);
	printf("│");

	gotoxy(59, 12);
	printf("로그인");
	gotoxy(60, 15);
	printf("뒤로");

	gotoxy(52, 6);
	while (1) {
		//키보드 입력이 있을때마다 커서가 움직이며 재 렌더링
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			cursor = _getch();  // 입력된 키를 읽음
			if (cursor == 0 || cursor == 224) {
				cursor = _getch();
				switch (cursor) {
				case 72: // 위쪽 화살표
					if (y > 6) {
						gotoxy(87, y);
						printf("  "); // 현재 위치의 화살표 지우기
						y -= 3;
						i = 0;   //인덱스 초기화
					}
					break;
				case 80: // 아래쪽 화살표
					if (y < 15) {
						gotoxy(87, y);
						printf("  "); // 현재 위치의 화살표 지우기
						y += 3;
						i = 0;   //인덱스 초기화
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
					if (y == 15) {
						system("cls");

						return;
					}
					else if (y == 12) {
						status = signup();
					}
					break;
				case 8:   //BackSpace가 들어왔을때 모든 항목 초기화
					printf("%c", cursor);
					for (int j = 0; j < sizeof(email); j++) {
						email[j] = 0;
						pw[j] = 0;
					}
					y = 6;
					system("cls");
					gotoxy(87, y);
					printf("◀");
					gotoxy(59, 1);
					printf("로그인");
					gotoxy(33, 6);
					printf("이메일");
					gotoxy(50, 6);
					printf("│");
					gotoxy(50, 5);
					printf("┌─────────────────────────────────┐");
					gotoxy(50, 7);
					printf("└─────────────────────────────────┘");
					gotoxy(84, 6);
					printf("│");

					gotoxy(33, 9);
					printf("비밀번호");
					gotoxy(50, 9);
					printf("│");
					gotoxy(50, 8);
					printf("┌─────────────────────────────────┐");
					gotoxy(50, 10);
					printf("└─────────────────────────────────┘");
					gotoxy(84, 9);
					printf("│");

					gotoxy(59, 12);
					printf("로그인");
					gotoxy(60, 15);
					printf("뒤로");
					break;
				default: // 다른 입력은 이름에 추가
					if (y == 6 && strlen(email) < 29) {
						email[i] = cursor;
						email[i + 1] = '\0';
						gotoxy(52, 6);
						printf("%-29s", email);
					}
					else if (y == 9 && strlen(pw) < 29) {
						pw[i] = cursor;
						pw[i + 1] = '\0';
						ptPw[i] = '*';
						ptPw[i + 1] = '\0';
						gotoxy(52, 9);
						printf("%-29s", ptPw);
					}
					i++;
					break;
				}
			}
		}

	}
}
