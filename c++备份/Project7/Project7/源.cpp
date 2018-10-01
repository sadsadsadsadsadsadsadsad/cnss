#include<stdio.h>
#include<stdlib.h>
# define max 100
int input(int *a)
{
	int i;
	for (i = 0; i < max; i++)
	{
		if(scanf_s("%d",&a[i])!=1)
			break;
	}
	return i;
}
void main()
{
	int a[max];
	int n ,i,c,p;
	n = input(a);
	int b[max],d[max];
	c = input(b);
	if (n == c)
		for (i = 0; i < n; i++)
		d[i]= a[i] - b[i];
	if (n > c)
	{
		for (i = 0; i < c; i++)
			d[i] = a[i] - b[i];
		for (i = c; i < n; i++)
			d[i] = a[i];
	}
	if (n < c)
	{
		for (i = 0; i < n; i++)
			d[i] = a[i] - b[i];
		for (i = n; i < c; i++)
			d[i] = b[i];
	}
	if (d[n - 1] < 0 || d[c - 1] < 0)
	{
		if (n >= c)
			d[n - 1] = -d[n - 1];
		else
			d[c - 1] = d[c - 1];
	}
	if (n >= c)
		for (i = 0; i < n; i++)
			printf("%nd", a[i]);
	else
		for (i = 0; i < c; i++)
			printf("%cd", a[i]);
	system("pause");
}