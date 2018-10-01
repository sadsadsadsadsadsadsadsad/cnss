#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a, b;
	scanf_s("%d/%d", &a, &b);
	int c;
	if (a <= b&&b%a == 0)
	{
		b = b / a;
		a = 1;
		printf("%d/%d", a, b);
	}
	else
		printf("%d/%d", a, b);
	system("pause");
}