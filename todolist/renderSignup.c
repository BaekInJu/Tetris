#include <stdio.h>
#include <conio.h>
#include <windows.h>


void renderSignup() {
    int y = 6;  // Ŀ���� y���� ����
    int cursor;  // �Էµ� Ű���� ���� ����

    // �� ������ ���� ���ڹ迭
    char name[30] = { 0 };
    char email[30] = { 0 };
    char pw[30] = { 0 };
    char checkPw[30] = { 0 };
    //��й�ȣ *ǥ�ø� ���� �ϳ� �� ����
    char ptPw[30] = { 0 };
    char ptChPw[30] = { 0 };
    int i = 0;   //�ε����� 0���� ����

    //ȸ������ ��û�� ó�� ���¸� ���� �� ���� ����
    int status = 0;
    //1 : ����
    //2 : ������� �̸���
    //3 : ��й�ȣ�� ��ġ ���� ����
    //4 : �׿� ����

    // �� ó�� ȣ�� �Ǿ����� ������
    gotoxy(87, y);
    printf("��");
    gotoxy(59, 1);
    printf("ȸ������");
    gotoxy(33, 6);
    printf("�̸�");
    gotoxy(50, 6);
    printf("��");
    gotoxy(50, 5);
    printf("����������������������������������������������������������������������");
    gotoxy(50, 7);
    printf("����������������������������������������������������������������������");
    gotoxy(84, 6);
    printf("��");

    gotoxy(33, 9);
    printf("�̸���");
    gotoxy(50, 9);
    printf("��");
    gotoxy(50, 8);
    printf("����������������������������������������������������������������������");
    gotoxy(50, 10);
    printf("����������������������������������������������������������������������");
    gotoxy(84, 9);
    printf("��");

    gotoxy(33, 12);
    printf("��й�ȣ");
    gotoxy(50, 12);
    printf("��");
    gotoxy(50, 11);
    printf("����������������������������������������������������������������������");
    gotoxy(50, 13);
    printf("����������������������������������������������������������������������");
    gotoxy(84, 12);
    printf("��");

    gotoxy(33, 15);
    printf("��й�ȣ Ȯ��");
    gotoxy(50, 15);
    printf("��");
    gotoxy(50, 14);
    printf("����������������������������������������������������������������������");
    gotoxy(50, 16);
    printf("����������������������������������������������������������������������");
    gotoxy(84, 15);
    printf("��");

    gotoxy(60, 18);
    printf("����");

    gotoxy(60, 21);
    printf("�ڷ�");

    while (1) {
        if (_kbhit()) {  // Ű���� �Է��� �ִ��� Ȯ��
            cursor = _getch();  // �Էµ� Ű�� ����
            if (cursor == 0 || cursor == 224) {
                // Ȯ�� Ű �Է� ó�� (ȭ��ǥ Ű ��)
                cursor = _getch(); // Ȯ�� Ű�� ���� ���� ����
                switch (cursor) {
                case 72: // ���� ȭ��ǥ
                    if (y > 6) {
                        gotoxy(87, y);
                        printf("  "); // ���� ��ġ�� ȭ��ǥ �����
                        y -= 3;
                        i = 0;   //�ε��� �ʱ�ȭ
                    }
                    break;
                case 80: // �Ʒ��� ȭ��ǥ
                    if (y < 21) {
                        gotoxy(87, y);
                        printf("  "); // ���� ��ġ�� ȭ��ǥ �����
                        y += 3;
                        i = 0;   //�ε��� �ʱ�ȭ
                    }
                    break;
                }
                gotoxy(87, y);
                printf("��");
            }
            else {
                // �Ϲ� Ű �Է� ó��
                switch (cursor) {
                case 13: // ����
                    if (y == 21) {
                        system("cls");

                        return;
                    }
                    else if (y == 18) {
                        status = signup();
                    }
                    break;
                case 8:   //BackSpace�� �������� ��� �׸� �ʱ�ȭ
                    printf("%c", cursor);
                    for (int j = 0; j < sizeof(name); j++) {
                        name[j] = 0;
                        email[j] = 0;
                        pw[j] = 0;
                        checkPw[j] = 0;
                        ptPw[j] = 0;
                        ptChPw[j] = 0;
                    }
                    y = 6;
                    system("cls");
                    //�緻����
                    gotoxy(87, y);
                    printf("��");
                    gotoxy(59, 1);
                    printf("ȸ������");
                    gotoxy(33, 6);
                    printf("�̸�");
                    gotoxy(50, 6);
                    printf("��");
                    gotoxy(50, 5);
                    printf("����������������������������������������������������������������������");
                    gotoxy(50, 7);
                    printf("����������������������������������������������������������������������");
                    gotoxy(84, 6);
                    printf("��");

                    gotoxy(33, 9);
                    printf("�̸���");
                    gotoxy(50, 9);
                    printf("��");
                    gotoxy(50, 8);
                    printf("����������������������������������������������������������������������");
                    gotoxy(50, 10);
                    printf("����������������������������������������������������������������������");
                    gotoxy(84, 9);
                    printf("��");

                    gotoxy(33, 12);
                    printf("��й�ȣ");
                    gotoxy(50, 12);
                    printf("��");
                    gotoxy(50, 11);
                    printf("����������������������������������������������������������������������");
                    gotoxy(50, 13);
                    printf("����������������������������������������������������������������������");
                    gotoxy(84, 12);
                    printf("��");

                    gotoxy(33, 15);
                    printf("��й�ȣ Ȯ��");
                    gotoxy(50, 15);
                    printf("��");
                    gotoxy(50, 14);
                    printf("����������������������������������������������������������������������");
                    gotoxy(50, 16);
                    printf("����������������������������������������������������������������������");
                    gotoxy(84, 15);
                    printf("��");

                    gotoxy(60, 18);
                    printf("����");

                    gotoxy(60, 21);
                    printf("�ڷ�");
                    break;
                default: // �ٸ� �Է��� �̸��� �߰�
                    if (y == 6 && strlen(name) < 29) {
                        name[i] = cursor;
                        name[i + 1] = '\0';    
                        gotoxy(52, 6);
                        printf("%-29s", name);  // �ִ� 19���ڱ��� ǥ��
                    }
                    else if (y == 9 && strlen(email) < 29) {
                        email[i] = cursor;
                        email[i + 1] = '\0';
                        gotoxy(52, 9);
                        printf("%-29s", email);
                    }
                    else if (y == 12 && strlen(pw) < 29) {
                        pw[i] = cursor;
                        pw[i + 1] = '\0';
                        ptPw[i] = '*';
                        ptPw[i + 1] = '\0';
                        gotoxy(52, 12);
                        printf("%-29s", ptPw);
                    }
                    else if (y == 15 && strlen(checkPw) < 19) {
                        checkPw[i] = cursor;
                        checkPw[i + 1] = '\0';
                        ptChPw[i] = '*';
                        ptChPw[i + 1] = '\0';
                        gotoxy(52, 15);
                        printf("%-29s", ptChPw);
                    }
                    i++;
                    break;
                }
            }
        }
    }
}
