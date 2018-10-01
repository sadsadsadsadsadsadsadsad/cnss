//楼新 2017060901014 all rights reserved@mark lou 2018.
//因为之前写过一个有关成绩的系统，所以有的参数变量名没改过来，敬请见谅！
# include <iostream>
# include <fstream>
# include <string.h>
#include <conio.h>
using namespace std;
int j=0;
class Student
{
public:
	char name[20];
	char Id[20];
	char Cnum[20];       
	int Mnum,  num;
	char com[20], part[20]; char work[20];
	Student * Next;
	Student * Head, *End;
	ifstream in;
	ofstream out;
	void ReadFile(istream & in)
	{
		in >> name >> Id >> Cnum >> Mnum >> com >> part >> work >> num;
	}
	 
		
	void Input()
	{
		cout << "\t\t为确保您的账号安全，请再次输入您的姓名：";  cin >> name;	
		cout << "\t\t请输入电话号码：";  cin >> Id;
		cout << "\t\t请输入住址：";  cin >> Cnum;
		cout << "\t\t请输入关系：1.公司用户 2.普通用户";  cin >> Mnum;
		if (Mnum == 1)
		{
			cout << "\t\t请输入单位名称："; cin >> com;
			cout << "\t\t请输入部门名称："; cin >> part;
			cout << "\t\t请输入职务："; cin >> work;
			cout << "\t\t请输入工资号："; cin >> num;
		}
		if (j > 0)
		{
			int len = strlen(name);
			name[len] = j;
		}
	}
	void Show()
	{
		if(Mnum==2)
		cout << "姓名:" << name << endl << "电话:" << Id << endl << "住址:" << Cnum << endl
			<< "关系:" << Mnum << endl << endl;
		else
		{
			cout << "姓名:" << name << endl << "电话:" << Id << endl << "住址:" << Cnum << endl
				<< "关系:" << Mnum <<endl<<"公司:"<<com<<endl<<"部门："<<endl<<"职务"<<work<<endl<<"工资号"<<work<<endl<< endl << endl;
		}
	}
	
};


