#include "head.h"

void renderFindPw() {
	int y = 6;  //커서의 y값을 저장
	int cursor;   //입력된 키보드 값을 저장
	int i = 0;
	MEMBER m1 = { 0, "", "", "", "" };
	MEMBER* mp = &m1;

	int status;
	// 1. 정상 비밀번호 반환
	// 2. email이 없음
	// 3. email과 이름이 다름

	//맨 처음 호출 되었을때 렌더링
	gotoxy(77, y);
	printf("◀");
	gotoxy(55, 1);
	printf("비밀번호 찾기");
	gotoxy(33, 6);
	printf("이메일");
	gotoxy(50, 6);
	printf("│");
	gotoxy(50, 5);
	printf("┌───────────────────────┐");
	gotoxy(50, 7);
	printf("└───────────────────────┘");
	gotoxy(74, 6);
	printf("│");

	gotoxy(33, 9);
	printf("이름");
	gotoxy(50, 9);
	printf("│");
	gotoxy(50, 8);
	printf("┌───────────────────────┐");
	gotoxy(50, 10);
	printf("└───────────────────────┘");
	gotoxy(74, 9);
	printf("│");

	gotoxy(60, 12);
	printf("찾기");

	gotoxy(60, 15);
	printf("뒤로");


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
						gotoxy(53, 20);
						//이전의 메세지 지우기 
						printf("                                         ");
						status = findPw(mp);   //상태와 비밀번호를 리턴받는다.

						switch (status) {
						case 1:
							gotoxy(60, 20);
							printf("%s", m1.pw);
							Sleep(2000);
							system("cls");
							return;
							break;
						case 2:
							gotoxy(56, 20);
							printf("없는 이메일");
							break;
						case 3:
							gotoxy(56, 20);
							printf("이름 불일치");
							break;
						}
					}
					break;
				case 8:   //BackSpace가 들어왔을때 모든 항목 초기화
					printf("%c", cursor);
					for (int j = 0; j < sizeof(m1.email); j++) {
						m1.email[j] = 0;
						m1.pw[j] = 0;
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
					printf("이름");
					gotoxy(50, 9);
					printf("│");
					gotoxy(50, 8);
					printf("┌─────────────────────────────────┐");
					gotoxy(50, 10);
					printf("└─────────────────────────────────┘");
					gotoxy(84, 9);
					printf("│");

					gotoxy(60, 12);
					printf("찾기");

					gotoxy(60, 15);
					printf("뒤로");
					break;
				default: // 다른 입력은 이름에 추가
					if (y == 6 && strlen(m1.email) < 29) {
						m1.email[i] = cursor;
						m1.email[i + 1] = '\0';
						gotoxy(52, 6);
						printf("%-29s", m1.email);
					}
					else if (y == 9 && strlen(m1.name) < 29) {
						m1.name[i] = cursor;
						m1.name[i + 1] = '\0';
						gotoxy(52, 9);
						printf("%-29s", m1.name);
					}
					i++;
					break;
				}
			}
		}
	}
}
