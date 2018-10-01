#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void main()
{
	FILE*fp;
	int x; 
	if ((fopen_s(&fp,"f1.txt", "w+")) == NULL)
	{
		printf("can't open this file!\n");
		exit(1);
	}
	printf("input your numbers:");
	scanf_s("%d", &x);
	fprintf(fp, "%6d", x);
	fclose(fp);

	if ((fopen_s(&fp, "f1.txt", "w+")) == NULL)
	{
		printf("can't open this file!\n");
		exit(2);
	}
	fscanf_s(fp, "%d", &x);
	printf("%6d", x);
	printf("\n");
	fclose(fp);
	printf("time used:%.2fs", (double)clock() / CLOCKS_PER_SEC);
	system("pause");
}


