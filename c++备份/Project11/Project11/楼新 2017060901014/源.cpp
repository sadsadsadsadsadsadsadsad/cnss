//¥�� 2017060901014 all rights reserved@mark lou 2018.
//��Ϊ֮ǰд��һ���йسɼ���ϵͳ�������еĲ���������û�Ĺ�����������£�
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
		cout << "\t\tΪȷ�������˺Ű�ȫ�����ٴ���������������";  cin >> name;	
		cout << "\t\t������绰���룺";  cin >> Id;
		cout << "\t\t������סַ��";  cin >> Cnum;
		cout << "\t\t�������ϵ��1.��˾�û� 2.��ͨ�û�";  cin >> Mnum;
		if (Mnum == 1)
		{
			cout << "\t\t�����뵥λ���ƣ�"; cin >> com;
			cout << "\t\t�����벿�����ƣ�"; cin >> part;
			cout << "\t\t������ְ��"; cin >> work;
			cout << "\t\t�����빤�ʺţ�"; cin >> num;
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
		cout << "����:" << name << endl << "�绰:" << Id << endl << "סַ:" << Cnum << endl
			<< "��ϵ:" << Mnum << endl << endl;
		else
		{
			cout << "����:" << name << endl << "�绰:" << Id << endl << "סַ:" << Cnum << endl
				<< "��ϵ:" << Mnum <<endl<<"��˾:"<<com<<endl<<"���ţ�"<<endl<<"ְ��"<<work<<endl<<"���ʺ�"<<work<<endl<< endl << endl;
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
		cout << "���������ַ�����������";
		_getch();
	}
	void AddItem()
	{
		End->Input();
		End->Next = new Student;
		End = End->Next;
		cout << "��ӳɹ�!" << endl;
		cout << "���������ַ�����������";
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
		cout << "����һ����ϵͳ�����û���Ϣ���������롣" << endl;
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
		cout << "\t\t��ȡ�û���Ϣ�ɹ�!" << endl;
	}
	char name[20];
	Student * p = NULL;
	if (p = FindItem(name))
	{
		cout << "\t\t���ҵ��û�����Ϣ���������µ���Ϣ!" << endl;
		p->Next->Input();
		cout << "�޸ĳɹ���" << endl;
		cout << "���������ַ�����������";
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
	cout << "��������������������  ��   ��  ��  �� �� �� ϵ  ͳ      ��  ��������������������" << endl;
	cout << "��������������������         ��������         �������������������" << endl;
	cout << "��������������������  ��          1.�����û���Ϣ        ��  �������������������" << endl;
	cout << "��������������������  ��          2.��ʾ�û���Ϣ        ��  �������������������" << endl;
	cout << "��������������������  ��          3.�����û���Ϣ        ��  �������������������" << endl;
	cout << "��������������������  ��          4.ɾ���û���Ϣ        ��  �������������������" << endl;
	cout << "��������������������  ��          5.�޸��û���Ϣ        ��  �������������������" << endl;
	cout << "��������������������  ��          0.��ȫ�˳�ϵͳ        ��  �������������������" << endl;

	cout << "\n\t\t\n\t\t��ѡ��";
}

void Studentmassage::lou()
{
	char name[20];
	int n;
	Student * p = NULL;
	cout << "\t\t�������������֣�" ;
	cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t�����ظ������������ӻ��Ǹ��ǣ�1������ 2�����ǣ�" ;
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
	cout << "\t\t�� 1.���û�����������\n\t\t�� 2.���û��绰�������";
	cout << "\n\t\t*********************************\n��ѡ��";
	cin >> x;
	switch (x)
	{
	case 1: {cout << "\t\t������Ҫ���ҵ��û���������"; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "\t\tû���ҵ����������û���" << '\n' << endl;
			cout << "���������ַ�����������";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t\t������Ҫ���ҵ��û��ĵ绰��"; cin >> Id;
		if (p = FindID(Id))
		{
			p->Next->Show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "\t\tû���ҵ��õ绰���û���" << '\n' << endl;
			cout << "���������ַ�����������";
			_getch();
		}
	}break;
	}

}

void Studentmassage::ModifyItem()     
{
	char name[20];
	Student * p = NULL;
	cout << "\t\t������Ҫ�޸ĵ��˵�����:"; cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t���ҵ��û�����Ϣ���������µ���Ϣ!" << endl;
		p->Next->Input();
		cout << "�޸ĳɹ���" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
	else
	{
		cout << "\t\tû���ҵ�!" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
}



void Studentmassage::RemoveItem()        
{
	char name[20];
	Student * p = NULL, *temp = NULL;
	cout << "\t\t������Ҫɾ�����û�������:" ; cin >> name;
	if (p = FindItem(name))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\tɾ���ɹ�!" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
	else
	{
		cout << "\t\tû���ҵ�!" << endl;
		cout << "���������ַ�����������";
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
	cout << "\t\t���������������������������" << endl;
	for (i = 0; i<3; i++)
		cout << "\t\t��\t\t\t\t\t\t  ��" << endl;
	cout << "\t\t�����  ��ӭ����绰������ϵͳ  �� ������" << endl;
	for (i = 0; i<3; i++)
		cout << "\t\t��\t\t\t\t\t\t  ��" << endl;
	cout << "\t\t���������������������������\n" << endl;;
	Studentmassage Grade;
	cout << "���������ʼ����";
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
//¥�� 2017060901014