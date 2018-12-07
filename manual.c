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
	printf("저희의 팀 프로젝트는");
	gotoxy(5, 4);
	printf("간단한 슈팅 게임입니다.");
	gotoxy(5, 6);
	printf("적이 플레이어에 닿거나");
	gotoxy(5, 7);
	printf("맨 밑에 닿으면 HP가 깎이게 되며,");
	gotoxy(5, 8);
	printf("플레이어는 총과 폭탄으로");
	gotoxy(5, 9);
	printf("이를 저지하면 됩니다.");
	gotoxy(5, 11);
	printf("게임 내의 기본적인 인터페이스는");
	gotoxy(5, 12);
	printf("이렇게 구성되어 있습니다.");
	gotoxy(28, 15);
	printf("좌우 방향키로 조작");
	gotoxy(5, 16);
	printf("메뉴로 돌아가기 : M");
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
		printf("▒");
	}
	gotoxy(35, 10);
	printf("MENU : M");
	gotoxy(34, 12);
	printf("TEAM");
	gotoxy(37, 13);
	printf("PROJECT");
	gotoxy(9, 6);
	textcolor(12);
	printf("∇");
	gotoxy(13, 15);
	textcolor(9);
	printf("⊙");
	gotoxy(23, 10);
	textcolor(14);
	printf("｜");
	textcolor(12);
	gotoxy(32, 3);
	printf("HP");
	gotoxy(33, 4);
	printf("♥♥♡");
	textcolor(10);
	gotoxy(32, 6);
	printf("BOMB");
	gotoxy(33, 7);
	printf("ⓑⓑⓑ");
	textcolor(11);
	gotoxy(32, 14);
	printf("SCORE");
	gotoxy(39, 15);
	printf("%0.7d", 1050);
	textcolor(15);
	gotoxy(5, 16);
	printf("메뉴로 돌아가기 : M");
	gotoxy(37, 16);
	printf("< 2 / 5 >");
}

void page3()
{
	gotoxy(5, 3);
	textcolor(9);
	printf("⊙ : 플레이어, 좌우 방향키로 조작");
	gotoxy(5, 4);
	textcolor(12);
	printf("∇ : 적");
	gotoxy(5, 5);
	textcolor(14);
	printf("｜ : 미사일, 윗 방향키로 발사");
	gotoxy(5, 7);
	textcolor(12);
	printf("♥ : 한 칸 체력");
	gotoxy(5, 8);
	printf("♡ : 반 칸 체력");
	gotoxy(5, 9);
	textcolor(10);
	printf("ⓑ : 폭탄, 아랫 방향키로 발동");
	textcolor(15);
	gotoxy(5, 11);
	printf("체력과 폭탄은 적을 미사일로 잡았을 시");
	gotoxy(5, 12);
	printf("일정 확률로 +1됩니다.(설정 가능)");
	gotoxy(5, 13);
	printf("(체력 반 칸 회복 or 폭탄 +1)");
	gotoxy(5, 16);
	printf("메뉴로 돌아가기 : M");
	gotoxy(37, 16);
	printf("< 3 / 5 >");
}

void page4()
{
	gotoxy(5, 3);
	printf("설정에서 초기 HP와 폭탄,");
	gotoxy(5, 4);
	printf("적이 생성되는 시간과 아이템 획득 확률을");
	gotoxy(5, 5);
	printf("조정할 수 있습니다.");
	gotoxy(5, 16);
	printf("메뉴로 돌아가기 : M");
	gotoxy(37, 16);
	printf("< 4 / 5 >");
}

void page5()
{
	gotoxy(5, 3);
	printf("그럼, 즐거운 플레이 되시길 바랍니다!");
	gotoxy(5, 16);
	printf("메뉴로 돌아가기 : M");
	gotoxy(37, 16);
	printf("< 5 / 5 >");
}