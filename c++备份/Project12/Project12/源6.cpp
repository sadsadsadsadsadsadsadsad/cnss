//下面是类fraction（分数）的定义，其中重载的运算符 << 以分数形式输出结果
//例如将三分之儿输出为2 / 3, 在横线上填上适当的内容。（提交时需要提交一个完整的源文件，不能只提交填空部分）
#include <iostream>
#include<conio.h>
using namespace std;
class fraction {
public:
	int den;//分子
	int num;//分母
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

//例如，输入：
//4 5回车
//输出：
//4 / 5