//����һ������Point, �������Ա����double Distance(const & Point) ������ľ��롣
//��������������꣬
//���������㣬 Ȼ�����Point���Distance�������������ľ��롣

//Point ���ʹ�÷�ʽ���£�
#include<iostream>
#include<math.h>
using namespace std;
class Point
{
private :
	double x, y;
public:
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double Getx()
	{
		return x;
	}
	double Gety()
	{
		return y;
	}
	double Distance(const Point&p)
	{
		x -= p.x;
		y -= p.y;
		return sqrt(x*x + y*y);
	}
};
int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	Point A(a, b), B(c, d);
	cout << A.Distance(B) << endl;
	return 0;
}

//�����룺
//1 2 3 4�س�
//�����
//2.82843