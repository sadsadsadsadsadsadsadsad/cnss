#include <iostream>
using namespace std;
class Shape {
public:
	Shape() {}
	~Shape() {}
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	static Shape* createRectangle(double length, double width);
	static Shape* createCircle(double radius);
};
class Rectangle  pudlic Shape
{

};

//��Shape��������Rectangle���Circle��, Rectangle���г������ԣ�Circle���а뾶����

//ʵ��������Rectangle��Circle��GetArea()��GetPerimeter()������ 

//Circle���GetArea����Բ�ε������GetPerimeter����Բ�ε��ܳ���

//Rectangle���й��캯��Rectangle(double l, double w)
//Circle���й��캯��Circle(double r)

//����Ĵ����г���ʵ���������໹�����createRectangle��createCircle��ʵ�֣�
//���ǵ�ʵ�ֱ�����Rectangle���Circle��Ķ���֮��ʵ�����£�
//Shape * Shape::createRectangle(double l, double w) { return new Rectangle(l, w); }
//Shape * Shape::createCircle(double r) { return new Circle(r); }





