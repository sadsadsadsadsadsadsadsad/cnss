#include<stdio.h>
#include<string.h>
const char*m[] = {
	"1t","2t","3t","4t","5t","6t","7t","8t","9t",
	"1s","2s","3s","4s","5s","6s","7s","8s","9s",
	"1w","2w","3w","4w","5w","6w","7w","8w","9w",
	"dong","nan","xi","bei","zhong","fa","bai"
};
int convert(char *s) {
	for (int i = 0; i < 34; i++)
		if (strcmp(m[i], s) == 0)
			return i;
	return -1;
}
int c[34];
bool search(int dep) {
	int i;
	for(i=0;i<34;i++)
		if (c[i] >= 3) {
			if (dep == 3)
				return true;
			c[i] -= 3;
			if (search(dep + 1))
				return true;
			c[i] += 3;
		}
	for(i=0;i<=24;i++)
		if (i % 9 <= 6 && c[i] >= 1 && c[i + 1] >= 1 && c[i + 2] >= 1)
		{
			if (dep == 3)
				return true;
			c[i]--; c[i + 1]--; c[i + 2]--;
			if (search(dep + 1))
				return true;
			c[i]++; c[i + 1]++; c[i + 2]++;
		}
	return false;
}
bool check() {
	int i;
	for(i=0;i<34;i++)
		if (c[i] >= 2)
		{
			c[i] -= 2; if (search(0)) return true;
			c[i] += 2;
		}
	return false;
}
int main() {
	int caseno = 0, i, j;
	bool ok;
	char s[100];
	int mj[15];
	while (scanf_s("%s", &s) == 1) {
		if (s[0] == '0') break;
		printf("case %d:", ++caseno);
		mj[0] = convert(s);
		for (int i = 1; i < 13; i++) {
			scanf_s("%s", &s);
			mj[i] = convert(s);
		}
		ok = false;
		for (i = 0; i < 34; i++) {
			memset(c, 0, sizeof(c));
			for (j = 0; j < 13; j++)
				c[mj[j]]++;
			if (c[j] >= 4)
				continue;
			c[j]++;
			if (check()) {
				ok = true;
				printf("%s", m[i]);
			}
			c[i]--;
		}
		if (!ok) printf("not ready");
		printf("\n");
	}
	return 0;
}
