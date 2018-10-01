#include <stdio.h>
 #include <windows.h>
#include <graphics.h>
#include <stdlib.h>
 #include <time.h>
#define SCREEN_WIDTH 640
  #define SCREEN_HEIGHT 480
 #define DEF_RAIN_NUM 91  //�������

 //�����꿪ʼ��λ��
 int g_nRainPos[DEF_RAIN_NUM] = { 0 };

 //��������ַ���
 char g_strRain[DEF_RAIN_NUM][10] = { 0 };

 //�������һ����ĸ
 char CreateRandomNum() {
	     char nRandomNum = 0;
	
		   while (1) {
		         nRandomNum = rand() % 123;   //�������0~122��һ���ַ�
		
			       if ((nRandomNum >= 65 && nRandomNum <= 90) || nRandomNum >= 97) {
			             return nRandomNum;
		
		}
		
	}
	
}

 //�������������Ŀ�ʼλ��
 void InitPos() {
	     for (int i = 0; i < DEF_RAIN_NUM; i++) {
		         g_nRainPos[i] = rand() % SCREEN_HEIGHT;
		
	}
	
}

 //��ʼ��������
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
	 settextstyle(32, 0, _T("����"));
	 outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, _T("��ά����"));
	 outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 50, _T("(product by louxin)"));
	 outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 80, _T("1.������Ϸ"));
	 outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 120, _T("2.˫����Ϸ"));
}
 //��ʾ��
 void ShowNumRain() {
	    for (int i = 0; i < DEF_RAIN_NUM; i++) {
		        //����������ɫ
			         settextcolor(RGB(255, 255, 255));  //��ɫ
		       for (int j = 0; j < 10; j++) {
			            outtextxy(i * 15, g_nRainPos[i] - 15 * j, g_strRain[i][j]);
			            settextcolor(RGB(0, 255 - 28 * j, 0));
			
		}
	
	}

		     for (int i = 0; i < DEF_RAIN_NUM; i++) {
		         g_nRainPos[i] += 15;    //��Ļˢ�º����λ���½�15
	
	}
	
		  for (int i = 0; i < DEF_RAIN_NUM; i++) {
		       if (g_nRainPos[i] - 10 * 15 >= SCREEN_HEIGHT) {
			            g_nRainPos[i] = 0;
		
		}
		
	}

}
int main() {
	    srand((unsigned)time(NULL));
	    initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

		    InitPos();
	     InitNumRain();
	
	    BeginBatchDraw();

		     while (1) {
		      InitNumRain();
		        ShowNumRain();
				name();
		       FlushBatchDraw();
		       Sleep(100);   //��ʱ0.1��
	        cleardevice();  //�����Ļ
		
	}

		    EndBatchDraw();
	    closegraph();
	     return 0;
	
}