class Studentmassage
{
public:
	char name[20];
	char Id[20];
	int Cnum;
	int Mnum;
	Student * Next;
	Studentmassage();
	~Studentmassage();
	void ShowMenu();
	void Find();
	void Save();
	void lou();
	void ModifyItem();
	void RemoveItem();
	void Swap(Student *, Student *);
	int ListCount();
	void Display()
	{
		for (Student * p = Head->Next; p != End; p = p->Next)
			p->Show();
		cout << "输入任意字符！继续……";
		_getch();
	}
	void AddItem()
	{
		End->Input();
		End->Next = new Student;
		End = End->Next;
		cout << "添加成功!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
private:
	Student * Head, *End;
	ifstream in;
	ofstream out;
	Student *FindItem(char * name)
	{
		for (Student * p = Head; p->Next != End; p = p->Next)
			if (!strcmp(p->Next->name, name))return p;
		return NULL;
	}
	Student *FindID(char * Id)
	{
		for (Student * p = Head; p->Next != End; p = p->Next)
			if (!strcmp(p->Next->Id, Id))return p;
		return NULL;
	}
};


Studentmassage::Studentmassage()
{
	Head = new Student;
	Head->Next = new Student;
	End = Head->Next;
	in.open("sort.txt");
	if (!in)
		cout << "这是一个新系统，无用户信息。请先输入。" << endl;
	else
	{
		while (!in.eof())
		{
			End->ReadFile(in);
			if (End->name[0] == '\0')break;
			End->Next = new Student;
			End = End->Next;
		}
		in.close();
		cout << "\t\t读取用户信息成功!" << endl;
	}
	char name[20];
	Student * p = NULL;
	if (p = FindItem(name))
	{
		cout << "\t\t已找到用户的信息，请输入新的信息!" << endl;
		p->Next->Input();
		cout << "修改成功！" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
}


Studentmassage::~Studentmassage()
{
	Save();
	for (Student * temp; Head->Next != End;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}


void Studentmassage::ShowMenu()
{
	cout << "********************************************************************************" << endl;
	cout << "〓〓〓〓〓〓〓〓〓〓  ☆   电  话  本 管 理 系  统      ☆  〓〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          1.增加用户信息        ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          2.显示用户信息        ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          3.查找用户信息        ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          4.删除用户信息        ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          5.修改用户信息        ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          0.安全退出系统        ☆  ★〓〓〓〓〓〓〓〓〓" << endl;

	cout << "\n\t\t\n\t\t请选择：";
}

void Studentmassage::lou()
{
	char name[20];
	int n;
	Student * p = NULL;
	cout << "\t\t请输入您的名字：" ;
	cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t名字重复，请问是增加还是覆盖：1，增加 2，覆盖：" ;
		cin >> n;
		if (n == 2)
		{
			Student * p = NULL, *temp = NULL;
			if (p = FindItem(name))
			{
				temp = p->Next;
				p->Next = p->Next->Next;
				delete temp;
			}
		}
		else
		{
			j++;
		}
	}
}

void Studentmassage::Find()
{
	char name[20], Id[10];
	int x;
	Student * p = NULL;
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.按用户的姓名查找\n\t\t※ 2.按用户电话号码查找";
	cout << "\n\t\t*********************************\n请选择：";
	cin >> x;
	switch (x)
	{
	case 1: {cout << "\t\t请输入要查找的用户的姓名："; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "输入任意字符！继续……";
			_getch();
		}
		else
		{
			cout << "\t\t没有找到该姓名的用户！" << '\n' << endl;
			cout << "输入任意字符！继续……";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t\t请输入要查找的用户的电话："; cin >> Id;
		if (p = FindID(Id))
		{
			p->Next->Show();
			cout << "输入任意字符！继续……";
			_getch();
		}
		else
		{
			cout << "\t\t没有找到该电话的用户！" << '\n' << endl;
			cout << "输入任意字符！继续……";
			_getch();
		}
	}break;
	}

}

void Studentmassage::ModifyItem()     
{
	char name[20];
	Student * p = NULL;
	cout << "\t\t请输入要修改的人的姓名:"; cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t已找到用户的信息，请输入新的信息!" << endl;
		p->Next->Input();
		cout << "修改成功！" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
}



void Studentmassage::RemoveItem()        
{
	char name[20];
	Student * p = NULL, *temp = NULL;
	cout << "\t\t请输入要删除的用户的姓名:" ; cin >> name;
	if (p = FindItem(name))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\t删除成功!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
}
int Studentmassage::ListCount()
{
	if (!Head)
		return 0;
	int n = 0;
	for (Student * p = Head->Next; p != End; p = p->Next)
	{
		n++;
	}
	return n;
}
void Studentmassage::Save()
{
	out.open("sort.txt");
	for (Student *p = Head->Next; p != End; p = p->Next)
		out << p->name << "\t" << p->Id << "\t" << p->Cnum << "\t"
		<< p->Mnum <<  '\n';
	out.close();
}

int main()
{
	int x, i = 0;
	bool quit = false;
	cout << "\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§" << endl;
	for (i = 0; i<3; i++)
		cout << "\t\t◎\t\t\t\t\t\t  ◎" << endl;
	cout << "\t\t◎★★★★【  欢迎进入电话本管理系统  】 ★★★★◎" << endl;
	for (i = 0; i<3; i++)
		cout << "\t\t◎\t\t\t\t\t\t  ◎" << endl;
	cout << "\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§\n" << endl;;
	Studentmassage Grade;
	cout << "按任意键开始……";
	_getch();
	while (!quit)
	{
		system("cls");
		Grade.ShowMenu();
		cin >> x;
		switch (x)
		{
		case 0:quit = true; break;
		case 1:Grade.lou(); Grade.AddItem();break;
		case 2:Grade.Display(); break;
		case 3:Grade.Find(); break;
		case 4:Grade.RemoveItem(); break;
		case 5:Grade.ModifyItem(); break;
		}
	}
	return 0;
}
//楼新 2017060901014