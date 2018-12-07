#include "Team.h"

void option_config(int *l,int *b,int *e,int *bul)
{
	int sel=1;
	int arrow;
	int life,boom,enemy,bullet;
	char enemy_c[5];
	FILE *fp;
	fp=fopen("TP.setting","r");
	if(fp==NULL)
	{
		fp=fopen("TP.setting","w");
		fprintf(fp,"10\n3\n1\n1");
		fclose(fp);
		fp=fopen("TP.setting","r");
	}
	fscanf(fp,"%d\n%d\n%d\n%d",&life,&boom,&enemy,&bullet);
	fclose(fp);
	
	if(enemy==0)
		strcpy(enemy_c, "느림\0");
	else if(enemy==1)
		strcpy(enemy_c, "보통\0");
	else
		strcpy(enemy_c, "빠름\0");
	gotoxy(12, 5);
	printf("체력		< %4d >",life);
	gotoxy(12, 6);
	printf("폭탄		< %4d >",boom);
	gotoxy(12, 8);
	printf("적 출현 속도	< %s >",enemy_c);
	gotoxy(12, 9);
	printf("아이템 획득 확률	< %4d >",bullet);
	gotoxy(12, 11);
	printf("기본 값으로");
	gotoxy(12, 13);
	printf("설정 종료");
		
	while(1)
	{
		if(enemy==0)
			strcpy(enemy_c, "느림\0");
		else if(enemy==1)
			strcpy(enemy_c, "보통\0");
		else
			strcpy(enemy_c, "빠름\0");
		if(sel==1) //목숨
		{
			gotoxy(12, 5);
			textcolor(11);
			printf("체력		< %4d >",life);
			textcolor(15);
			gotoxy(12, 6);
			printf("폭탄		< %4d >",boom);
			gotoxy(12, 13);
			printf("설정 종료");
		}

		else if(sel==2) //폭탄
		{
			gotoxy(12, 5);
			printf("체력		< %4d >",life);
			gotoxy(12, 6);
			textcolor(11);
			printf("폭탄		< %4d >",boom);
			textcolor(15);
			gotoxy(12, 8);
			printf("적 출현 속도	< %s >",enemy_c);
		}
		else if(sel==3) //적체력
		{
			gotoxy(12, 6);
			printf("폭탄		< %4d >",boom);
			gotoxy(12, 8);
			textcolor(11);
			printf("적 출현 속도	< %s >",enemy_c);
			textcolor(15);
			gotoxy(12, 9);
			printf("아이템 획득 확률	< %4d >",bullet);
		}
		else if(sel==4) //적체력
		{
			gotoxy(12, 8);
			printf("적 출현 속도	< %s >",enemy_c);
			gotoxy(12, 9);
			textcolor(11);
			printf("아이템 획득 확률	< %4d >",bullet);
			textcolor(15);
			gotoxy(12, 11);
			printf("기본 값으로");
		}
		else if(sel==5)
			{
			gotoxy(12, 9);
			printf("아이템 획득 확률	< %4d >",bullet);
			gotoxy(12, 9);
			textcolor(11);
			gotoxy(12, 11);
			printf("기본 값으로");
			textcolor(15);
			gotoxy(12, 13);
			printf("설정 종료");
		}
		else //종료
		{
			gotoxy(12, 5);
			printf("체력		< %4d >",life);
			gotoxy(12, 11);
			printf("기본 값으로");
			gotoxy(12, 13);
			textcolor(11);
			printf("설정 종료");
			textcolor(15);
		}
				
		arrow=getch(); //방향키를 입력받기 위함
		if(arrow==extra||arrow==0) //확장 키코드 판단
		{
			arrow=getch();
			if(arrow==up) //윗 방향키일 때
			{
				if(sel==1)
					sel=6;
				else
					sel--;
			}
			else if(arrow==down) //아랫 방향키일 때
			{
				if(sel==6)
					sel=1;
				else
					sel++;
			}
			else if(arrow==left) //왼쪽 방향키일 때
			{
				if(sel==1&&life>1)
					life--;
				else if(sel==2&&boom>1)
					boom--;
				else if(sel==3&&enemy>0)
					enemy--;
				else if(sel==4&&bullet>0)
					bullet--;
			}
			else if(arrow==right) //오른 방향키일 때
			{
				if(sel==1&&life<12)
					life++;
				else if(sel==2&&boom<6)
					boom++;
				else if(sel==3&&enemy<2)
					enemy++;
				else if(sel==4&&bullet<100)
					bullet++;
			}
		}
		else if(arrow==enter) //엔터일 때
		{
			if(sel==5)
			{
				life=10;
				boom=3;
				enemy=1;
				bullet=1;
				if(enemy==0)
					strcpy(enemy_c, "느림\0");
				else if(enemy==1)
					strcpy(enemy_c, "보통\0");
				else
					strcpy(enemy_c, "빠름\0");
				gotoxy(12, 5);
				printf("체력		< %4d >",life);
				gotoxy(12, 6);
				printf("폭탄		< %4d >",boom);
				gotoxy(12, 8);
				printf("적 출현 속도	< %s >",enemy_c);
				gotoxy(12, 9);
				printf("아이템 획득 확률	< %4d >",bullet);
			}
			else if(sel==6)
			{
				fp=fopen("TP.setting","w");
				fprintf(fp,"%d\n%d\n%d\n%d",life,boom,enemy,bullet);
				fclose(fp);
				break; //탈출
			}
		}
	}
	*l=life;
	*b=boom;
	*e=enemy;
	*bul=bullet;
}