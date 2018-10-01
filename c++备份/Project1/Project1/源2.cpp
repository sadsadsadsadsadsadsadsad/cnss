#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
class Ctriangle
{

public:
	double a, b, c;
	void display() {
	
cout <<"Criangle:"<<"a="<< a <<"£¬b="<< b <<"£¬c="<< c << endl;
}
	int GetPerimeter()
	{
		double d = a + b + c;
		return(d);
	}
	int GetArea()
	{
		double s;
		s = (a + b + c)/2;
		return(sqrt(s*(s - a)*(s - b)*(s - c)));
	}
};
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	Ctriangle T;
	T.display();
	cout << "Perimeter:" << T.GetPerimeter() << endl;
	cout << "Area:" << T.GetArea() << endl;
	system("pause");
	return 0;
}
