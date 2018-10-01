/*����һ��Point�࣬Ԫ�ذ�����int x, int y; �������������캯��Point(int x, int y)��int getX(), int getY()�� 
����һ��Circle�࣬Ԫ�ذ�����Point p, int r; ���������� Circle(int x, int y, int r), int getR(), int judge(Circle c)----
�ж�����Բ��λ�ù�ϵ���غϷ���0, �ں�����1, ���з���2, �ཻ����3, ���з���4, ���뷵��5��������ɺ󣬰��������������Ƶ��Լ��ĳ����У���֤��Ĺ��ܡ�
int main()
{
	Circle c1(0, 0, 1);
	Circle c2(1, 1, 1);
	int result1 = c2.judge(c1);
	cout << result1;
	Circle c3(-2, -2, 1);
	int result2 = c2.judge(c3);
	cout << result2 << endl;
	return 0;
}*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class point
{
private:
	int x;
	int y;
public:
	
	point(int x, int y)
	{
		getX();
		getY();
	}
	void  getX()
	{
		this->x = x;
	}
	void  getY()
	{
		this->y = y;
	}
};
class Circle
{
private:
	int r,x,y;
public:
	Circle(int x, int y, int r) 
	{
		this->x = x;
		this->y = y;
		this->r = r;
		
	}
	


	int judge(Circle c) 
	{
		double d = sqrt(double((c.x - x)*(c.x - x) + (c.y - y)*(c.y - y)));
		if (d > r + c.r)
			return 5;
		if (d == 0)
			return 0;
		if (d < r - c.r || d < c.r - r)
			return 1;
		if (d == r - c.r || d == c.r - r)
			return 2;
		if (d < r + c.r)
			return 3;
		if (d == r + c.r)
			return 4;
	}
};

int main()
{
	Circle c1(0, 0, 1);
	Circle c2(1, 1, 1);
	int result1 = c2.judge(c1);
	cout << result1;
	Circle c3(-2, -2, 1);
	int result2 = c2.judge(c3);
	cout << result2 << endl;
	return 0;
}

