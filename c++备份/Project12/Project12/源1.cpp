//��������� << , ʹ֮�ܹ�ʹ��cout��Date������ֻ�����ڸ�ʽ�����Date��Ķ������£�
//����Ĵ����������Date��Ķ����ʵ�֡�
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

//����Ҫʵ������� << �����أ� ������ڵĸ�ʽ�μ�display������
//ʵ��Date�����days�������÷�������ָ�������ж����죬��days(2001, 1), ����31.

//����Date���ʹ�÷�ʽ���£�����Ĵ����г������Date���������������main������

int main() {
	int y, m, d;
	cin >> y >> m >> d;
	Date dt;
	dt.l(y,m,d);
	dt.display();
	system("pause");
	return 0;
}

//����, ���룺
//2013 2 1�س�
//�����
//2013 - 2 - 1�س�


