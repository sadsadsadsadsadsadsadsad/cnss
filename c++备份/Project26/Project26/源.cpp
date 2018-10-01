#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void h(int n, int k, char d[]) {
	int f = 1;
	for (int i = 1; i <= strlen(d); i++)
	{
		if (d[i - 1] == '4'&&d[i] == '7')
		{
			f = 0;
			if (i % 2 == 0)
				d[i-1] = '7';
			else if (i % 2 == 1)
				d[i ] = '4';

		}
		if (f == 0)
			break;
	}
}
int main() {
	int  n, k; char f[4];
	char d[20];
	scanf_s("%d%d", &n, &k);
	gets_s(f);
	gets_s(d);
	for (int j = 0; j < k; j++)
		h(n, k, d);
	printf("%s", d);
	system("pause");
	return 0;
}