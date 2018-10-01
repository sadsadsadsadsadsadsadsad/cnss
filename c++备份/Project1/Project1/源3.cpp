/*ʵ��ʱ����Clock, (24Сʱ�ƣ�0~23)
�ڴ���������ͷ�ļ� Clock.h
���Ķ������£�*/
#include <iostream>
#include<stdlib.h>
using namespace std;
class Clock {
public:
	Clock(int h, int m, int s);
	void SetAlarm(int h, int m, int s);
	void run();
	void ShowTime() {
		cout << "Now:" << hour << ":" << minute << ":" << second << endl;
	}
private:
	int hour;   //ʱ
	int minute;  //��
	int second;  //��

	int Ahour;   //ʱ�����ӣ�
	int Aminute;  //�֣����ӣ�
	int Asecond;   //�루���ӣ�
};
Clock::Clock(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
	if (hour > 23 || hour<0)hour = 0;
	if (minute > 60 || minute<0)minute = 0;
	if (second > 60 || second<0)second = 0;
}
void Clock::SetAlarm(int h, int m, int s)
{
	Ahour = h;
	Aminute = m;
	Asecond = s;
	if (Ahour > 23)Ahour = 0;
	if (Aminute > 60)Aminute = 0;
	if (Asecond > 60)Asecond = 0;
}
void Clock::run()
{
	second += 1;
	if (second >= 60)
	{
		second = 0;
		minute += 1;
		if (minute >= 60)
		{
			minute = 0;
			hour += 1;
			if (hour > 23)
			{
				hour = 0;
			}
		}
	}
	if(hour == Ahour&&minute == Aminute&&second == Asecond)
	cout <<"Plink!plink!plink!..." << endl;
}


int main()
{
	Clock a(0, 59, 59);
	a.SetAlarm(1, 0, 0);
	a.run();
}

	

/*ʵ�ֹ��캯��Clock(int h, int m, int s)
���캯������ʱ���֡��롣����ǰ���жϴ����ʱ�����Ƿ�Ϸ���������Ϸ���������Ϊ0
���� Clock c(25, 61, -1);
c.ShowTime();
�����
Now : 0 : 0 : 0*/

