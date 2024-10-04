#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void Position(int x, int y) {
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void displayGameScreen() {
    textcolor(14);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                               ________________________________________________________________________________________________________________________________________ \n");
    printf("                              |                                                                                                                                        |\n");
    printf("                              |     # # # # #   #            #  #        #            #         #   #             #  #       #              #             #       #    |\n");
    printf("                              |            #   #           #     #      #            #         #   #            #     #     #              # # # # # # # #       #     |\n");
    printf("                              |           #   # # #         #  #       #            #         #   # # # #        #  #      #              #             #       #      |\n");
    printf("                              |         #    #          # # # # # #   #            # # # # # #   #           # # # # # #  #              # # # # # # # #       #       |\n");
    printf("                              |       #     #              #         #            #         #   #                 #      #                     #                       |\n");
    printf("                              |     #      #              #         #            # # # # # #   #                 #      #              # # # # # # # #       #         |\n");
    printf("                              |                                                                                                                                        |\n");
    printf("                              |________________________________________________________________________________________________________________________________________|\n");
}

int main(void) {
    int Player = 0, Com = 0, round = 0;
    int result[3] = { 0 };

    srand(time(NULL)); // ������ �ʱ�ȭ
    displayGameScreen();
    textcolor(10);
    printf("\n\n\n\n\n\n\n");
    printf("                                                                             ���� ���� �� ������ �����غ�����!\n\n");

    while (1) {
        Com = rand() % 3 + 1;
        textcolor(14);
        printf("                                                                      �� �� �ϳ��� �����ϼ���! ����(1), ����(2), ��(3) \n");
        printf("                                                                      => ");
        scanf_s("%d", &Player);

        if (Player == -1) break;

        if (Player < 1 || Player > 3) {
            textcolor(4);
            printf("�߸��� �Է��Դϴ�. 1, 2, 3 �� �ϳ��� �Է����ּ���!\n");
            continue; // �߸��� �Է� �� �ٽ� ����
        }

        round++;

        // ��� ��
        if (Com == Player) {
            textcolor(13);
            printf("                                                                                          ���º�!");
            result[0]++;
        }
        else if ((Player == 1 && Com == 3) || (Player == 2 && Com == 1) || (Player == 3 && Com == 2)) {
            textcolor(11);
            printf("                                                                                 �÷��̾ �¸� �Ͽ����ϴ�!");
            result[1]++;
        }
        else {
            textcolor(12);
            printf("                                                                                 �÷��̾ �й� �Ͽ����ϴ�!");
            result[2]++;
        }

        // ���� ȭ���� �ٽ� �׸���
        displayGameScreen();
        textcolor(10);
        printf("\n\n\n\n\n\n\n");
        printf("                                                                             ���� ���� �� ������ �����غ�����!\n\n");
    }

    // ��� ���
    printf("���� ����! ��� �� ");
    textcolor(13);
    printf("���º� : %dȸ\n", result[0]);
    textcolor(11);
    printf("                   �¸� : %dȸ\n", result[1]);
    textcolor(12);
    printf("                   �й� : %dȸ\n", result[2]);

    system("pause");
    return 0;
}
