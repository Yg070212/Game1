#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int Player = 0;
	int Com = 0;
	int round = 0;
	int result[3] = { 0, };
	// result [0] ���º�!, result [1] �÷��̾ �̰���ϴ�!, result �÷��̾ �й��Ͽ����ϴ�!
	srand(time(NULL)); // �������� �ʱ�ȭ

	printf("���� ���� �� ������ �����غ�����!\n");
	while (Player != -1)
	{
		Com = rand() %3 + 1;
		printf("�� �� �ϳ��� �����ϼ���! ����(1), ����(2), ��(3) \n=>");
		scanf("%d, &Player");

		if (Player == -1)
		{
			printf("������ �����Ͻðڽ��ϱ�?\n");
			if (Player == -2)
			{
				printf("������ �� ����ּ���!");
			}
			else if (Player == -3)
			{
				printf("�������� ���ư���.");
			}
		
		}
	}


}