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
	// result [0] ���º�!, result [1] �÷��̾ �¸��Ͽ����ϴ�!, result �÷��̾ �й��Ͽ����ϴ�!
	srand(time(NULL)); // �������� �ʱ�ȭ

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
		printf("                                                                             ���� ���� �� ������ �����غ�����!\n\n");

		Com = rand() % 3 + 1;
		textcolor(14);
		printf("                                                                      �� �� �ϳ��� �����ϼ���! ����(1), ����(2), ��(3) \n");
		printf("                                                                      =>");
		scanf_s("%d", &Player);

		getchar();
		system("cls");

		if (Player == -1)
		{
			break; // ���� ���� (while ���� Ż��.)
		}
		else if (Player > 0 && Player < 4)
		{
			round++;

			if (Com == Player)
			{
				textcolor(13);
				Position(0, 36);
				printf("                                                                                          ���º�!");
				result[0]++;

			}
			else if (((Player == 1 && Com == 3) ||
				(Player == 2 && Com == 1) ||	
				(Player == 3 && Com == 2)))
			{
				textcolor(11);
				Position(0, 36);
				printf("                                                                                 �÷��̾ �¸� �Ͽ����ϴ�!");
				result[1]++;

			}
			else if (((Com == 1 && Player == 3) ||
				(Com == 2 && Player == 1) ||
				(Com == 3 && Player == 2)))
			{
				textcolor(12);
				Position(0, 36);
				printf("                                                                                 �÷��̾ �й� �Ͽ����ϴ�!");
				result[2]++;

			}
		}
		else
		{
			textcolor(4);
			Position(0, 36);
			printf("                                                                      �߸��� �Է��Դϴ�. 1, 2, 3 �� �ϳ��� �Է����ּ���!\n");
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
			printf("                                                                             ���� ���� �� ������ �����غ�����!\n\n");

			Com = rand() % 3 + 1;
			textcolor(14);
			printf("                                                                      �� �� �ϳ��� �����ϼ���! ����(1), ����(2), ��(3) \n");
			printf("                                                                      =>");
			scanf_s("%d", &Player);

			getchar();
			system("cls");
		}
	}

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