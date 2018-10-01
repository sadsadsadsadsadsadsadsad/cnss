#include <stdio.h>
#include <string.h>
#define maxsum 1000000
char dna[1000];
char dnac[1000][1000];
int main() {
	printf("hello,debug me\n");
	scanf("%s", dna);
	int len = strlen(dna);
	printf("Successfully!\n");
	for (int i = 0; dna[i] != 0; i++) {
		int a = 0;
		//´¢´æµÚi+1¸ö×Ö·û´®£»
		for (int j = i, first = 0;;) {
			if (j == i) if (first) break;
			first = 1;
			dnac[i][a++] = dna[j++];
			if (dna[j] == 0) j = 0;
		}
	}

	int num[20];
	memset(num, 0, sizeof(num));
	int min;
	for (int i = 0; i<len; i++) {
		min = maxsum;
		for (int j = 0; j<len; j++) {
			num[j] += dnac[j][i];
		}
		for (int j = 0; j<len; j++) {
			if (min > num[j]) min = num[j];
		}

		for (int j = 0; j<len; j++) {
			if (num[j]>min) num[j] = maxsum;
		}
	}

	int i;
	for (i = 0; i<len; i++) {
		if (min == num[i]) break;
	}

	printf("%s", dnac[i]);
	printf("\n");

	return 0;
}
