# define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<iostream>
#include<stdlib.h>
#include "源.h"
using namespace std;
# define high 480
# define width 640
int ball_x, ball_y;
int ball_vx, ball_vy;
int radius;
int bar1_left, bar1_right, bar1_top, bar1_bottom;
int bar2_left, bar2_right, bar2_top, bar2_bottom;
int bar_height, bar_width;
int score = 0;
int ball_x0, ball_y0;
int ball_vx0, ball_vy0;
int radius0;
int bar_left, bar_right, bar_top, bar_bottom;
int bar_height0, bar_width0;
void startup()
{
	ball_x = width / 2;
	ball_y = high / 2;
	ball_vx = 1;
	ball_vy = 1;
	radius = 20;
	bar_width = width / 30;
	bar_height = high / 2;
	bar1_left = width * 1 / 20;
	bar1_top = high / 4;
	bar1_right = bar_width+bar1_left;
	bar1_bottom = bar1_top + bar_height;
	bar2_left = width * 18.5/ 20;
	bar2_top = high / 4;
	bar2_right = bar_width + bar2_left;
	bar2_bottom = bar2_top + bar_height;
	initgraph(width, high);
	BeginBatchDraw();
}
void startup0()
{
	ball_x0 = width / 4;
	ball_y0 = high / 4;
	ball_vx0 = 1;
	ball_vy0 = 1;
	radius0 = 20;
	bar_width0 = width / (2);
	bar_height0 = high / 30;
	bar_left = width * 1 / 20;
	bar_top = high * 18.5 / 20;
	bar_right = bar_left + bar_width0;
	bar_bottom = bar_top - bar_height0;
	initgraph(width, high);
	BeginBatchDraw();
}
void clean()
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball_x, ball_y, radius);
	fillcircle(ball_x, ball_y, radius);
	bar(bar1_left, bar1_top, bar1_right, bar1_bottom);
	bar(bar2_left, bar2_top, bar2_right, bar2_bottom);
}
void clean0()
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball_x0, ball_y0, radius0);
	fillcircle(ball_x0, ball_y0, radius0);
	bar(bar_left, bar_top, bar_right, bar_bottom);
}
void show()
{
	setcolor(GREEN);
	setfillcolor(GREEN);
	fillcircle(ball_x, ball_y, radius);
	setcolor(YELLOW);
	setfillcolor(YELLOW);
	bar(bar1_left, bar1_top, bar1_right, bar1_bottom);
	bar(bar2_left, bar2_top, bar2_right, bar2_bottom);
	FlushBatchDraw();
	Sleep(3);
}
void show0()
{
	setcolor(GREEN);
	setfillcolor(GREEN);
	fillcircle(ball_x0, ball_y0, radius0);
	setcolor(YELLOW);
	setfillcolor(YELLOW);
	bar(bar_left, bar_top, bar_right, bar_bottom);
	FlushBatchDraw();
	Sleep(3);
}
void without0()
{
	char s[60];
	sprintf(s, "your score is:%d", score);
	settextcolor(WHITE);
	settextstyle(32, 0, _T("宋体"));
	outtextxy(width / 2, high * 2 / 3, (s));
	if (ball_y0 + radius0 >= bar_top&&ball_x0 - radius0 >= bar_left&&ball_x0 + radius0 <= bar_right)
	{
		ball_vy0 = -ball_vy0; score++;
	}
	ball_x0 = ball_x0 + ball_vx0;
	ball_y0 = ball_y0 + ball_vy0;
	if ((ball_x0 <= radius0) || (ball_x0 >= width - radius0))
		ball_vx0 = -ball_vx0;
	if ((ball_y0 <= radius0) || (ball_y0 >= high - radius0))
		ball_vy0 = -ball_vy0;
	if ((score + 1) % 10 == 0 && ball_vx0>0 && ball_vy0>0)
	{
		score++;
		ball_vx0 = ball_vx0 + 0.2;
		ball_vy0 = ball_vy0 + 0.2;
	}
	if ((score + 1) % 10 == 0 && ball_vx0<0 && ball_vy0>0)
	{
		score++;
		ball_vx0 = ball_vx0 - 0.2;
		ball_vy0 = ball_vy0 + 0.2;
	}
	if ((score + 1) % 10 == 0 && ball_vx0<0 && ball_vy0<0)
	{
		score++;
		ball_vx0 = ball_vx0 - 0.2;
		ball_vy0 = ball_vy0 - 0.2;
	}
	if ((score + 1) % 10 == 0 && ball_vx0>0 && ball_vy0<0)
	{
		score++;
		ball_vx0 = ball_vx0 + 0.2;
		ball_vy0 = ball_vy0 - 0.2;
	}
	if (ball_y0 + radius0 >= high)
	{
		settextcolor(WHITE);
		settextstyle(32, 0, _T("黑体"));
		outtextxy(width / 2, high / 2, _T("you lose it!!"));
		sprintf(s, "your score is:%d", score);
		settextcolor(WHITE);
		settextstyle(32, 0, _T("宋体"));
		outtextxy(width / 2, high * 2 / 3, (s));
		system("pause");
	}
}
void without()
{

	if (ball_x + radius >= bar2_left&&ball_y + radius >= bar2_top&&ball_y + radius <= bar2_bottom)
		ball_vx = -ball_vx;
	else if (ball_x - radius <= bar1_left&&ball_y + radius >= bar1_top&&ball_y + radius <= bar1_bottom)
		ball_vx = -ball_vx;
	ball_x = ball_x + ball_vx;
	ball_y = ball_y + ball_vy;
	if ((ball_x <= radius) || (ball_x >= width - radius))
		ball_vx = -ball_vx;
	if ((ball_y <= radius) || (ball_y >= high - radius))
		ball_vy = -ball_vy;
	if (ball_x-radius <= 0)
	{
		settextcolor(WHITE);
		settextstyle(32, 0, _T("宋体"));
		outtextxy(width/2,high/2, _T("the right player win!!"));
		system("pause");
	}
	if (ball_x+radius >= width)
	{
		settextcolor(WHITE);
		settextstyle(32, 0, _T("宋体"));
		outtextxy(width / 2, high / 2, _T("the left player win!!"));
		system("pause");
	}
}

void with()
{
	int step = 1;
	if (GetAsyncKeyState(0x57) & 0x8000)
		bar1_top -= step;
	if (GetAsyncKeyState(0x53) & 0x8000)
		bar1_top += step;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		bar2_top -= step;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		bar2_top += step;
	bar1_bottom = bar1_top + bar_height;
	bar2_bottom = bar2_top + bar_height;
}
void with0()
{
	int step0 = 1;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		bar_left -= step0;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		bar_left += step0;
	if (GetAsyncKeyState(65) & 0x8000)
		bar_left -= step0;
	if (GetAsyncKeyState(68) & 0x8000)
		bar_left += step0;
	bar_right = bar_left + bar_width0;
}
void gameover()
{   
	EndBatchDraw();
	closegraph();
}
int main()
{
	int a;
	cin >> a;
	switch (a)
	{
	case'1':
	{
		startup0();
		while (1)
		{
			clean0();
			without0();
			with0();
			show0();
		}
	}
	case'2':
		{
			startup();
			while (1)
			{
				clean();
				without();
				with();
				show();
			}
		}
	}
	gameover();
	return 0;
}