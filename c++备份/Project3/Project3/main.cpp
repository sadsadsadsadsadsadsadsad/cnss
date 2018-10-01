#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 89; i++)
	{
		a = rand() % 89 + 2;
		printf("%d ", a);
	}
	system("pause");
}