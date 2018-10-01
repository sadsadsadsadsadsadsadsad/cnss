#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[4];
	int t;
	for (int i = 0; i<3; i++)
		scanf_s("%d", &a[i]);
	t = a[0];
	a[0] = a[2];
	a[2] = t;
	for (int i = 0; i<3; i++)
		printf("%d", a[i]);
	system("pause");
}
