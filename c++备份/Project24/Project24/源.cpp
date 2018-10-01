#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, m,t;
	scanf_s("%d%d", &n, &m);
	int r[6], y[6];
	for (int i = 0; i < n; i++)
		scanf_s("%d", &r[i]);
	for (int i = 0; i < m; i++)
		scanf_s("%d", &y[i]);
	int b,s=0;
	for (int i = 0; i < n; i++)
	{
		b = 0;

		for (int j = 0; j < m; j++)
			if (r[i] <= y[j])
				b = 1;
		if (b == 0)
			s = 1;
	}	
	if (s == 1 || n > m)
		printf("Loowater is doomed");
	else
	{
		for (int i = 0; i < n; i++)
		for (int i = 0; i < n - 1; i++)
			if (r[i] > r[i + 1])
			{
				t = r[i];
				r[i] = r[i + 1];
				r[i + 1] = t;
			}
		for (int i = 0; i < m ; i++)
		for (int i = 0; i < m - 1; i++)
			if (y[i] > y[i + 1])
			{
				t = y[i];
				y[i] = y[i + 1];
				y[i + 1] = t;
			}
		int s = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (r[i] <= y[j])
				{
					s += y[j];
					y[j] = 0;
					i++;
				}
				if (i == n)
					printf("%d", s);
			}
		
	}
	system("pause");
	return 0;
}