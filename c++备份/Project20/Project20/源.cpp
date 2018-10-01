#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<iostream>
# include <fstream>
#include<stdlib.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;
#define high 480
#define width 640
#define brick_num 10
char e;
int d=0;
int c=0 ;
int b = 0;
int a=0;
int score=0;
int ball_x0, ball_y0;
float ball_vx0, ball_vy0;
int radius0;
int bar_left, bar_right, bar_top, bar_bottom;
int bar_height0, bar_width0;
int ball_x, ball_y;
int ball_vx, ball_vy;
int radius;
int bar1_left, bar1_right, bar1_top, bar1_bottom;
int bar2_left, bar2_right, bar2_top, bar2_bottom;
int bar_height, bar_width;
int isbrickexisted[brick_num];
int brick_high, brick_width;
ifstream fin; //fin 是从文档中读出内容
ofstream fout;
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define DEF_RAIN_NUM 91  //雨的列数
void gave()
{
	ofstream fout("score.txt");
	fout << score<< ball_x0<< ball_y0<<ball_vx0<< ball_vy0<<bar_left<< bar_right<< bar_top<<bar_bottom;
	fout.close();
	
}
void in()
{
	ifstream fin("score.txt");
	fin >> score >>ball_x0 >> ball_y0 >> ball_vx0 >> ball_vy0 >> bar_left >> bar_right >> bar_top >> bar_bottom;;
	fin.close();
}

void readRecordFile()
{
	FILE*fp; errno_t err; 
	err = fopen_s(&fp, "sss.txt", "r+");
	fscanf_s(fp, "%d %d %d %f %f %d %d %d %d %d %d",
		score,
		ball_x0, ball_y0,
		ball_vx0, ball_vy0,
		bar_left, bar_right, bar_top, bar_bottom,
		bar_height0, bar_width0);
	fclose(fp);
	return;
}
void writeRecordFile()
{
	FILE*fp;
	errno_t err;
	err = fopen_s(&fp, "sss.txt", "r+");
	fprintf(fp, "%d %d %d %f %f %d %d %d %d %d %d",
		score,
		ball_x0, ball_y0,
		ball_vx0, ball_vy0,
		bar_left, bar_right, bar_top, bar_bottom,
		bar_height0, bar_width0);
	fclose(fp);
	return;
}
//数字雨开始的位置
int g_nRainPos[DEF_RAIN_NUM] = { 0 };

//数字雨的字符串
char g_strRain[DEF_RAIN_NUM][10] = { 0 };

//随机产生一个字母
char CreateRandomNum() {
	char nRandomNum = 0;

	while (1) {
		nRandomNum = rand() % 123;   //随机产生0~122的一个字符

		if ((nRandomNum >= 65 && nRandomNum <= 90) || nRandomNum >= 97) {
			return nRandomNum;

		}

	}

}

//随机产生数字雨的开始位置
void InitPos() {
	for (int i = 0; i < DEF_RAIN_NUM; i++) {
		g_nRainPos[i] = rand() % SCREEN_HEIGHT;

	}

}

