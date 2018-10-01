//
//  main.cpp
//  成绩管理系统PLUS
//
//  Created by 龚兴 on 2017/12/16.
//  Copyright © 2017年 龚兴. All rights reserved.
//

#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

class Student//学生类
{
public:
	void InputStudent(void);//输入学生信息
	void OutStudentNumber(void);//输出学生人数
	void OutputStudent(void);//输出学生信息
	void SearchStudent(void);//查找学生信息
	void ScortByChinese(void);//对学生的语文成绩排名
	void SearchChinese(void);//查找语文成绩
	void ScortByMath(void);//对学生的数学成绩排名
	void SearchMath(void);//查找数学成绩
	void ScortByEnglish(void);//对学生的英语成绩排名
	void SearchEnglish(void);//查找英语成绩
	void ScortByProfession(void);//对学生的专业课成绩排名
	void SearchProfession(void);//查找专业课成绩
	void ScortByTotal(void);//对学生的总成绩排名
	void SearchTotal(void);//查找总成绩成绩
private:
	Student *St; //学生类指针
	int Size;    // 学生人数
	wstring Name; //姓名
	wstring Sex; //性别
	int Age; //年龄
	long int No; //学号
	wstring Native; //籍贯
	wstring Academy; //学院
	long int Number; //电话号码
	string Email; //电子邮件
	long int QQ; //QQ号
	float Score[4];//三科的成绩
	float Total;  //总分
};


//输入学生的信息
void Student::InputStudent(void)
{
	int len;//学生的人数
	cout << "请输入学生的人数:";
	cin >> len;

	system("cls");

	Size = len;

	St = new Student[Size];

	for (int i = 0; i<len; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的姓名:";
		wcin >> St[i].Name;

		cout << "请输入第" << i + 1 << "个学生的性别:";
		wcin >> St[i].Sex;

		cout << "请输入第" << i + 1 << "个学生的年龄:";
		cin >> St[i].Age;

		cout << "请输入第" << i + 1 << "个学生的学号:";
		cin >> St[i].No;

		cout << "请输入第" << i + 1 << "个学生的籍贯:";
		wcin >> St[i].Native;

		cout << "请输入第" << i + 1 << "个学生的学院:";
		wcin >> St[i].Academy;

		cout << "请输入第" << i + 1 << "个学生的电话号码:";
		cin >> St[i].Number;

		cout << "请输入第" << i + 1 << "个学生的电子邮件号:";
		cin >> St[i].Email;

		cout << "请输入第" << i + 1 << "个学生QQ号:";
		cin >> St[i].QQ;

		cout << "请输入第" << i + 1 << "个学生的语文成绩:";
		cin >> St[i].Score[0];

		cout << "请输入第" << i + 1 << "个学生的数学成绩:";
		cin >> St[i].Score[1];

		cout << "请输入第" << i + 1 << "个学生的英语成绩:";
		cin >> St[i].Score[2];

		cout << "请输入第" << i + 1 << "个学生的专业课成绩:";
		cin >> St[i].Score[3];

		St[i].Total = St[i].Score[0] + St[i].Score[1] + St[i].Score[2] + St[i].Score[3];

		system("cls");
	}
}

//输出学生人数
void Student::OutStudentNumber(void)
{
	cout << "总人数:" << Size << endl;
}

//输出学生的信息
void Student::OutputStudent(void)
{
	cout << "姓名" << "\t\t\t\t" << "性别" << "\t\t\t\t" << "学号" << "\t\t\t\t" << "语文" << "\t\t\t\t" << "数学" << "\t\t\t\t" << "英语" << "\t\t\t\t" << "专业课" << "\t\t\t\t" << "总分" << "\t\t\t" << "排名" << endl;

	for (int i = 0; i<Size; i++)
	{
		//左对齐
		cout.setf(ios::left); wcout << setw(16) << St[i].Name << setw(16) << St[i].Sex << setw(16) << St[i].No << setw(16) << St[i].Score[0] << setw(16) << St[i].Score[1] << setw(16) << St[i].Score[2] << setw(16) << St[i].Score[3] << setw(16) << St[i].Total << setw(16) << i + 1 << endl;
	}
}

