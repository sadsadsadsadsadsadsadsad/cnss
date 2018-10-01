
//引入头文件Person.h，它的内容如下：
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

//实现Student类和Teacher类，他们都继承至Person类，
//St//udent类增加表示专业的major属性，Teacher类增加表示职称的position属性。
//实现Student类的display方法，只输出major属性，输出格式参照Person类的display方法
//实现Teacher类的dispaly方法，只输出position属性，输出格式参照Person类的display方法

//实现Stu_Teacher类，该类由Student类和Teacher类共同派生出需实现该类的display方法，输出所有属性，
//注意先输出major属性，再输出position属性。

//必须实现Person类的
/*Person* createStu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major);
Person* createStudent(char *name, char sex, char *ID, char *birthday, char *major);
Person* createTeacher(char *name, char sex, char *ID, char *birthday, char *position);
三个方法，实现如下：

Person* Person::createStudent(char *name, char sex, char *ID, char *birthday, char *major) {
	return new Student(name, sex, ID, birthday, major);
}
Person* Person::createTeacher(char *name, char sex, char *ID, char *birthday, char *position) {
	return new Teacher(name, sex, ID, birthday, position);
}
Person* Person::createStu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major) {
	return new Stu_Techer(name, sex, ID, birthday, position, major);
}

上述三个方法的实现必须在Student类、Teacher类和Stu_Teacher类的定义之后。





*/