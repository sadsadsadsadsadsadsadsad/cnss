/*输入5个字符，按从小到大顺序排序后输出。
例如：输入：A5av3   输出：35Aav*/
#include <stdio.h>
#include<stdlib.h>
#define N 5

int main()

{

	char str[N];

	char temp;

	for (int i = 0; i<N; i++)

		scanf_s("%c", &str[i]);


	for (int i = 1; i<N; i++)

	{

		for (int j = 0; j<N - i; j++)

		{
			if (str[j] > str[j+1 ])
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}

	}


	for (int i = 0; i<N; i++)

		printf("%c", str[i]);

	printf("\n");
	system("pause");

	return 0;

}
