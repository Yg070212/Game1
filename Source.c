#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int Player = 0;
	int Com = 0;
	int round = 0;
	int result[3] = { 0, };
	// result [0] 무승부!, result [1] 플레이어가 이겼습니다!, result 플레이어가 패배하였습니다!
	srand(time(NULL)); // 랜덤값을 초기화

	printf("가위 바위 보 게임을 시작해보세요!\n");
	while (Player != -1)
	{
		Com = rand() %3 + 1;
		printf("이 중 하나를 선택하세요! 가위(1), 바위(2), 보(3) \n=>");
		scanf("%d, &Player");

		if (Player == -1)
		{
			printf("게임을 종료하시겠습니까?\n");
			if (Player == -2)
			{
				printf("다음에 또 즐겨주세요!");
			}
			else if (Player == -3)
			{
				printf("게임으로 돌아가기.");
			}
		
		}
	}


}