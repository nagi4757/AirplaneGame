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
		strcpy(enemy_c, "����\0");
	else if(enemy==1)
		strcpy(enemy_c, "����\0");
	else
		strcpy(enemy_c, "����\0");
	gotoxy(12, 5);
	printf("ü��		< %4d >",life);
	gotoxy(12, 6);
	printf("��ź		< %4d >",boom);
	gotoxy(12, 8);
	printf("�� ���� �ӵ�	< %s >",enemy_c);
	gotoxy(12, 9);
	printf("������ ȹ�� Ȯ��	< %4d >",bullet);
	gotoxy(12, 11);
	printf("�⺻ ������");
	gotoxy(12, 13);
	printf("���� ����");
		
	while(1)
	{
		if(enemy==0)
			strcpy(enemy_c, "����\0");
		else if(enemy==1)
			strcpy(enemy_c, "����\0");
		else
			strcpy(enemy_c, "����\0");
		if(sel==1) //���
		{
			gotoxy(12, 5);
			textcolor(11);
			printf("ü��		< %4d >",life);
			textcolor(15);
			gotoxy(12, 6);
			printf("��ź		< %4d >",boom);
			gotoxy(12, 13);
			printf("���� ����");
		}

		else if(sel==2) //��ź
		{
			gotoxy(12, 5);
			printf("ü��		< %4d >",life);
			gotoxy(12, 6);
			textcolor(11);
			printf("��ź		< %4d >",boom);
			textcolor(15);
			gotoxy(12, 8);
			printf("�� ���� �ӵ�	< %s >",enemy_c);
		}
		else if(sel==3) //��ü��
		{
			gotoxy(12, 6);
			printf("��ź		< %4d >",boom);
			gotoxy(12, 8);
			textcolor(11);
			printf("�� ���� �ӵ�	< %s >",enemy_c);
			textcolor(15);
			gotoxy(12, 9);
			printf("������ ȹ�� Ȯ��	< %4d >",bullet);
		}
		else if(sel==4) //��ü��
		{
			gotoxy(12, 8);
			printf("�� ���� �ӵ�	< %s >",enemy_c);
			gotoxy(12, 9);
			textcolor(11);
			printf("������ ȹ�� Ȯ��	< %4d >",bullet);
			textcolor(15);
			gotoxy(12, 11);
			printf("�⺻ ������");
		}
		else if(sel==5)
			{
			gotoxy(12, 9);
			printf("������ ȹ�� Ȯ��	< %4d >",bullet);
			gotoxy(12, 9);
			textcolor(11);
			gotoxy(12, 11);
			printf("�⺻ ������");
			textcolor(15);
			gotoxy(12, 13);
			printf("���� ����");
		}
		else //����
		{
			gotoxy(12, 5);
			printf("ü��		< %4d >",life);
			gotoxy(12, 11);
			printf("�⺻ ������");
			gotoxy(12, 13);
			textcolor(11);
			printf("���� ����");
			textcolor(15);
		}
				
		arrow=getch(); //����Ű�� �Է¹ޱ� ����
		if(arrow==extra||arrow==0) //Ȯ�� Ű�ڵ� �Ǵ�
		{
			arrow=getch();
			if(arrow==up) //�� ����Ű�� ��
			{
				if(sel==1)
					sel=6;
				else
					sel--;
			}
			else if(arrow==down) //�Ʒ� ����Ű�� ��
			{
				if(sel==6)
					sel=1;
				else
					sel++;
			}
			else if(arrow==left) //���� ����Ű�� ��
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
			else if(arrow==right) //���� ����Ű�� ��
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
		else if(arrow==enter) //������ ��
		{
			if(sel==5)
			{
				life=10;
				boom=3;
				enemy=1;
				bullet=1;
				if(enemy==0)
					strcpy(enemy_c, "����\0");
				else if(enemy==1)
					strcpy(enemy_c, "����\0");
				else
					strcpy(enemy_c, "����\0");
				gotoxy(12, 5);
				printf("ü��		< %4d >",life);
				gotoxy(12, 6);
				printf("��ź		< %4d >",boom);
				gotoxy(12, 8);
				printf("�� ���� �ӵ�	< %s >",enemy_c);
				gotoxy(12, 9);
				printf("������ ȹ�� Ȯ��	< %4d >",bullet);
			}
			else if(sel==6)
			{
				fp=fopen("TP.setting","w");
				fprintf(fp,"%d\n%d\n%d\n%d",life,boom,enemy,bullet);
				fclose(fp);
				break; //Ż��
			}
		}
	}
	*l=life;
	*b=boom;
	*e=enemy;
	*bul=bullet;
}