//查找学生信息
void Student::SearchStudent(void)
{
	long int no;
	cout << "请输入你需要查找的学生的学号:";
	cin >> no;

	int i;

	for (i = 0; i<Size; i++)
	{
		if (no == St[i].No)
		{
			break;
		}
	}

	cout << "姓名: ";
	wcout << St[i].Name << endl;
	cout << "性别: ";
	wcout << St[i].Sex << endl;
	cout << "年龄: ";
	cout << St[i].Age << endl;
	cout << "学号: ";
	cout << St[i].No << endl;
	cout << "籍贯: ";
	wcout << St[i].Name << endl;
	cout << "学院: ";
	wcout << St[i].Academy << endl;
	cout << "电子邮件号: ";
	cout << St[i].Email << endl;
	cout << "QQ号: ";
	cout << St[i].QQ << endl;
	cout << "语文: ";
	cout << St[i].Score[0] << endl;
	cout << "数学: ";
	cout << St[i].Score[1] << endl;
	cout << "英语: ";
	cout << St[i].Score[2] << endl;
	cout << "专业课: ";
	cout << St[i].Score[3] << endl;
	cout << "总成绩: ";
	cout << St[i].Total << endl;

}

//对语文成绩排序
void Student::ScortByChinese(void)
{
	for (int i = 1; i<Size; i++)
	{
		int j = i - 1; //设置前值

		Student temp = St[i]; //后值代数

		while (temp.Score[0] > St[j].Score[0] && j >= 0) // 比较后值与前值
		{
			St[j + 1] = St[j]; // 后值前置
			j--;             // 为下步准备
		}
		St[j++] = temp;    // 若while成立（前值后置），否则不交换
	}
}

//查找语文成绩第i名的学生信息
void Student::SearchChinese(void)
{
	int j;
	int i;
	cout << "请输入您要查找的学生排名:";
	cin >> j;
	i = j - 1;

	cout << "姓名: ";
	wcout << St[i].Name << endl;
	cout << "性别: ";
	wcout << St[i].Sex << endl;
	cout << "年龄: ";
	cout << St[i].Age << endl;
	cout << "学号: ";
	cout << St[i].No << endl;
	cout << "籍贯: ";
	wcout << St[i].Name << endl;
	cout << "学院: ";
	wcout << St[i].Academy << endl;
	cout << "电子邮件号: ";
	cout << St[i].Email << endl;
	cout << "QQ号: ";
	cout << St[i].QQ << endl;
	cout << "语文: ";
	cout << St[i].Score[0] << endl;
	cout << "数学: ";
	cout << St[i].Score[1] << endl;
	cout << "英语: ";
	cout << St[i].Score[2] << endl;
	cout << "专业课: ";
	cout << St[i].Score[3] << endl;
	cout << "总成绩: ";
	cout << St[i].Total << endl;
}

//对数学成绩排序
void Student::ScortByMath(void)
{
	for (int i = 1; i<Size; i++)
	{
		int j = i - 1; //设置前值

		Student temp = St[i]; //后值代数

		while (temp.Score[1] > St[j].Score[1] && j >= 0) // 比较后值与前值
		{
			St[j + 1] = St[j]; // 后值前置
			j--;             // 为下步准备
		}
		St[j++] = temp;    // 若while成立（前值后置），否则不交换
	}
}

