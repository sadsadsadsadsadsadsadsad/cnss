#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
using namespace std;
int high, width;
int bird_x, bird_y;
int bar_xdown, bar_y, bar_xtop;
int score;
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void startup()
{
	high = 30;
	width = 50;
	bird_x = high / 2;
	bird_y = 15;
	bar_y = width / 2;
	bar_xdown = high / 3;
	bar_xtop = high / 2;
	score = 0;
}
void show()
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i<high; i++)
	{
		for (j = 0; j<width; j++)
		{
			if ((i == bird_x) && (j == bird_y))
				printf("Äñ");
			else if ((j == bar_y) && (i<bar_xdown || i>bar_xtop))
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	cout << "your score is:" << score;
}
void m()
{
	bird_x++;
	bar_y--;
	if (bird_y == bar_y)
	{
		if ((bird_x >= bar_xdown) && (bird_x <= bar_xtop))
		{
			score++;
		}
		else
		{
			cout << "gaem over" << endl;
			printf("\a");
			system("pause");
			exit(0);
		}
	}
	if (bar_y == 0)

	{

		bar_y = width;
		int t = rand() % int(high*0.8);
		bar_xdown = t - high / 10;
		bar_xtop = t + high / 10;
	}
	Sleep(150);

}

void doit()
{
	char input;
	if(_kbhit())  
	{
		input = _getch();
		if (input == ' ')
			bird_x = bird_x - 2;
	}
}

int main()
{

	startup();
	while (1)
	{
		show();
		m();
		doit();
	}
	system("pause");
	//MessageBox(NULL,TEXT("Hello world"), TEXT("Hello world"), 0);
	return 0;
}
