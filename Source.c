#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int Player = 0;
	int Com = 0;
	int round = 0;
	int result[3] = { 0, };
	// result [0] ���º�!, result [1] �÷��̾ �¸��Ͽ����ϴ�!, result �÷��̾ �й��Ͽ����ϴ�!
	srand(time(NULL)); // �������� �ʱ�ȭ

	printf("���� ���� �� ������ �����غ�����!\n");
	while (Player != -1)
	{
		Com = rand() % 3 + 1;
		printf("�� �� �ϳ��� �����ϼ���! ����(1), ����(2), ��(3) \n=>");
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
				printf("���º�!\n");
				result[0]++;
			}
			else if (((Player == 1 && Com == 3) ||
				(Player == 2 && Com == 1) ||
				(Player == 3 && Com == 2)))
			{
				printf("�÷��̾ �¸��Ͽ����ϴ�!\n\n");
				result[1]++;
			}
			else if (((Com == 1 && Player == 3) ||
				(Com == 2 && Player == 1) ||
				(Com == 3 && Player == 2)))
			{
				printf("�÷��̾ �й��Ͽ����ϴ�!\n\n");
				result[2]++;
			}
		}
		else
		{
			printf("�߸��� �Է��Դϴ�. 1, 2, 3 �� �ϳ��� �Է����ּ���!\n");
			Com = rand() % 3 + 1;
			printf("�� �� �ϳ��� �����ϼ���! ����(1), ����(2), ��(3) \n=>");
			scanf_s("%d", &Player);

			getchar();
			system("cls");
		}
	}

	printf("���� ����! ��� �� ");
	printf("���º� : %dȸ\n", result[0]);
	printf("                   �¸� : %dȸ\n", result[1]);
	printf("                   �й� : %dȸ\n", result[2]);

	return 0;
}