#include<iostream>
using namespace std;
class Location {
private:
	int X, Y;
public:
	void init(int initX, int initY) {
		X = initX;
		Y = initY;
	}
	int GetX() {
		return X;
	}
	int GetY() {
		return Y;
	}
};
int main() {
	Location A1;
	A1.init(20, 90);
	cout<<A1.GetX()<<A1.GetY();//����һ��ָ��A1������rA1
	
	//��rA1����Ļ�������������A1�����ݳ�ԱX��Y��ֵ;
		return 0; 
}
