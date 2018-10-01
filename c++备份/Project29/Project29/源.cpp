#include<iostream>
#include<stdlib.h>
using namespace std;

int n=0;
double jjj(double m) {
	
	m =m+ m*0.035 - 6000*12;
	n++;
	return m;
}
int main() {
	double m = 1000000;
	m = m*(1 + 0.035)*(1 + 0.035)*(1 + 0.035);
	while (1) {
		if (m >= 0) {
			m=jjj(m);
		}
		if (m < 0)
		{
			break;
		}

	}
	printf("%d", n);
	system("pause");
	return 0;
}