//查找数学成绩第i名的学生信息
void Student::SearchMath(void)
{
	int j;
	int i;
	cout << "请输入您要查找的学生排名:";
	cin >> j;
	i = j - 1;

	cout << "姓名: ";
	wcout << St[i].Name << endl;
	cout << "性别: ";
	wcout << St[i].Sex << endl;
	cout << "年龄: ";
	cout << St[i].Age << endl;
	cout << "学号: ";
	cout << St[i].No << endl;
	cout << "籍贯: ";
	wcout << St[i].Name << endl;
	cout << "学院: ";
	wcout << St[i].Academy << endl;
	cout << "电子邮件号: ";
	cout << St[i].Email << endl;
	cout << "QQ号: ";
	cout << St[i].QQ << endl;
	cout << "语文: ";
	cout << St[i].Score[0] << endl;
	cout << "数学: ";
	cout << St[i].Score[1] << endl;
	cout << "英语: ";
	cout << St[i].Score[2] << endl;
	cout << "专业课: ";
	cout << St[i].Score[3] << endl;
	cout << "总成绩: ";
	cout << St[i].Total << endl;

}

//对英语成绩排序
void Student::ScortByEnglish(void)
{
	for (int i = 1; i<Size; i++)
	{
		int j = i - 1; //设置前值

		Student temp = St[i]; //后值代数

		while (temp.Score[2] > St[j].Score[2] && j >= 0) // 比较后值与前值
		{
			St[j + 1] = St[j]; // 后值前置
			j--;             // 为下步准备
		}
		St[j++] = temp;    // 若while成立（前值后置），否则不交换
	}
}

//查找英语成绩第i名的学生信息
void Student::SearchEnglish(void)
{
	int j;
	int i;
	cout << "请输入您要查找的学生排名:";
	cin >> j;
	i = j - 1;

	cout << "姓名: ";
	wcout << St[i].Name << endl;
	cout << "性别: ";
	wcout << St[i].Sex << endl;
	cout << "年龄: ";
	cout << St[i].Age << endl;
	cout << "学号: ";
	cout << St[i].No << endl;
	cout << "籍贯: ";
	wcout << St[i].Name << endl;
	cout << "学院: ";
	wcout << St[i].Academy << endl;
	cout << "电子邮件号: ";
	cout << St[i].Email << endl;
	cout << "QQ号: ";
	cout << St[i].QQ << endl;
	cout << "语文: ";
	cout << St[i].Score[0] << endl;
	cout << "数学: ";
	cout << St[i].Score[1] << endl;
	cout << "英语: ";
	cout << St[i].Score[2] << endl;
	cout << "专业课: ";
	cout << St[i].Score[3] << endl;
	cout << "总成绩: ";
	cout << St[i].Total << endl;
}

//对专业课成绩排序
void Student::ScortByProfession(void)
{
	for (int i = 1; i<Size; i++)
	{
		int j = i - 1; //设置前值

		Student temp = St[i]; //后值代数

		while (temp.Score[3] > St[j].Score[3] && j >= 0) // 比较后值与前值
		{
			St[j + 1] = St[j]; // 后值前置
			j--;             // 为下步准备
		}
		St[j++] = temp;    // 若while成立（前值后置），否则不交换
	}
}

//查找专业课成绩第i名的学生信息
void Student::SearchProfession(void)
{
	int j;
	int i;
	cout << "请输入您要查找的学生排名:";
	cin >> j;
	i = j - 1;

	cout << "姓名: ";
	wcout << St[i].Name << endl;
	cout << "性别: ";
	wcout << St[i].Sex << endl;
	cout << "年龄: ";
	cout << St[i].Age << endl;
	cout << "学号: ";
	cout << St[i].No << endl;
	cout << "籍贯: ";
	wcout << St[i].Name << endl;
	cout << "学院: ";
	wcout << St[i].Academy << endl;
	cout << "电子邮件号: ";
	cout << St[i].Email << endl;
	cout << "QQ号: ";
	cout << St[i].QQ << endl;
	cout << "语文: ";
	cout << St[i].Score[0] << endl;
	cout << "数学: ";
	cout << St[i].Score[1] << endl;
	cout << "英语: ";
	cout << St[i].Score[2] << endl;
	cout << "专业课: ";
	cout << St[i].Score[3] << endl;
	cout << "总成绩: ";
	cout << St[i].Total << endl;
}

