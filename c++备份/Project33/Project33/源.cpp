#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int m, n;
	cout << "行数:";
	cin >> m;
	cout << "列数:";
	cin >> n;
	int a[100][100];
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];

		}
	float  r[100];
	for (int i = 0; i < m; i++)
	{
		r[i] = 0;
		}
			
			for (int k = 0; k < m; k++) {
				for (int j = 0; j < n; j++)
				{
					r[k] += a[k][j];
				}
			}
		
		for (int i = 0; i < m; i++)
			cout << r[i]/n  << endl;
		system("pause");
		return 0;
}
