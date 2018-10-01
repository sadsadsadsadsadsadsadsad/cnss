#include<stdio.h>
#include<stdlib.h>
int main1()
{
	int l, t; int n;
	scanf_s("%d%d%d", &l, &t, &n);
	int m[6]; int k[6];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &m[i]);
		scanf_s("%d", &k[i]);
		getchar();
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (k[j] ==1)
				m[j]++;
			if (k[j] == 2)
				m[j]--;
		}
		for(int c=0;c<n;c++)
			for (int v = 0; v < n; v++)
			{
				if (m[c] == m[v]&&c!=v)
				{
					if (k[c] == 1)
						k[c] = 2;
					if (k[c] == 2)
						k[c] = 1;
					if (k[v] == 1)
						k[v] = 2;
					if (k[v] == 1)
						k[v] = 2;
				}
			}
	}
	for (int i = 0; i < n; i++)
	{
		int w=0;
		if (m[i] < 0 || m[i] > l)
		{
			printf("Fell off");
			printf("\n");
			w = 1;
		}
		if (w == 0)
		{
			int b;
			b = 0;
			printf("%d ", m[i]);
				for (int v = 0; v < n; v++)
				{
					if (m[i] == m[v] && i != v)
					{
						b = 1;
						printf("Turning");
						printf("\n");
					}
				}
				if(b==0)
					{
						printf("%d", k[i]);
						printf("\n");
					}
				
		}
	}
	return 0;
}
int main()
{
	int e;
	scanf_s("%d", &e);
	while (e--)
	{
		main1();
	}
	system("pause");
	return 0;
}