//对学生总分排名
void Student::ScortByTotal(void)
{
	for (int i = 1; i<Size; i++)
	{
		int j = i - 1;

		Student temp = St[i];

		while (temp.Total > St[j].Total && j >= 0)
		{
			St[j + 1] = St[j];
			j--;
		}
		St[++j] = temp;
	}
}

//查找总成绩第i名的学生信息
void Student::SearchTotal(void)
{
	int j;
	int i;
	cout << "请输入您要查找的学生排名:";
	cin >> j;
	i = j - 1;

	cout << "姓名: ";
	wcout << St[i].Name << endl;
	cout << "性别: ";
	wcout << St[i].Sex << endl;
	cout << "年龄: ";
	cout << St[i].Age << endl;
	cout << "学号: ";
	cout << St[i].No << endl;
	cout << "籍贯: ";
	wcout << St[i].Name << endl;
	cout << "学院: ";
	wcout << St[i].Academy << endl;
	cout << "电子邮件号: ";
	cout << St[i].Email << endl;
	cout << "QQ号: ";
	cout << St[i].QQ << endl;
	cout << "语文: ";
	cout << St[i].Score[0] << endl;
	cout << "数学: ";
	cout << St[i].Score[1] << endl;
	cout << "英语: ";
	cout << St[i].Score[2] << endl;
	cout << "专业课: ";
	cout << St[i].Score[3] << endl;
	cout << "总成绩: ";
	cout << St[i].Total << endl;
}

int main()
{
	cout << "================================================================================\n" << endl;
	cout << "*************************欢迎使用学生信息管理系统************************************\n" << endl;
	cout << "-----------------------------------------------------------------------制作人:龚兴\n" << endl;
	cout << "-------------------------------------------------------------学号：2017060901008\n" << endl;
	cout << "********************************************************************************\n" << endl;
	cout << "================================================================================\n" << endl;

	cout << "请按任意将进入学生管理系统:" << endl;
	getchar();
	system("cls");

	cout << "================================================================================\n\n";
	cout << "------------------------ 请选择要操作的命令----------------------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 1 输入学生信息-----------------------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 2 输出学生人数-----------------------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 3 查找学生信息-----------------------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 4 将学生的语文成绩按从大到小排----------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 5 将学生的数学成绩按从大到小排----------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 6 将学生的英语成绩按从大到小排----------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 7 将学生的专业课成绩按从大到小排---------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 8 将学生的总成绩按从大到小排------------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 9 通过语文成绩排名查找学生信息----------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 10 通过数学成绩排名查找学生信息----------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 11 通过英语成绩排名查找学生信息----------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 12 通过专业课成绩排名查找学生信息---------------------------\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "-------------------------- 13 通过总成绩排名查找学生信息------------------------------\n\n";
	cout << "================================================================================\n\n";

	int Item;//操作命令

	Student st;//学生对象

	while (1)
	{
		cout << "请选择操作命令:";
		cin >> Item;
		system("cls");//清屏

		switch (Item)
		{
		case 1://输入学生信息
		{
			st.InputStudent();
		}
		break;

		case 2://
		{
			st.OutStudentNumber();
		}
		break;

		case 3://查找学生信息
		{
			st.SearchStudent();
		}
		break;

		case 4://
		{
			st.ScortByChinese();
			st.OutputStudent();
		}
		break;

		case 5://
		{
			st.ScortByMath();
			st.OutputStudent();
		}
		break;

		case 6://
		{
			st.ScortByEnglish();
			st.OutputStudent();
		}
		break;

		case 7://
		{
			st.ScortByProfession();
			st.OutputStudent();
		}
		break;

		case 8://对学生的总分排序
		{
			st.ScortByTotal();
			st.OutputStudent();
		}
		break;

		case 9://
		{
			st.SearchChinese();
		}
		break;

		case 10://
		{
			st.SearchMath();
		}
		break;

		case 11://
		{
			st.SearchEnglish();
		}
		break;

		case 12://
		{
			st.SearchProfession();;
		}
		break;

		case 13://
		{
			st.SearchTotal();
		}
		break;

		default:
			break;
		}
	}
	return 0;
}























