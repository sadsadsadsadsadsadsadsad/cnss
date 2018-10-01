# include <iostream>
# include <fstream>
# include <string.h>
#include <conio.h>
using namespace std;
class Student
{
public:
	char name[20];
	char Id[20];
	int Cnum;       
	int Mnum;       
	int sum;         
	Student * Next;
	void Input()
	{
		cout << "\t\t������ѧ����������";  cin >> name;
		cout << "\t\t������ѧ����ѧ�ţ�";  cin >> Id;
		cout << "\t\t���������Ŀγ̵ĳɼ���";  cin >> Cnum;
		cout << "\t\t��������ѧ�γ̵ĳɼ���";  cin >> Mnum;
		sum = Cnum + Mnum ;
	}
	void ReadFile(ifstream & in)
	{
		in >> name >> Id >> Cnum >> Mnum  >> sum;
	}
	void Show()
	{
		cout << "����:" << name << endl << "ѧ��:" << Id << endl << "����:" << Cnum << endl
			<< "��ѧ:" << Mnum << endl << "�ܳɼ�:" << sum << endl << endl << endl;
	}
};
class Studentmassage
{
public:
	Studentmassage();
	~Studentmassage();
	void ShowMenu();
	void Find();
	void Save();
	void ModifyItem();
	void RemoveItem();
	void Swap(Student *, Student *);
	void Sort();
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
		cout << "����һ����ϵͳ����ѧ����Ϣ���������롣" << endl;
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
		cout << "\t\t��ȡѧ����Ϣ�ɹ�!" << endl;
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
	cout << "��������������������  ��   ѧ �� �� �� �� �� ϵ  ͳ     ��  ��������������������" << endl;
	cout << "��������������������         ��������         �������������������" << endl;
	cout << "��������������������  ��          1.����ѧ���ɼ�        ��  �������������������" << endl;
	cout << "��������������������  ��          2.��ʾѧ���ɼ�        ��  �������������������" << endl;
	cout << "��������������������  ��          3.����ͳ�Ƴɼ�        ��  �������������������" << endl;
	cout << "��������������������  ��          4.����ѧ���ɼ�        ��  �������������������" << endl;
	cout << "��������������������  ��          5.ɾ��ѧ���ɼ�        ��  �������������������" << endl;
	cout << "��������������������  ��          6.�޸�ѧ����Ϣ        ��  �������������������" << endl;
	cout << "��������������������  ��          0.��ȫ�˳�ϵͳ        ��  �������������������" << endl;

	cout << "\n\t\t\n\t\t��ѡ��";
}
void Studentmassage::Find()
{
	char name[20], Id[10];
	int x;
	Student * p = NULL;
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.��ѧ������������\n\t\t�� 2.��ѧ��ѧ�Ų���";
	cout << "\n\t\t*********************************\n��ѡ��";
	cin >> x;
	switch (x)
	{
	case 1: {cout << "\t\t������Ҫ���ҵ�ѧ����������"; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "\t\tû���ҵ���������ѧ����" << '\n' << endl;
			cout << "���������ַ�����������";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t\t������Ҫ���ҵ�ѧ����ѧ�ţ�"; cin >> Id;
		if (p = FindID(Id))
		{
			p->Next->Show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "\t\tû���ҵ���ѧ�õ�ѧ����" << '\n' << endl;
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
		cout << "\t\t���ҵ�ѧ������Ϣ���������µ���Ϣ!" << endl;
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
	cout << "\t\t������Ҫɾ����ѧ��������:" << endl; cin >> name;
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
void Studentmassage::Swap(Student *p1, Student *p2)
{
	Student *temp = new Student;
	strcpy_s(temp->name, p1->name);
	strcpy_s(temp->Id, p1->Id);
	temp->Cnum = p1->Cnum;
	temp->Mnum = p1->Mnum;
	temp->sum = p1->sum;

	strcpy_s(p1->name, p2->name);
	strcpy_s(p1->Id, p2->Id);
	p1->Cnum = p2->Cnum;
	p1->Mnum = p2->Mnum;
	p1->sum = p2->sum;

	strcpy_s(p2->name, temp->name);
	strcpy_s(p2->Id, temp->Id);
	p2->Cnum = temp->Cnum;
	p2->Mnum = temp->Mnum;
	p2->sum = temp->sum;
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
void Studentmassage::Sort()
{
	cout << "Sorting..." << endl;
	Student *p = NULL, *p1 = NULL, *k = NULL;
	int n = Studentmassage::ListCount();
	if (n<2)
		return;
	for (p = Head->Next; p != End; p = p->Next)
		for (k = p->Next; k != End; k = k->Next)
		{
			if (p->sum>k->sum)
			{
				Studentmassage::Swap(p, k);
			}
		}
	cout << "������ɣ�" << endl;
	_getch();
	return;
}
void Studentmassage::Save()
{
	out.open("sort.txt");
	for (Student *p = Head->Next; p != End; p = p->Next)
		out << p->name << "\t" << p->Id << "\t" << p->Cnum << "\t"
		<< p->Mnum << "\t" << p->sum << '\n';
	out.close();
}
int main()
{
	int x, i = 0;
	bool quit = false;
	cout << "\t\t���������������������������" << endl;
	for (i = 0; i<3; i++)
		cout << "\t\t��\t\t\t\t\t\t  ��" << endl;
	cout << "\t\t�����  ��ӭ����ѧ���ɼ�����ϵͳ  ��������" << endl;
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
		case 1:Grade.AddItem(); break;
		case 2:Grade.Display(); break;
		case 3:Grade.Sort(); break;
		case 4:Grade.Find(); break;
		case 5:Grade.RemoveItem(); break;
		case 6:Grade.ModifyItem(); break;
		}
	}
	return 0;
}