//初始化数字雨
void InitNumRain() {
	for (int i = 0; i < DEF_RAIN_NUM; i++) {
		for (int j = 0; j < 10; j++) {
			g_strRain[i][j] = CreateRandomNum();

		}

	}

}
void name()
{
	settextcolor(WHITE);
	settextstyle(32, 0, _T("宋体"));
	outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, _T("二维弹球"));
	outtextxy(100, SCREEN_HEIGHT / 3 + 40, _T("(product by louxin2017060901014)"));
	outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 80, _T("1.单人游戏"));
	outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 120, _T("2.双人游戏"));
	outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 160, _T("3.退出游戏"));
	settextcolor(WHITE);
	settextstyle(20, 0, _T("宋体"));
	outtextxy(150, SCREEN_HEIGHT / 3 + 200, _T("all rights reserved@louxin mark2018"));
	outtextxy(150, SCREEN_HEIGHT / 3 + 240, _T("鸣谢：戴波，龚科，李昕阳"));
}
//显示雨
void ShowNumRain() {
	for (int i = 0; i < DEF_RAIN_NUM; i++) {
		//设置字体颜色
		settextcolor(RGB(255, 255, 255));  //白色
		for (int j = 0; j < 10; j++) {
			outtextxy(i * 15, g_nRainPos[i] - 15 * j, g_strRain[i][j]);
			settextcolor(RGB(0, 255 - 28 * j, 0));

		}

	}

	for (int i = 0; i < DEF_RAIN_NUM; i++) {
		g_nRainPos[i] += 15;    //屏幕刷新后雨的位置下降15

	}

	for (int i = 0; i < DEF_RAIN_NUM; i++) {
		if (g_nRainPos[i] - 10 * 15 >= SCREEN_HEIGHT) {
			g_nRainPos[i] = 0;

		}

	}

}
void ashow()
{
	settextcolor(WHITE);
	settextstyle(32, 0, _T("宋体"));
	outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, _T("1.新游戏"));
	outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3+40, _T("2.读取存档"));
	outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 80, _T("3.退出"));
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
	bar_top = high * 18.5/20;
	bar_right = bar_left + bar_width0;
	bar_bottom = bar_top - bar_height0;
	brick_width = width / brick_num;
	brick_high = high / brick_num;
	int i;
	for (i = 0; i < brick_num; i++)
		isbrickexisted[i] = 1;
	initgraph(width, high);
	BeginBatchDraw();
}
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
	bar1_right = bar_width + bar1_left;
	bar1_bottom = bar1_top + bar_height;
	bar2_left = width * 18.5 / 20;
	bar2_top = high / 4;
	bar2_right = bar_width + bar2_left;
	bar2_bottom = bar2_top + bar_height;
	initgraph(width, high);
	BeginBatchDraw();
}
void clean0()
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball_x0, ball_y0, radius0);
	fillcircle(ball_x0, ball_y0, radius0);
	bar(bar_left, bar_top, bar_right, bar_bottom);
	int i, brick_left, brick_right, brick_top, brick_bottom;
	for (i = 0; i < brick_num; i++)
	{
		brick_left = i*brick_width;
		brick_right = brick_left + brick_width;
		brick_top = 0;
		brick_bottom = brick_high;
		if (!isbrickexisted[i])
			fillrectangle(brick_left, brick_top, brick_right, brick_bottom);
	}
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
void show0()
{
	setcolor(GREEN);
	setfillcolor(GREEN);
	fillcircle(ball_x0, ball_y0, radius0);
	setcolor(YELLOW);
	setfillcolor(YELLOW);
	bar(bar_left, bar_top, bar_right, bar_bottom);
	int i, brick_left, brick_right, brick_top, brick_bottom;
	for (i = 0; i < brick_num; i++)
	{
		brick_left = i*brick_width;
		brick_right = brick_left + brick_width;
		brick_top = 0;
		brick_bottom = brick_high+ brick_top;
		if ((score + 1) % 11 == 0)
		{
			score++;
			for (int j = 0; j < brick_num; j++)
				isbrickexisted[j] = 1;
			brick_top+=brick_high;
		}
		if (isbrickexisted[i])
		{
			setcolor(WHITE);
			setfillcolor(RED);
			fillrectangle(brick_left, brick_top, brick_right, brick_bottom);
		}
	}
	FlushBatchDraw();
	Sleep(3);
}
void show()
{
	setcolor(GREEN);
	setfillcolor(GREEN);
	fillcircle(ball_x, ball_y, radius);
	setcolor(YELLOW);
	setfillcolor(YELLOW);
	bar(bar1_left, bar1_top, bar1_right, bar1_bottom);
	setcolor(BLUE);
	setfillcolor(BLUE);
	bar(bar2_left, bar2_top, bar2_right, bar2_bottom);
	FlushBatchDraw();
	Sleep(3);
}
void without0()
{
	char s[60];
	sprintf_s(s, "your score is:%d", score);
	settextcolor(WHITE);
	settextstyle(32, 0, _T("宋体"));
	outtextxy(width / 2, high * 2 / 3, (s));
	if (ball_y0 + radius0 >= bar_top&&ball_x0 - radius0 >= bar_left&&ball_x0 + radius0 <= bar_right)
	{
		ball_vy0 = -ball_vy0; 
	}
	ball_x0 = ball_x0 + ball_vx0;
	ball_y0 = ball_y0 + ball_vy0;
	if ((ball_x0 <= radius0) || (ball_x0 >= width - radius0))
		ball_vx0 = -ball_vx0;
	if ((ball_y0 <= radius0) || (ball_y0 >= high - radius0))
		ball_vy0 = -ball_vy0;
	int i, brick_left, brick_right, brick_top, brick_bottom;
	for (i = 0; i < brick_num; i++)
	{
		if (isbrickexisted[i])
		{
			brick_left = i*brick_width;
			brick_right = brick_left + brick_width;
			brick_bottom = brick_high;
			if ((ball_y0 == brick_bottom + radius) && (ball_x0 >= brick_left) && (ball_x0 <= brick_right))
			{
				isbrickexisted[i] = 0;
				ball_vy0 = -ball_vy0;
				score++; printf("\a");
			}
		}
	}
	if (score == 100)
	{
		ball_vx0 = 1.5;
		ball_vy0 = -1.5;
	}
	if (score == 200)
	{
		ball_vx0 = 2.0;
		ball_vy0 = -2.0;
	}

	if (ball_y0 + radius0 >= high)
	{
		settextcolor(WHITE);
		settextstyle(32, 0, _T("宋体"));
		outtextxy(width / 2, high / 2, _T("Game over!!"));
		sprintf_s(s, "your score is:%d", score);
		settextcolor(WHITE);
		settextstyle(32, 0, _T("宋体"));
		outtextxy(width / 2, high * 2 / 3, (s));
		system("pause"); printf("\a");  HWND wnd = GetHWnd();
		if (MessageBox(wnd, _T("您要退出游戏吗？"), _T("提醒"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
			closegraph();
		exit(0);
	}
}

void without()
{
	char k[60];
	sprintf_s(k, "the left player's score is:%d", d);
	settextcolor(WHITE);
	settextstyle(16, 0, _T("宋体"));
	outtextxy(width / 2-100, high  / 3, (k));
	char h[60];
	sprintf_s(h, "the right player's score is:%d", c);
	settextcolor(WHITE);
	settextstyle(16, 0, _T("宋体"));
	outtextxy(width / 2-100, high / 3+40, (h));
	if (ball_x + radius >= bar2_left&&ball_y + radius >= bar2_top&&ball_y + radius <= bar2_bottom)
		ball_vx = -ball_vx;
	else if (ball_x - radius <= bar1_right&&ball_y + radius >= bar1_top&&ball_y + radius <= bar1_bottom)
		ball_vx = -ball_vx;
	ball_x = ball_x + ball_vx;
	ball_y = ball_y + ball_vy;
	if ((ball_x <= radius) || (ball_x >= width - radius))
		ball_vx = -ball_vx;
	if ((ball_y <= radius) || (ball_y >= high - radius))
		ball_vy = -ball_vy;
	if (ball_x - radius <= 0)
	{
		settextcolor(WHITE);
		settextstyle(32, 0, _T("宋体"));
		outtextxy(width / 2, high / 2, _T("the right player win!!"));
		system("pause");  printf("\a");  c++;
		if((c+1)%11==0||(d+1)%11==0)
		{
			HWND wnd = GetHWnd();
			if (MessageBox(wnd, _T("您要退出游戏吗？"), _T("提醒"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
				closegraph();
			exit(0);
		}
	}
	if (ball_x + radius >= width)
	{
		settextcolor(WHITE);
		settextstyle(32, 0, _T("宋体"));
		outtextxy(width / 2, high / 2, _T("the left player win!!"));
		system("pause");  printf("\a");  d++;
		if ((c+1) % 11 == 0 || (d+1) % 11 == 0)
		{
			HWND wnd = GetHWnd();
			if (MessageBox(wnd, _T("您要退出游戏吗？"), _T("提醒"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
				closegraph();
			exit(0);
		}
	}
}
void with0()
{
	int step0 = 1;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		bar_left -= step0;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		bar_left += step0;
	if(GetAsyncKeyState(65)&0x8000)
		bar_left -= step0;
	if (GetAsyncKeyState(68) & 0x8000)
		bar_left += step0;
	if (GetAsyncKeyState(0x57) & 0x8000)
		bar_top -= step0;
	if (GetAsyncKeyState(0x53) & 0x8000)
		bar_top += step0;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		bar_top -= step0;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		bar_top += step0;
	bar_right = bar_left + bar_width0;
	bar_bottom = bar_top + bar_height0;
}
void with()
{
	int step = 1;
	if ((GetAsyncKeyState(0x57) & 0x8000)&&(bar1_top>=0))
		bar1_top -= step;
	if ((GetAsyncKeyState(0x53) & 0x8000)&& (bar1_bottom <= high))
		bar1_top += step;
	if ((GetAsyncKeyState(VK_UP) & 0x8000)&& (bar2_top >= 0))
		bar2_top -= step;
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000)&& (bar2_bottom <= high))
		bar2_top += step;
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (bar2_left >= 0))
		bar2_left -= step;
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)&&(bar2_right<=width))
		bar2_left += step;
	if ((GetAsyncKeyState(65) & 0x8000)&&(bar1_left >= 0))
		bar1_left -= step;
	if ((GetAsyncKeyState(68) & 0x8000)&& (bar1_right <= width))
		bar1_left += step;
	bar1_right = bar1_left + bar_width;
	bar2_right = bar2_left + bar_width;
	bar1_bottom = bar1_top + bar_height;
	bar2_bottom = bar2_top + bar_height;
}
void special()
{
	mciSendString(_T("open background.mp3 alias mymusic"), NULL, 0, NULL);

	
	// 播放音乐
	mciSendString(_T("play mymusic"), NULL, 0, NULL);

	srand((unsigned)time(NULL));
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	InitPos();
	InitNumRain();
	BeginBatchDraw();
	while(a==0)
	{
		InitNumRain();
		ShowNumRain();
		name();
		FlushBatchDraw();
		Sleep(100);
		//延时0.1秒
		cleardevice();  //清空屏幕
		if (_kbhit())
		{
			cin >> a;
		}
	} 
	
	EndBatchDraw();
	closegraph();
}
void other()
{
	srand((unsigned)time(NULL));
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	InitPos();
	InitNumRain();
	BeginBatchDraw();
	while (b==0)
	{
		InitNumRain();
		ShowNumRain();
		ashow();
		FlushBatchDraw();
		Sleep(100);
		//延时0.1秒
		cleardevice();  //清空屏幕
		if (_kbhit())
		{
			cin >> b;
		}
	}

	EndBatchDraw();
	closegraph();
}

void newgame()
{
	special();


	if (a == 1)
	{
		other();
		if (b == 1)
		{
			startup0();
			while (1)
			{
				clean0();
				without0();
				with0();
				show0();
				in();
			}
		}
		if (b == 2)
		{
			startup0();
			gave();
			while (1)
			{
				clean0();
				without0();
				with0();
				show0();
				in();
				
			}
		}
		if (b == 3)
		{
			exit(0);
		}
	}
	if (a == 2)
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
	if (a == 3)
	{
		exit(0);
	}
}


int main()
{
	
	newgame();
	
	
	return 0;
}