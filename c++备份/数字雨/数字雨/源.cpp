#include <stdio.h>
 #include <windows.h>
#include <graphics.h>
#include <stdlib.h>
 #include <time.h>
#define SCREEN_WIDTH 640
  #define SCREEN_HEIGHT 480
 #define DEF_RAIN_NUM 91  //雨的列数

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
	 outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 50, _T("(product by louxin)"));
	 outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 80, _T("1.单人游戏"));
	 outtextxy(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 + 120, _T("2.双人游戏"));
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
		       Sleep(100);   //延时0.1秒
	        cleardevice();  //清空屏幕
		
	}

		    EndBatchDraw();
	    closegraph();
	     return 0;
	
}