#include"stdafx.h"
#include <graphics.h>
#include <conio.h>
#define NSIZE 10//定义每条边的小格子最大个数
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
void colorcell(int x, int y, COLORREF color, int size) {//3D小方块
	int s = size / 10;
	setfillcolor(color);//画背景色
	bar(x + s, y + s, x + size - s, y + size - s);
	setcolor(color + 50);
	for (int a = 0; a<5; a++) {//画左上两条浅色有宽度线条
		line(x + a, y, x + a, y + 50 - a);
		line(x, y + a, x + 50 - a, y + a);
	}//for
	setcolor(color - 50);
	for (int a = 0; a<5; a++) {//画右下两条深色有宽度线条
		line(x + 50, y + 50 - a, x + a, y + 50 - a);
		line(x + 50 - a, y + a, x + 50 - a, y + 50);
	}//for
}//colorcell
void welcome()
{// 初始化窗口
	initgraph(600, 600);//设置窗口大小
	setorigin(50, 50);//设置坐标原点
	cleardevice();//清空屏幕
				  // 欢迎界面
	settextcolor(RGB(0, 255, 0));//设置字符颜色
	setfont(64, 0, _T("黑体"));//设置字符大小，减价和字体
	outtextxy(100, 50, _T("涂格子游戏"));//直接输出字符串
	outtextxy(150, 130, _T("(点灯)"));
	settextcolor(WHITE);
	setfont(16, 0, _T("宋体"));
	outtextxy(50, 280, _T("每单击一个格子，上下左右的格子也会变另外的颜色"));
	outtextxy(50, 260, _T("游戏说明：总共5关，全绿色通关，右键重来，中键退出"));
	outtextxy(350, 350, _T("制作人：盐碱地的羊"));
	setfont(16, 0, _T("黑体"));
	outtextxy(350, 390, _T("Ver 1"));
	// 实现闪烁的"按任意键继续"
	int co = 255;
	while (!kbhit()) {
		co -= 8;
		if (co<0) co = 255;
		settextcolor(RGB(co, 255 - co, co));
		outtextxy(215, 450, _T("按任意键继续"));
		Sleep(20);//延时0.02秒
	}//while
	getch();//按任意键继续
	cleardevice();
}//welcome
void level(int s) {//关卡
	MOUSEMSG m;//鼠标信息类型
	int flag[NSIZE][NSIZE];//值为0或1
	int x, y;//横数第几个，纵数第几个格子；步数
	int lu = (10 - 2 * s) / 2, rd = (10 + 2 * s) / 2;//设置要显示的格子数量，lu左上边距，rd右下边距
	TCHAR c1[2], c2[5];//c1存放关卡，c2存放步数，需将整型存在字符串型变量中
	COLORREF color[2] = { RED,LIGHTGREEN };//颜色类型数组
										   //初始界面
loop://goto循环头
	int num = 0;//步数清零
				//判是否通关标志
	settextcolor(WHITE);
	setfont(25, 0, _T("黑体"));
	outtextxy(183, -35, _T("第 关"));
	_stprintf(c1, _T("%d"), s); outtextxy(225, -35, c1);// 输出字符串变量
	outtextxy(400, 508, _T("共"));
	outtextxy(480, 508, _T("步"));
	for (int i = lu; i<rd; i++) {//绘制关卡初始状态
		for (int j = lu; j<rd; j++) {
			flag[i][j] = 0;//将颜色代码数组赋初值0,color[0]为红色
			colorcell(i * 50, j * 50, color[flag[i][j]], 50);//全部小格子为红色
		}//for
	}//for
	 //不断获取鼠标信息
	while (1) {
		int lable = 1;
		m = GetMouseMsg();//获取一个鼠标信息
		if (m.uMsg == WM_LBUTTONDOWN) {//若为单击
			x = m.x / 50; y = m.y / 50;//获取单击小格子序号
			x--; y--;//因重置坐标中心需减1
			if (x<lu || x >= rd || y<lu || y >= rd) {
				if (x == -1 && y == -1) {//作弊:点击左上角
					for (int i = lu; i<rd; i++) {//全部格子刷成绿色
						for (int j = lu; j<rd; j++) {
							colorcell(i * 50, j * 50, color[1], 50);
						}//for
					}//for
					break;//强制通关，退出while 完成当前level
				}//if
				else continue;//单击非操作区域则重新获取鼠标信息
			}//if
			flag[x][y] = (flag[x][y] + 1) % 2;//单击小格子对应的颜色编码0-1，1-0互换
			colorcell(x * 50, y * 50, color[flag[x][y]], 50);//填充当前小格子另一种颜色
			num++;//步数加1
			settextcolor(LIGHTGREEN);// 显示步数
			_stprintf(c2, _T("%d"), num);
			outtextxy(433, 508, c2);
			if (y + 1<rd) { //操作区域内填充下小格子
				flag[x][y + 1] = (flag[x][y + 1] + 1) % 2;
				colorcell(x * 50, (y + 1) * 50, color[flag[x][y + 1]], 50);
			}
			if (y - 1 >= lu) {//操作区域内填充上小格子
				flag[x][y - 1] = (flag[x][y - 1] + 1) % 2;
				colorcell(x * 50, (y - 1) * 50, color[flag[x][y - 1]], 50);
			}
			if (x + 1<rd) {//操作区域内填充右小格子
				flag[x + 1][y] = (flag[x + 1][y] + 1) % 2;
				colorcell((x + 1) * 50, y * 50, color[flag[x + 1][y]], 50);
			}
			if (x - 1 >= lu) {//操作区域内填充左小格子
				flag[x - 1][y] = (flag[x - 1][y] + 1) % 2;
				colorcell((x - 1) * 50, y * 50, color[flag[x - 1][y]], 50);
			}
		}//if单击
		if (m.uMsg == WM_RBUTTONDOWN) {//若为右击
			cleardevice();
			goto loop;//刷新，返回loop
		}//if右击
		 //判是否通关
		for (int i = lu; i<rd; i++) {
			for (int j = lu; j<rd; j++)
				if (flag[i][j] == 0) lable = 0;//有红格子
		}//for
		if (lable) break;//通关退出while循环
	}//while
}//level
void byebye() {
	int co = 255;
	cleardevice();
	while (!kbhit()) {
		settextcolor(RGB(co, 255 - 0, 0));
		setfont(64, 0, _T("黑体"));
		outtextxy(100, 200, _T("恭喜通关！"));
		co = (co + 10) % 256;
		Sleep(20);//延时0.02秒
	}//while
}//byebye
void main()
{
	welcome();//调用/欢迎界面，游戏说明
			  //逐关操作
	for (int s = 1; s<6; s++) {//设置5关
		level(s);//调用关卡
		outtextxy(0, 508, _T("恭喜过关，按任意键进行下一关"));
		getch();
		cleardevice();
	}//for
	byebye();
	closegraph();//关闭屏幕
}