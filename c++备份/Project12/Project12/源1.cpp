//重载运算符 << , 使之能够使用cout将Date类对象的只以日期格式输出，Date类的定义如下，
//在你的代码中需包含Date类的定义和实现。
#include<iostream>
#include<stdlib.h>
using namespace std;
class Date {
public:
	void l(int y , int m , int d ) {
		day = d;
		month = m;
		year = y;
		if (m>12 || m<1)
		{
			month = 1;
		}
		if (d>days(y, m))
		{
			cout << "Invalid day!" << endl;
			day = 1;
		}
	};
	int days(int y, int m)
	{
		int i = 1;
		if (y % 400 == 0 || y % 4 == 0 && y % 400 != 0)
			i = 0;
		if (m == 1 || m == 3)
			return 31;
		if (m == 5 || m == 7)
			return 31;
		if (m == 8 || m == 10)
			return 31;
		if (m == 12)
			return 31;
		if (m == 4 || m == 6)
			return 30;
		if (m == 9 || m == 11)
			return 30;
		if (m == 2)
		{
			if (i = 0)
				return 29;
			else return 28;
		}
	}
	void display() {
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

//你需要实现运算符 << 的重载， 输出日期的格式参见display方法。
//实现Date对象的days方法，该方法返回指定年月有多少天，如days(2001, 1), 返回31.

//最终Date类的使用方式如下，在你的代码中除了完成Date函数还需包含以下main函数：

int main() {
	int y, m, d;
	cin >> y >> m >> d;
	Date dt;
	dt.l(y,m,d);
	dt.display();
	system("pause");
	return 0;
}

//例如, 输入：
//2013 2 1回车
//输出：
//2013 - 2 - 1回车


