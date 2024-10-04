#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void Position(int x, int y)
{
	COORD position = {x, y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void textcolor(int colorNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorNum);
}

enum ColorType
{
	BLACK,  	//0
	darkBLUE,	//1
	DarkGreen,	//2
	darkSkyBlue,//3
	DarkRed,  	//4
	DarkPurple,	//5
	DarkYellow,	//6
	GRAY,		//7
	DarkGray,	//8
	BLUE,		//9
	GREEN,		//10
	SkyBlue,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE		//15
}COLOR;

int main(void)
{
	int Player = 0;
	int Com = 0;
	int round = 0;
	int result[3] = { 0, };
	// result [0] 무승부!, result [1] 플레이어가 승리하였습니다!, result 플레이어가 패배하였습니다!
	srand(time(NULL)); // 랜덤값을 초기화

	while (Player != -1)
	{
		textcolor(14);
		Position(0, 0);
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

		textcolor(10);
		printf("\n\n\n\n\n\n\n");
		printf("                                                                             가위 바위 보 게임을 시작해보세요!\n\n");

		Com = rand() % 3 + 1;
		textcolor(14);
		printf("                                                                      이 중 하나를 선택하세요! 가위(1), 바위(2), 보(3) \n");
		printf("                                                                      =>");
		scanf_s("%d", &Player);

		getchar();
		system("cls");

		if (Player == -1)
		{
			break; // 게임 종료 (while 루프 탈출.)
		}
		else if (Player > 0 && Player < 4)
		{
			round++;

			if (Com == Player)
			{
				textcolor(13);
				Position(0, 36);
				printf("                                                                                          무승부!");
				result[0]++;

			}
			else if (((Player == 1 && Com == 3) ||
				(Player == 2 && Com == 1) ||	
				(Player == 3 && Com == 2)))
			{
				textcolor(11);
				Position(0, 36);
				printf("                                                                                 플레이어가 승리 하였습니다!");
				result[1]++;

			}
			else if (((Com == 1 && Player == 3) ||
				(Com == 2 && Player == 1) ||
				(Com == 3 && Player == 2)))
			{
				textcolor(12);
				Position(0, 36);
				printf("                                                                                 플레이어가 패배 하였습니다!");
				result[2]++;

			}
		}
		else
		{
			textcolor(4);
			Position(0, 36);
			printf("                                                                      잘못된 입력입니다. 1, 2, 3 중 하나를 입력해주세요!\n");
			Com = rand() % 3 + 1;
			textcolor(14);
			Position(0, 0);
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

			textcolor(10);
			printf("\n\n\n\n\n\n\n");
			printf("                                                                             가위 바위 보 게임을 시작해보세요!\n\n");

			Com = rand() % 3 + 1;
			textcolor(14);
			printf("                                                                      이 중 하나를 선택하세요! 가위(1), 바위(2), 보(3) \n");
			printf("                                                                      =>");
			scanf_s("%d", &Player);

			getchar();
			system("cls");
		}
	}

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