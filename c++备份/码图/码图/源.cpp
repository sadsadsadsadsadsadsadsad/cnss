/*һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6 = 1 + 2 + 3����������һ�����������жϸ����ǲ���������
����������Yes, ��������� No�� ����������С�ڵ���0, �����Error*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int s=0;
	int a;
	scanf_s("%d", &a);
	if (a <= 0)
		printf("Error");
	else
	{
		for (int i = 1; i < a; i++)
			if (a%i == 0)
				s += i;
		if (s == a)
			printf("Yes");
		else
			printf("No");
	}
}