/*一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6 = 1 + 2 + 3。键盘输入一个正整数，判断该数是不是完数，
如果是输出：Yes, 否则输出： No。 如果输入的数小于等于0, 输出：Error*/
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