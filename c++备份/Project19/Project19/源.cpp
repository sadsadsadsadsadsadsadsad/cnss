#include"stdafx.h"
#include <graphics.h>
#include <conio.h>
#define NSIZE 10//����ÿ���ߵ�С����������
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
void colorcell(int x, int y, COLORREF color, int size) {//3DС����
	int s = size / 10;
	setfillcolor(color);//������ɫ
	bar(x + s, y + s, x + size - s, y + size - s);
	setcolor(color + 50);
	for (int a = 0; a<5; a++) {//����������ǳɫ�п������
		line(x + a, y, x + a, y + 50 - a);
		line(x, y + a, x + 50 - a, y + a);
	}//for
	setcolor(color - 50);
	for (int a = 0; a<5; a++) {//������������ɫ�п������
		line(x + 50, y + 50 - a, x + a, y + 50 - a);
		line(x + 50 - a, y + a, x + 50 - a, y + 50);
	}//for
}//colorcell
void welcome()
{// ��ʼ������
	initgraph(600, 600);//���ô��ڴ�С
	setorigin(50, 50);//��������ԭ��
	cleardevice();//�����Ļ
				  // ��ӭ����
	settextcolor(RGB(0, 255, 0));//�����ַ���ɫ
	setfont(64, 0, _T("����"));//�����ַ���С�����ۺ�����
	outtextxy(100, 50, _T("Ϳ������Ϸ"));//ֱ������ַ���
	outtextxy(150, 130, _T("(���)"));
	settextcolor(WHITE);
	setfont(16, 0, _T("����"));
	outtextxy(50, 280, _T("ÿ����һ�����ӣ��������ҵĸ���Ҳ����������ɫ"));
	outtextxy(50, 260, _T("��Ϸ˵�����ܹ�5�أ�ȫ��ɫͨ�أ��Ҽ��������м��˳�"));
	outtextxy(350, 350, _T("�����ˣ��μ�ص���"));
	setfont(16, 0, _T("����"));
	outtextxy(350, 390, _T("Ver 1"));
	// ʵ����˸��"�����������"
	int co = 255;
	while (!kbhit()) {
		co -= 8;
		if (co<0) co = 255;
		settextcolor(RGB(co, 255 - co, co));
		outtextxy(215, 450, _T("�����������"));
		Sleep(20);//��ʱ0.02��
	}//while
	getch();//�����������
	cleardevice();
}//welcome
void level(int s) {//�ؿ�
	MOUSEMSG m;//�����Ϣ����
	int flag[NSIZE][NSIZE];//ֵΪ0��1
	int x, y;//�����ڼ����������ڼ������ӣ�����
	int lu = (10 - 2 * s) / 2, rd = (10 + 2 * s) / 2;//����Ҫ��ʾ�ĸ���������lu���ϱ߾࣬rd���±߾�
	TCHAR c1[2], c2[5];//c1��Źؿ���c2��Ų������轫���ʹ����ַ����ͱ�����
	COLORREF color[2] = { RED,LIGHTGREEN };//��ɫ��������
										   //��ʼ����
loop://gotoѭ��ͷ
	int num = 0;//��������
				//���Ƿ�ͨ�ر�־
	settextcolor(WHITE);
	setfont(25, 0, _T("����"));
	outtextxy(183, -35, _T("�� ��"));
	_stprintf(c1, _T("%d"), s); outtextxy(225, -35, c1);// ����ַ�������
	outtextxy(400, 508, _T("��"));
	outtextxy(480, 508, _T("��"));
	for (int i = lu; i<rd; i++) {//���ƹؿ���ʼ״̬
		for (int j = lu; j<rd; j++) {
			flag[i][j] = 0;//����ɫ�������鸳��ֵ0,color[0]Ϊ��ɫ
			colorcell(i * 50, j * 50, color[flag[i][j]], 50);//ȫ��С����Ϊ��ɫ
		}//for
	}//for
	 //���ϻ�ȡ�����Ϣ
	while (1) {
		int lable = 1;
		m = GetMouseMsg();//��ȡһ�������Ϣ
		if (m.uMsg == WM_LBUTTONDOWN) {//��Ϊ����
			x = m.x / 50; y = m.y / 50;//��ȡ����С�������
			x--; y--;//�����������������1
			if (x<lu || x >= rd || y<lu || y >= rd) {
				if (x == -1 && y == -1) {//����:������Ͻ�
					for (int i = lu; i<rd; i++) {//ȫ������ˢ����ɫ
						for (int j = lu; j<rd; j++) {
							colorcell(i * 50, j * 50, color[1], 50);
						}//for
					}//for
					break;//ǿ��ͨ�أ��˳�while ��ɵ�ǰlevel
				}//if
				else continue;//�����ǲ������������»�ȡ�����Ϣ
			}//if
			flag[x][y] = (flag[x][y] + 1) % 2;//����С���Ӷ�Ӧ����ɫ����0-1��1-0����
			colorcell(x * 50, y * 50, color[flag[x][y]], 50);//��䵱ǰС������һ����ɫ
			num++;//������1
			settextcolor(LIGHTGREEN);// ��ʾ����
			_stprintf(c2, _T("%d"), num);
			outtextxy(433, 508, c2);
			if (y + 1<rd) { //���������������С����
				flag[x][y + 1] = (flag[x][y + 1] + 1) % 2;
				colorcell(x * 50, (y + 1) * 50, color[flag[x][y + 1]], 50);
			}
			if (y - 1 >= lu) {//���������������С����
				flag[x][y - 1] = (flag[x][y - 1] + 1) % 2;
				colorcell(x * 50, (y - 1) * 50, color[flag[x][y - 1]], 50);
			}
			if (x + 1<rd) {//���������������С����
				flag[x + 1][y] = (flag[x + 1][y] + 1) % 2;
				colorcell((x + 1) * 50, y * 50, color[flag[x + 1][y]], 50);
			}
			if (x - 1 >= lu) {//���������������С����
				flag[x - 1][y] = (flag[x - 1][y] + 1) % 2;
				colorcell((x - 1) * 50, y * 50, color[flag[x - 1][y]], 50);
			}
		}//if����
		if (m.uMsg == WM_RBUTTONDOWN) {//��Ϊ�һ�
			cleardevice();
			goto loop;//ˢ�£�����loop
		}//if�һ�
		 //���Ƿ�ͨ��
		for (int i = lu; i<rd; i++) {
			for (int j = lu; j<rd; j++)
				if (flag[i][j] == 0) lable = 0;//�к����
		}//for
		if (lable) break;//ͨ���˳�whileѭ��
	}//while
}//level
void byebye() {
	int co = 255;
	cleardevice();
	while (!kbhit()) {
		settextcolor(RGB(co, 255 - 0, 0));
		setfont(64, 0, _T("����"));
		outtextxy(100, 200, _T("��ϲͨ�أ�"));
		co = (co + 10) % 256;
		Sleep(20);//��ʱ0.02��
	}//while
}//byebye
void main()
{
	welcome();//����/��ӭ���棬��Ϸ˵��
			  //��ز���
	for (int s = 1; s<6; s++) {//����5��
		level(s);//���ùؿ�
		outtextxy(0, 508, _T("��ϲ���أ��������������һ��"));
		getch();
		cleardevice();
	}//for
	byebye();
	closegraph();//�ر���Ļ
}