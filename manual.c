#include "Team.h"

void print(int page);
void page1();
void page2();
void page3();
void page4();
void page5();

void readme()
{
	int arrow;
	int page=1;

	page1();
	while(1)
	{
		if(kbhit())
		{
			arrow=getch();
			if(arrow==extra||arrow==0)
			{
				arrow=getch();
				if(arrow==left)
				{
					clear();
					if(page>1)
						page--;
					else
						page=5;
				}
				else if(arrow==right)
				{
					clear();
					if(page<5)
						page++;
					else
						page=1;
				}
			}
			else if(arrow=='m'||arrow=='M')
			{
				clear();
				break;
			}
			print(page);
		}
	}
}

void print(int page)
{
	if(page==1)
		page1();
	else if(page==2)
		page2();
	else if(page==3)
		page3();
	else if(page==4)
		page4();
	else if(page==5)
		page5();
}

void page1()
{
	textcolor(15);
	gotoxy(5, 3);
	printf("������ �� ������Ʈ��");
	gotoxy(5, 4);
	printf("������ ���� �����Դϴ�.");
	gotoxy(5, 6);
	printf("���� �÷��̾ ��ų�");
	gotoxy(5, 7);
	printf("�� �ؿ� ������ HP�� ���̰� �Ǹ�,");
	gotoxy(5, 8);
	printf("�÷��̾�� �Ѱ� ��ź����");
	gotoxy(5, 9);
	printf("�̸� �����ϸ� �˴ϴ�.");
	gotoxy(5, 11);
	printf("���� ���� �⺻���� �������̽���");
	gotoxy(5, 12);
	printf("�̷��� �����Ǿ� �ֽ��ϴ�.");
	gotoxy(28, 15);
	printf("�¿� ����Ű�� ����");
	gotoxy(5, 16);
	printf("�޴��� ���ư��� : M");
	gotoxy(37, 16);
	printf("< 1 / 5 >");
}

void page2()
{
	int i;
	
	for(i=2;i<18;i++)
	{
		textcolor(6);
		gotoxy(29, i);
		printf("��");
	}
	gotoxy(35, 10);
	printf("MENU : M");
	gotoxy(34, 12);
	printf("TEAM");
	gotoxy(37, 13);
	printf("PROJECT");
	gotoxy(9, 6);
	textcolor(12);
	printf("��");
	gotoxy(13, 15);
	textcolor(9);
	printf("��");
	gotoxy(23, 10);
	textcolor(14);
	printf("��");
	textcolor(12);
	gotoxy(32, 3);
	printf("HP");
	gotoxy(33, 4);
	printf("������");
	textcolor(10);
	gotoxy(32, 6);
	printf("BOMB");
	gotoxy(33, 7);
	printf("�ΨΨ�");
	textcolor(11);
	gotoxy(32, 14);
	printf("SCORE");
	gotoxy(39, 15);
	printf("%0.7d", 1050);
	textcolor(15);
	gotoxy(5, 16);
	printf("�޴��� ���ư��� : M");
	gotoxy(37, 16);
	printf("< 2 / 5 >");
}

void page3()
{
	gotoxy(5, 3);
	textcolor(9);
	printf("�� : �÷��̾�, �¿� ����Ű�� ����");
	gotoxy(5, 4);
	textcolor(12);
	printf("�� : ��");
	gotoxy(5, 5);
	textcolor(14);
	printf("�� : �̻���, �� ����Ű�� �߻�");
	gotoxy(5, 7);
	textcolor(12);
	printf("�� : �� ĭ ü��");
	gotoxy(5, 8);
	printf("�� : �� ĭ ü��");
	gotoxy(5, 9);
	textcolor(10);
	printf("�� : ��ź, �Ʒ� ����Ű�� �ߵ�");
	textcolor(15);
	gotoxy(5, 11);
	printf("ü�°� ��ź�� ���� �̻��Ϸ� ����� ��");
	gotoxy(5, 12);
	printf("���� Ȯ���� +1�˴ϴ�.(���� ����)");
	gotoxy(5, 13);
	printf("(ü�� �� ĭ ȸ�� or ��ź +1)");
	gotoxy(5, 16);
	printf("�޴��� ���ư��� : M");
	gotoxy(37, 16);
	printf("< 3 / 5 >");
}

void page4()
{
	gotoxy(5, 3);
	printf("�������� �ʱ� HP�� ��ź,");
	gotoxy(5, 4);
	printf("���� �����Ǵ� �ð��� ������ ȹ�� Ȯ����");
	gotoxy(5, 5);
	printf("������ �� �ֽ��ϴ�.");
	gotoxy(5, 16);
	printf("�޴��� ���ư��� : M");
	gotoxy(37, 16);
	printf("< 4 / 5 >");
}

void page5()
{
	gotoxy(5, 3);
	printf("�׷�, ��ſ� �÷��� �ǽñ� �ٶ��ϴ�!");
	gotoxy(5, 16);
	printf("�޴��� ���ư��� : M");
	gotoxy(37, 16);
	printf("< 5 / 5 >");
}