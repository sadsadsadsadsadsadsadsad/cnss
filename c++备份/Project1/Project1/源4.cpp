/*���һ��ѧ����Student������ѧ��ѧ�ţ��10λ��������������֧�������12λ�������ſγ̳ɼ��Ȼ�����Ϣ��
����ÿ�ſγ�ѧ����ƽ���ɼ���

��ʵ��Student��display��Ա�������������ѧ�� ���� �����ſεĳɼ���ÿ������Կո����
��Ա���� average1, average2, average3, �ֱ𷵻����ſε�ƽ���ɼ���

Student���ʹ�÷���������ʾ������Ĵ����г���ʵ��Student�࣬�����������´��룺*/
#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {

	char name1[10], name2[10], name3[10];
	char num1[12], num2[12], num3[12]; 
	double grade1[3], grade2[3], grade3[3];
	double average1, average2, average3;
	cin >> name1 >> num1 >> grade1[0] >> grade1[1] >> grade1[2];
	cin >> name2 >> num2 >> grade2[0] >> grade2[1] >> grade2[2];
	cin >> name3 >> num3 >> grade3[0] >> grade3[1] >> grade3[2];
	cout << name1<<" "<< num1<<" " << grade1[0]<<" "  << grade1[1]<<" "<< grade1[2] << endl;
	cout << name2 << " " << num2 << " " << grade2[0] << " " << grade2[1] << " " << grade2[2] << endl;
	cout << name3 << " "<< num3 << " " << grade3[0] << " " << grade3[1] << " " << grade3[2] << endl;
	average1= (grade1[0] + grade2[0] +grade3[0])/3;
	average2=  (grade2[1] + grade1[1] + grade3[1]) / 3;
	average3= (grade2[2] + grade1[2] + grade3[2]) / 3;
	cout << "The average grade of course1:" << average1<< endl;
	cout << "The average grade of course2:" << average2 << endl;
	cout << "The average grade of course3:" <<average3 << endl;
	system("pause");
	return 0;
}
/*��������ִ��ʱ
���룺
200906294 LiWeiwei 88 75 91 200902164 ChenHanfu 86 78 93 200908079 ZhanGaolin 94 69 97
�����
200906294 LiWeiwei 88 75 91�س�
200902164 ChenHanfu 86 78 93�س�
200908079 ZhanGaolin 94 69 97�س�
The average grade of course1 : 89.3333�س�
The average grade of course2 : 74�س�
The average grade of course3 : 93.6667�س�*/