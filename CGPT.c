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

    srand(time(NULL)); // 랜덤값 초기화
    displayGameScreen();
    textcolor(10);
    printf("\n\n\n\n\n\n\n");
    printf("                                                                             가위 바위 보 게임을 시작해보세요!\n\n");

    while (1) {
        Com = rand() % 3 + 1;
        textcolor(14);
        printf("                                                                      이 중 하나를 선택하세요! 가위(1), 바위(2), 보(3) \n");
        printf("                                                                      => ");
        scanf_s("%d", &Player);

        if (Player == -1) break;

        if (Player < 1 || Player > 3) {
            textcolor(4);
            printf("잘못된 입력입니다. 1, 2, 3 중 하나를 입력해주세요!\n");
            continue; // 잘못된 입력 시 다시 선택
        }

        round++;

        // 결과 비교
        if (Com == Player) {
            textcolor(13);
            printf("                                                                                          무승부!");
            result[0]++;
        }
        else if ((Player == 1 && Com == 3) || (Player == 2 && Com == 1) || (Player == 3 && Com == 2)) {
            textcolor(11);
            printf("                                                                                 플레이어가 승리 하였습니다!");
            result[1]++;
        }
        else {
            textcolor(12);
            printf("                                                                                 플레이어가 패배 하였습니다!");
            result[2]++;
        }

        // 게임 화면을 다시 그리기
        displayGameScreen();
        textcolor(10);
        printf("\n\n\n\n\n\n\n");
        printf("                                                                             가위 바위 보 게임을 시작해보세요!\n\n");
    }

    // 결과 출력
    printf("게임 종료! 결과 → ");
    textcolor(13);
    printf("무승부 : %d회\n", result[0]);
    textcolor(11);
    printf("                   승리 : %d회\n", result[1]);
    textcolor(12);
    printf("                   패배 : %d회\n", result[2]);

    system("pause");
    return 0;
}
