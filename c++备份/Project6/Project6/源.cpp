#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c,d, h, m;
	char n[2];
	scanf_s("%d:%d", &a,&b);
		c = a % 10; d = a / 10;
		if (a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || (a == 5&&b<=50)||a==10||a==11||a==12||a==13||(a==15&&a<=51)||a==14||a==20||a==21||a==22)
		{
			if (b > (c * 10 + d))
				printf("%d", 70 - (b - (c * 10 + d)));
			else
				printf("%d", c * 10 + d - b);
		}

		if (a == 23)
			printf("%d", 60 - b);
		if (a==6||a == 7 || a == 8 || a == 9||(a=5&&b>50))
			printf("%d", (9 - a) * 60 + 61 - b);
		if (a == 15&&a>51)
			printf("%d", (19 - a) * 60 + 62 - b);
		if( a == 16 || a == 17 || a == 18 || a == 19)
			printf("%d", (19 - a) * 60 + 62 - b);
	system("pause");
	return 0;
}