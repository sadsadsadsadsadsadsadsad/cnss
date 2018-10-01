/*定义一个Point类，元素包括：int x, int y; 方法包括：构造函数Point(int x, int y)，int getX(), int getY()。 
定义一个Circle类，元素包括：Point p, int r; 方法包括： Circle(int x, int y, int r), int getR(), int judge(Circle c)----
判断两个圆的位置关系，重合返回0, 内含返回1, 内切返回2, 相交返回3, 外切返回4, 相离返回5。定义完成后，把以下主函数复制到自己的程序中，验证类的功能。
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

