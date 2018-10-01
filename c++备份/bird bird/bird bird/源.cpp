#include<iostream>
#include<graphics.h>
#include<conio.h>
IMAGE img_bk, img_bd1, img_up1, img_down1;
int bird_y;
int bird_x;
void startup()
{
	initgraph(700, 600);
	loadimage(&img_bk, "D:\\background.jpg");
	loadimage(&img_bd1, "D:\\bird.jpg ");
	loadimage(&img_up1, "D:\\up.jpg");
	loadimage(&img_down1, "D:\\down.jpg");
	bird_x = 50;
	bird_y = 200;
	BeginBatchDraw();
}
void show()
{
	putimage(0, 0, &img_bk);
	putimage(150, 100, &img_up1);
	putimage(150, 200, &img_down1);
	putimage(bird_x, bird_y, &img_bd1);
	FlushBatchDraw();
	Sleep(50);
}
int main()
{
	startup();
	show();
	system("pause");
	return 0;
}
