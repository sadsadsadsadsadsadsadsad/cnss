#include<stdio.h>
#include<stdlib.h>
int a[1000];
void  sort(int n,int a[]) {
	for (int l = 0; l<n; l++)
		for (int k = 0; k<n - 1; k++)
			if (a[k] > a[k + 1])
			{
				int t;
				t = a[k];
				a[k] = a[k + 1];
				a[k + 1] = t;
			}

}
int  loop(int m,int n,int a[]) {
	for (int i = n - 1; i >= 0; i--)
	{

		if (m - a[i] >= 5)
		{
			m -= a[i]; a[i] = 0;
			if (i != 0)
				continue;
			if (i == 0)
				break;
		}
		

	}
	return m;
}
int main() {
	int n ;
	while (scanf_s("%d", &n) == 1&&n) {
		for (int i = 0; i < n; i++)
			scanf_s("%d", &a[i]);
		sort(n, a);
		int m = 0;

		scanf_s("%d", &m);

		m=loop(m, n, a);
		sort(n, a);
		m=loop(m, n, a);
		if (m >= 5)
		m -= a[n - 1];
		printf("%d", m);
	}

	system("pause");
	return 0;
}
