#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int Player = 0;
	int Com = 0;
	int round = 0;
	int result[3] = { 0, };
	// result [0] 무승부!, result [1] 플레이어가 승리하였습니다!, result 플레이어가 패배하였습니다!
	srand(time(NULL)); // 랜덤값을 초기화

	printf("가위 바위 보 게임을 시작해보세요!\n");
	while (Player != -1)
	{
		Com = rand() % 3 + 1;
		printf("이 중 하나를 선택하세요! 가위(1), 바위(2), 보(3) \n=>");
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
				printf("무승부!\n");
				result[0]++;
			}
			else if (((Player == 1 && Com == 3) ||
				(Player == 2 && Com == 1) ||
				(Player == 3 && Com == 2)))
			{
				printf("플레이어가 승리하였습니다!\n\n");
				result[1]++;
			}
			else if (((Com == 1 && Player == 3) ||
				(Com == 2 && Player == 1) ||
				(Com == 3 && Player == 2)))
			{
				printf("플레이어가 패배하였습니다!\n\n");
				result[2]++;
			}
		}
		else
		{
			printf("잘못된 입력입니다. 1, 2, 3 중 하나를 입력해주세요!\n");
			Com = rand() % 3 + 1;
			printf("이 중 하나를 선택하세요! 가위(1), 바위(2), 보(3) \n=>");
			scanf_s("%d", &Player);

			getchar();
			system("cls");
		}
	}

	printf("게임 종료! 결과 → ");
	printf("무승부 : %d회\n", result[0]);
	printf("                   승리 : %d회\n", result[1]);
	printf("                   패배 : %d회\n", result[2]);

	return 0;
}