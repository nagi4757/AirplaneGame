#include "Team.h"

void cursor() //Ŀ�� ����� �Լ�
{
	CurInfo.bVisible=FALSE;
	CurInfo.dwSize=1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

void textcolor(int color_number) //���� �� ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void gotoxy(int x, int y) //Ŀ�� ��ġ ���� �Լ�
{
	COORD Cur;
	Cur.X=x;
	Cur.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void clear() //ȭ�� ������(gotoxy �Լ��� Ȱ���Ͽ� �����Ÿ��� �ʵ���)
{
	int i, j;

	for(i=2;i<18;i++)
	{
		gotoxy(3, i);
		for(j=0;j<22;j++)
			printf("��");
	}
}