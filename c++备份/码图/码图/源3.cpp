/*������������ָ���2�������ԣ�����3��5��5��7��11��13������������n, �ҳ�С�ڵ���n�������ж��������ԡ���������Եĸ�����
�������룺9
�����2*/
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