//设计一个User类，要求User类可以保持多个用户的用户名和密码信息，
//实现User类的构造函数和AddUser方法添加新用户，
//实现int login(char *name, char * pass)方法，该方法接受用户名和密码，
//判断用户名对应的密码是否正确，如果正确返回用户的编号，如果不正确返回 - 1。

//User类的使用示意如下所示，在你的代码中除了实现User类以外，还需一如如下main函数
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class User
{
public:
	char name[20]; char pass[20];
	char name1[20]; char pass1[20];
	void AddUser(char name[],char pass[]);
	int login(char name1[], char pass1[]);
};
void User::AddUser(char a[], char b[])
{	
	strcpy_s(name, a);
	strcpy_s(pass, b);
}
int User::login(char *c, char *d)
{
	int m = 0, j = 0;
	int len2 = strlen(c);
	for (int i = 0; i < len2; i++)
		if (c[i] != name[i])
			m = 1;
	if (m = 0) {
		int len3 = strlen(d);
		for (int i = 0; i < len3; i++)
		{
			if (d[i] != pass[i])
				j = 1;
		}
		if (j == 0 && m == 0)
			return 1;
		else
			return -1;
	}
}
int main()
{
	char name[10], name1[10], pass[10], pass1[10];
	cin >> name >> pass >> name1 >> pass1;
	User user;
	user.AddUser(name, pass);
	if (user.login(name1, pass1) >= 0)
	{
		cout << "Success Login!" << endl;
	}
	else {
		cout << "Login failed!" << endl;
	}
	system("pause");
	return 0;
}

//例如输入：
//test 1234567 test 123456回车
//输出：
//Login failed!

