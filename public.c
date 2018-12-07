#include "Team.h"

void cursor() //커서 지우기 함수
{
	CurInfo.bVisible=FALSE;
	CurInfo.dwSize=1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

void textcolor(int color_number) //글자 색 변경 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void gotoxy(int x, int y) //커서 위치 지정 함수
{
	COORD Cur;
	Cur.X=x;
	Cur.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void clear() //화면 깨끗히(gotoxy 함수를 활용하여 깜빡거리지 않도록)
{
	int i, j;

	for(i=2;i<18;i++)
	{
		gotoxy(3, i);
		for(j=0;j<22;j++)
			printf("　");
	}
}