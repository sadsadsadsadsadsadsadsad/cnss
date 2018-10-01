/*实现时钟类Clock, (24小时制，0~23)
在代码中引入头文件 Clock.h
它的定义如下：*/
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
	int hour;   //时
	int minute;  //分
	int second;  //秒

	int Ahour;   //时（闹钟）
	int Aminute;  //分（闹钟）
	int Asecond;   //秒（闹钟）
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

	

/*实现构造函数Clock(int h, int m, int s)
构造函数设置时、分、秒。设置前先判断传入的时分秒是否合法，如果不合法将其设置为0
例如 Clock c(25, 61, -1);
c.ShowTime();
输出：
Now : 0 : 0 : 0*/

