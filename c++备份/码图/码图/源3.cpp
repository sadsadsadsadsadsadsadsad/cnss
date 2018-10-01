/*孪生素数就是指相差2的素数对，例如3和5，5和7，11和13。输入正整数n, 找出小于等于n的数中有多少素数对。输出素数对的个数。
例如输入：9
输出：2*/
#include<stdio.h>
#include<stdlib.h>
int p = 0;
int susu(int s)
{
	int r = 0;
	for (int i = 2; i < s; i++)
		if (s%i == 0)
			r = 1;
	if (r == 0)
		return 1;
	else
		return 0;
}
void main()
{
	int a;
	scanf_s("%d", &a);
	for (int i = 5; i <= a; i++)
		if (susu(i) == 1 && susu(i - 2) == 1)
			p++;
	printf("%d", p);
	system("pause");
}