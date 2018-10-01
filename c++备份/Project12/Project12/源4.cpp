//实现日期类Date，它能正确表示年、月、日。
//在代码中引入头文件 CDate.h
//它的内容如下：
#include<iostream>
#include<stdlib.h>
using namespace std;
class Date {
private:
	int year; //年
	int month; //月
	int day;  // 日
public:

	Date(int y = 1996, int m = 1, int d = 1);
	int days(int y, int m) ;
	void NewDay();
	
	void display()
	{
		cout << year << "-" << month << "-" << day << endl;
	}

};
Date::Date(int y,int m, int d)
{
	year = y;  month = m; day = d;
	if (m > 12 || m < 1)
	{
		cout << "Invalid month!" << endl;
		month = 1;
	}
	if (d > days(y, m))
	{
		cout << "Invalid day!" << endl;
		day = 1;
	}
}
int Date::days(int y, int m)
{
	year = y;  month = m; 
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
		if (i == 0)
			return 29;
		else return 28;
	}
}
void Date::NewDay()
{
	day++;
	if (day>days(year, month))
	{
		day= 1; month++;
		if (month > 12)
			month = 1; year++;
	}

}




//需要实现构成函数Date(int y = 1996, int m = 1, int d = 1)
//在构造函数内依次判断输入的月和日是否合法
//即月为1~12月中的一个 如果月不合法则输出Invalid month!然后将月置为1。
//如果天数不合法，则输出Invalid day!然后将天数置为1。
//例如 Date d(1993, 13, 32);
//输出：
//Invalid month!回车
//Invalid day!回车
////再调用 d.display()
//输出：
//1993 - 1 - 1

//设计一个NewDay()成员函数，将当前Date表示的日期增加一天。
//例如：Date d(1991, 1, 1);
//d.NewDay();
//d.display();
//输出：
//1991 - 1 - 2

//设计一个days(int year, int month)成员函数, 返回指定年月有多少天。
//例如 d.days(1991, 1)
//返回：
//31

//在你的代码中必须实现以上三个方法，例如：
//#include "CDate.h"
//Date::Date(int y = 1996, int m = 1, int d = 1) {
//	...
//}
//int  Date::days(int year, int month) {
//	...
//}
//void Date::NewDay() {
//	...
//}
/*#include<iostream>
#include<stdlib.h>
using namespace std;
class Date {
public:
	void l(int y, int m, int d) {
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
	int dayear;
};

//你需要实现运算符 << 的重载， 输出日期的格式参见displayear方法。
//实现Date对象的dayears方法，该方法返回指定年月有多少天，如dayears(2001, 1), 返回31.

//最终Date类的使用方式如下，在你的代码中除了完成Date函数还需包含以下main函数：

int main() {
	int year, m, d;
	cin >> year >> m >> d;
	Date dt;
	dt.l(year, m, d);
	dt.displayear();
	syearstem("pause");
	return 0;
}

//例如, 输入：
//2013 2 1回车*/





