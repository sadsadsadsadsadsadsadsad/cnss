#include <graphics.h>
#include <conio.h>
// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

void main()         
{
	initgraph(640, 480);

	// 打开音乐
	mciSendString("open E:\\666.mp3 alias mymusic", NULL, 0, NULL);

	outtextxy(0, 0, "按任意键开始播放");
	_getch();

	// 播放音乐
	mciSendString("play mymusic", NULL, 0, NULL);

	outtextxy(0, 0, "按任意键停止播放");
	_getch();

	// 停止播放并关闭音乐
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);

	outtextxy(0, 0, "按任意键退出程序");
	_getch();
	closegraph();
}