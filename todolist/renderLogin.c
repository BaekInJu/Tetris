void renderLogin() {
	int y = 6;  //Ŀ���� y���� ����
	int cursor;   //�Էµ� Ű���� ���� ����

	//�� ó�� ȣ�� �Ǿ����� ������
	gotoxy(77, y);
	printf("��");
	gotoxy(59, 1);
	printf("�α���");
	gotoxy(33, 6);
	printf("�̸���");
	gotoxy(50, 6);
	printf("��");
	gotoxy(50, 5);
	printf("��������������������������������������������������");
	gotoxy(50, 7);
	printf("��������������������������������������������������");
	gotoxy(74, 6);
	printf("��");

	gotoxy(33, 9);
	printf("��й�ȣ");
	gotoxy(50, 9);
	printf("��");
	gotoxy(50, 8);
	printf("��������������������������������������������������");
	gotoxy(50, 10);
	printf("��������������������������������������������������");
	gotoxy(74, 9);
	printf("��");

	gotoxy(59, 12);
	printf("�α���");
	gotoxy(60, 15);
	printf("�ڷ�");


	while (1) {
		//Ű���� �Է��� ���������� Ŀ���� �����̸� �� ������
		if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
			cursor = _getch();  // �Էµ� Ű�� ����
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
			printf("��");
			gotoxy(59, 1);
			printf("�α���");
			gotoxy(33, 6);
			printf("�̸���");
			gotoxy(50, 6);
			printf("��");
			gotoxy(50, 5);
			printf("��������������������������������������������������");
			gotoxy(50, 7);
			printf("��������������������������������������������������");
			gotoxy(74, 6);
			printf("��");

			gotoxy(33, 9);
			printf("��й�ȣ");
			gotoxy(50, 9);
			printf("��");
			gotoxy(50, 8);
			printf("��������������������������������������������������");
			gotoxy(50, 10);
			printf("��������������������������������������������������");
			gotoxy(74, 9);
			printf("��");

			gotoxy(59, 12);
			printf("�α���");
			gotoxy(60, 15);
			printf("�ڷ�");
		}
	}
}