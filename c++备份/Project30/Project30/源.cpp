#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
using namespace std;


int  main() {
	char s[1000000];
	int i, j, k = 0, l;
	gets_s(s);
	int a[27];
	for (i = 0; i<26; i++)
	scanf_s("%d", &a[i]);
	char c[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int b[27] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	l = strlen(s);
	for (i = 0; i<l; i++)
		for (j = 0; j<26; j++)
			if (s[i] == c[j])
				b[j]++;
	for (i = 0; i<25; i++)
		if (b[i] == a[i] && b[i + 1] == a[i + 1] && b[i]>0 && b[i + 1]>0 && a[i]>0 && a[i + 1]>0)
		{
			k = 1;
		}
	if (k == 0)
		printf("No\n");
	else
	{
		printf("Yes\n");
	}
	system("pause");
	return 0;
}
