#include <graphics.h>
#include <conio.h>
// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

void main()         
{
	initgraph(640, 480);

	// ������
	mciSendString("open E:\\666.mp3 alias mymusic", NULL, 0, NULL);

	outtextxy(0, 0, "���������ʼ����");
	_getch();

	// ��������
	mciSendString("play mymusic", NULL, 0, NULL);

	outtextxy(0, 0, "�������ֹͣ����");
	_getch();

	// ֹͣ���Ų��ر�����
	mciSendString("stop mymusic", NULL, 0, NULL);
	mciSendString("close mymusic", NULL, 0, NULL);

	outtextxy(0, 0, "��������˳�����");
	_getch();
	closegraph();
}