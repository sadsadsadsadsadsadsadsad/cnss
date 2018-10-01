#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<Windows.h>
#pragma comment(lib,"Winmm.lib")
# define high 864
# define width 591
IMAGE img_bk;
float position_x, position_y;
float bullet_x, bullet_y;
float enemy_x, enemy_y;
IMAGE img_np, img_exp, img_b, img_ep;
int isexpolde = 0;
int score = 0;
void startup()
{
	initgraph(width, high);
	loadimage(&img_bk, L"D:\\bk.jpg", 1000, 1000);
	loadimage(&img_np, L"D:\\nplane.jpg", 100, 100);
	loadimage(&img_exp, L"D:\\eplane.jpg", 100, 100);
	loadimage(&img_b, L"D:\\bullet.jpg", 50, 50);
	loadimage(&img_ep, L"D:\\enemyplane", 100, 100);
	position_x = width*0.5;
	position_y = high*0.7;
	bullet_x = position_x;
	bullet_y = -200;
	enemy_x = 100;
	enemy_y = -10;
	BeginBatchDraw();
}
void show()
{
	putimage(0, 0, &img_bk);
	if (isexpolde == 0)
	{
		putimage(position_x - 50, position_y - 60, &img_np);

		putimage(enemy_x, enemy_y, &img_ep);
	}
	else
	{
		putimage(position_x - 50, position_y - 60, &img_exp);
	}
	outtextxy((864*0.48), (591*0.95), _T("your score is:"));
	FlushBatchDraw();
	Sleep(2);
}
void updatewithoutinput()
{
	if (isexpolde == 0)
	{
		if (bullet_y > -25)
			bullet_y = bullet_y - 2;
		if (enemy_y < high - 25)
			enemy_y = enemy_y + 0.5;
		else
		{
			enemy_y = 10;
		}
		if (abs(bullet_x - enemy_x) + abs(bullet_y - enemy_y) < 80);
		{
			enemy_x = rand() % width;
			enemy_y = 40;
			bullet_y = -85;
		}
		if (abs(position_x - enemy_x) + abs(position_y - enemy_y) < 50)
			isexpolde = 1;
	}
}
void updatewithinput()
{
	MOUSEMSG m;
	while (MouseHit())
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE)
		{
			position_x = m.x;
			position_y = m.y;
		}
		else if (m.uMsg == WM_LBUTTONDOWN)
		{
			putimage(bullet_x - 7, bullet_y, &img_b);
			bullet_x = position_x;
			bullet_y = position_y-85;
		}
	}
}
void gameover()
{
	EndBatchDraw();
	_getch();
	closegraph();
}
int main()
{
	startup();
	while (1)
	{
		show();
		updatewithoutinput();
		updatewithinput();
	}
	gameover();
	return 0;
}
