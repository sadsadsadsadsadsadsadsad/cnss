#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"acllib.h"
typedef struct myImages
{
	char name[50];
	ACL_Image img;
	//	int nx, ny, nwidth, nheight;
}myImages;
typedef struct imgPos
{
	int nx, ny, nwidth, nheight;
	int npos;
}imgPos;
const int winWidth = 300, winHeight = 300;
const int NUM = 4, row = 3, col = 3;
myImages imgs[NUM] = { { "1-bird.jpg" },{ "1-cat.jpg" },{ "1-dog.jpg" },{ "1-rabbit.jpg" } };
imgPos imgsPos[row][col];
int Setup()
{
	initWindow("load Image", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	for (int i = 0; i < NUM; ++i)
	{
		loadImage(imgs[i].name, &imgs[i].img);
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			imgsPos[i][j].nx = i * 100;
			imgsPos[i][j].ny = j * 100;
			imgsPos[i][j].nwidth = 100;
			imgsPos[i][j].nheight = 100;
			imgsPos[i][j].npos = rand() % 4;

		}
	beginPaint();
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			putImageScale(&imgs[imgsPos[i][j].npos].img, imgsPos[i][j].nx, imgsPos[i][j].ny, imgsPos[i][j].nwidth, imgsPos[i][j].nheight);
		}
	endPaint();

	return 0;
}
