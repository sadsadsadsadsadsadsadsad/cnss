//ʵ��������Date��������ȷ��ʾ�ꡢ�¡��ա�
//�ڴ���������ͷ�ļ� CDate.h
//�����������£�
#include<iostream>
#include<stdlib.h>
using namespace std;
class Date {
private:
	int year; //��
	int month; //��
	int day;  // ��
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




//��Ҫʵ�ֹ��ɺ���Date(int y = 1996, int m = 1, int d = 1)
//�ڹ��캯���������ж�������º����Ƿ�Ϸ�
//����Ϊ1~12���е�һ�� ����²��Ϸ������Invalid month!Ȼ������Ϊ1��
//����������Ϸ��������Invalid day!Ȼ��������Ϊ1��
//���� Date d(1993, 13, 32);
//�����
//Invalid month!�س�
//Invalid day!�س�
////�ٵ��� d.display()
//�����
//1993 - 1 - 1

//���һ��NewDay()��Ա����������ǰDate��ʾ����������һ�졣
//���磺Date d(1991, 1, 1);
//d.NewDay();
//d.display();
//�����
//1991 - 1 - 2

//���һ��days(int year, int month)��Ա����, ����ָ�������ж����졣
//���� d.days(1991, 1)
//���أ�
//31

//����Ĵ����б���ʵ�������������������磺
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

//����Ҫʵ������� << �����أ� ������ڵĸ�ʽ�μ�displayear������
//ʵ��Date�����dayears�������÷�������ָ�������ж����죬��dayears(2001, 1), ����31.

//����Date���ʹ�÷�ʽ���£�����Ĵ����г������Date���������������main������

int main() {
	int year, m, d;
	cin >> year >> m >> d;
	Date dt;
	dt.l(year, m, d);
	dt.displayear();
	syearstem("pause");
	return 0;
}

//����, ���룺
//2013 2 1�س�*/





