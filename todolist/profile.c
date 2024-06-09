#include "head.h"

void profile(struct member* mpp, int* cp) {
	int y = 9;  //커서의 y값을 저장
	int cursor;   //입력된 키보드 값을 저장

	MEMBER m1 = *mpp;  //넘어온 정보를 출력해줄 구조체
	MEMBER* mp = &m1;

	MEMBER m2 = { 0 };   //새로운 정보를 저장할 구조체
	MEMBER* mp2 = &m2;

	strcpy(m2.email, m1.email);
	strcpy(m2.name, m1.name);
	strcpy(m2.pw, m1.pw);

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
	gotoxy(58, 1);
	printf("개인정보");
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
	gotoxy(52, 6);
	printf("%s", mpp->email);

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
	gotoxy(52, 9);
	printf("%s", mpp->name);

	gotoxy(33, 12);
	printf("비밀번호");
	gotoxy(50, 12);
	printf("│");
	gotoxy(50, 11);
	printf("┌─────────────────────────────────┐");
	gotoxy(50, 13);
	printf("└─────────────────────────────────┘");
	gotoxy(84, 12);
	printf("│");
	gotoxy(52, 12);
	printf("%s", mpp->pw);

	gotoxy(60, 15);
	printf("수정");

	gotoxy(60, 18);
	printf("삭제");

	gotoxy(60, 21);
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
					if (y > 9) {
						gotoxy(87, y);
						printf("  "); // 현재 위치의 화살표 지우기
						y -= 3;
						i = 0;   //인덱스 초기화
					}
					break;
				case 80: // 아래쪽 화살표
					if (y < 21) {
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
					if (y == 21) {
						system("cls");
						return;
					}
					else if (y == 18) {
						gotoxy(53, 20);
						//이전의 메세지 지우기 
						printf("                                         ");
						delete(&m1);  //계정 삭제 함수 호출
						gotoxy(58, 26);
						printf("삭제 완료");
						Sleep(2000);
						*cp = 0;
						system("cls");
						return;
					}
					else if (y == 15) {
						gotoxy(53, 20);
						//이전의 메세지 지우기 
						printf("                                         ");
						status = update(mp2);
						if ((!strcmp(m1.name, m2.name))&&(!strcmp(m1.pw, m2.pw))) {
							status = 2;
						}
						switch (status) {
						case 1:
							gotoxy(50, 26);
							printf("변경 완료 (다시 로그인 해주세요)");
							Sleep(2000);
							system("cls");
							*cp = 0;
							return mp;
							break;
						case 2:
							gotoxy(56, 26);
							printf("바뀐 정보가 없음");
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
					y = 9;
					system("cls");
					gotoxy(87, y);
					printf("◀");
					gotoxy(58, 1);
					printf("개인정보");
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
					gotoxy(52, 6);
					printf("%s", mpp->email);

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
					gotoxy(52, 9);
					printf("%s", mpp->name);

					gotoxy(33, 12);
					printf("비밀번호");
					gotoxy(50, 12);
					printf("│");
					gotoxy(50, 11);
					printf("┌─────────────────────────────────┐");
					gotoxy(50, 13);
					printf("└─────────────────────────────────┘");
					gotoxy(84, 12);
					printf("│");
					gotoxy(52, 12);
					printf("%s", mpp->pw);

					gotoxy(60, 15);
					printf("수정");

					gotoxy(60, 18);
					printf("삭제");

					gotoxy(60, 21);
					printf("뒤로");
					break;
				default: // 다른 입력은 이름에 추가
					if (y == 6 && strlen(m2.email) < 29) {
						m2.email[i] = cursor;
						m2.email[i + 1] = '\0';
						gotoxy(52, 6);
						printf("%-29s", m2.email);
					}
					else if (y == 9 && strlen(m2.name) < 29) {
						m2.name[i] = cursor;
						m2.name[i + 1] = '\0';
						gotoxy(52, 9);
						printf("%-29s", m2.name);
					}
					else {
						m2.pw[i] = cursor;
						m2.pw[i + 1] = '\0';
						gotoxy(52, 12);
						printf("%-29s", m2.pw);
					}
					i++;
					break;
				}
			}
		}

	}
}
