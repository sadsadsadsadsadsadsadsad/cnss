#include<stdio.h>
#include<stdlib.h>

double jjj(double n,float r){
	double h = 1; 
	
	for (int i = 1; i <= n; i++)
		h *= r;
	return h;
}
int main() {
	double n=7,m=0,j;
	float r;
	while (1)
	{
		m = 0;
		scanf_s("%f", &r);
		for (int i = 1; i <= n; i++)
			m += jjj(i, 1/(1+r));

		
		printf("%f", m);
	}
	system("pause");
	return 0;
}