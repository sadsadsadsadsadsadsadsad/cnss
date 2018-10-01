
//����ͷ�ļ�Person.h�������������£�
#include <iostream>
using namespace std;
class Person {
public:
	Person(char *name, char sex, char *ID, char *birthday) {
		strcpy(this->name, name);
		this->sex = sex;
		strcpy(this->ID, ID);
		strcpy(this->birthday, birthday);
	}
	virtual void display() {
		cout << "Name:" << name << endl;
		cout << "Sex:" << sex << endl;
		cout << "ID:" << ID << endl;
		cout << "Birthday:" << birthday << endl;
	}
	Person* createStu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major);
	Person* createStudent(char *name, char sex, char *ID, char *birthday, char *major);
	Person* createTeacher(char *name, char sex, char *ID, char *birthday, char *position);
private:
	char name[20];
	char sex;
	char ID[20];
	char birthday[12];
};
class Student :public Person
{

};

//ʵ��Student���Teacher�࣬���Ƕ��̳���Person�࣬
//St//udent�����ӱ�ʾרҵ��major���ԣ�Teacher�����ӱ�ʾְ�Ƶ�position���ԡ�
//ʵ��Student���display������ֻ���major���ԣ������ʽ����Person���display����
//ʵ��Teacher���dispaly������ֻ���position���ԣ������ʽ����Person���display����

//ʵ��Stu_Teacher�࣬������Student���Teacher�๲ͬ��������ʵ�ָ����display����������������ԣ�
//ע�������major���ԣ������position���ԡ�

//����ʵ��Person���
/*Person* createStu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major);
Person* createStudent(char *name, char sex, char *ID, char *birthday, char *major);
Person* createTeacher(char *name, char sex, char *ID, char *birthday, char *position);
����������ʵ�����£�

Person* Person::createStudent(char *name, char sex, char *ID, char *birthday, char *major) {
	return new Student(name, sex, ID, birthday, major);
}
Person* Person::createTeacher(char *name, char sex, char *ID, char *birthday, char *position) {
	return new Teacher(name, sex, ID, birthday, position);
}
Person* Person::createStu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major) {
	return new Stu_Techer(name, sex, ID, birthday, position, major);
}

��������������ʵ�ֱ�����Student�ࡢTeacher���Stu_Teacher��Ķ���֮��





*/