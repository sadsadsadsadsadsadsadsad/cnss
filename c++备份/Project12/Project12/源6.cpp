//��������fraction���������Ķ��壬�������ص������ << �Է�����ʽ������
//���罫����֮�����Ϊ2 / 3, �ں����������ʵ������ݡ����ύʱ��Ҫ�ύһ��������Դ�ļ�������ֻ�ύ��ղ��֣�
#include <iostream>
#include<conio.h>
using namespace std;
class fraction {
public:
	int den;//����
	int num;//��ĸ
	fraction(int d, int n) {
		den = d;
		num = n;
	}
	friend ostream& operator <<(ostream&, fraction);
};
ostream &operator <<(ostream& os, fraction fr) {
	cout << fr.den << '/' << fr.num;
	return os;
}
int main() {
	int den, num;
	cin >> den >> num;
	fraction fr(den, num);
	cout << fr << endl;
	_getch();
	return 0;
}

//���磬���룺
//4 5�س�
//�����
//4 / 5