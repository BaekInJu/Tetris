void renderLogin() {
	int y = 6;  //커서의 y값을 저장
	int cursor;   //입력된 키보드 값을 저장

	//맨 처음 호출 되었을때 렌더링
	gotoxy(77, y);
	printf("◀");
	gotoxy(59, 1);
	printf("로그인");
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
	printf("비밀번호");
	gotoxy(50, 9);
	printf("│");
	gotoxy(50, 8);
	printf("┌───────────────────────┐");
	gotoxy(50, 10);
	printf("└───────────────────────┘");
	gotoxy(74, 9);
	printf("│");

	gotoxy(59, 12);
	printf("로그인");
	gotoxy(60, 15);
	printf("뒤로");


	while (1) {
		//키보드 입력이 있을때마다 커서가 움직이며 재 렌더링
		if (_kbhit()) {  // 키보드 입력이 있는지 확인
			cursor = _getch();  // 입력된 키를 읽음
			switch (cursor) {
			case 72:
				if (y == 6) {
					continue;
				}
				else {
					y -= 3;
				}
				break;
			case 80:
				if (y == 15) {
					continue;
				}
				else {
					y += 3;
				}
				break;
			case 13:
				if (y == 15) {
					system("cls");
					return;
				}
				break;
			}
			system("cls");
			gotoxy(77, y);
			printf("◀");
			gotoxy(59, 1);
			printf("로그인");
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
			printf("비밀번호");
			gotoxy(50, 9);
			printf("│");
			gotoxy(50, 8);
			printf("┌───────────────────────┐");
			gotoxy(50, 10);
			printf("└───────────────────────┘");
			gotoxy(74, 9);
			printf("│");

			gotoxy(59, 12);
			printf("로그인");
			gotoxy(60, 15);
			printf("뒤로");
		}
	}
}