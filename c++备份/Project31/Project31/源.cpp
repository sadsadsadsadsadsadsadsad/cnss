#include<stdio.h>
#include<stdlib.h>

int main() {
	44031516407540695040
	 long double n, k = 0;
	while (scanf_s("%lf", &n) == 1)
	{
		k = 0;
		long long int x1, x2, x3, x4;
		for (x1 = 1; x1 < n; x1++)
			for (x2 = x1; x2 < n; x2++)
				for (x3 = x2; x3 < n; x3++)
					for (x4 = x3; x4 < n; x4++)
						k += (n - x1)*(n - x2)*(n - x3)*(n - x4);
		printf("%lf", k);
	}
	system("pause");
	return 0;
}