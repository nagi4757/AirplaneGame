#include "Team.h"

void ranking_load()
{
	struct ranking { //���������� �ҷ��� ���� ����ü ��������
		unsigned int get_i;
		char get_c[20];
	}s[10]; //����ü ���� s
	int i; //ī���ð���i
	int pre_clock=clock();
	char user=0;
	int color;
	FILE *fp;
	fp=fopen("TP.dat","rb"); //�ҷ��� ���Ͽ���.
	if(fp==NULL)
	{
		struct ranking s[10]={0, "\0"};
		fp=fopen("TP.dat","w+b");
		for(i=0;i<10;i++)
		{
			s[i]=s[0];
			fwrite(&s[i],sizeof(struct ranking),1,fp);
		}
		fclose(fp);
		fp=fopen("TP.dat","rb");
	}
	textcolor(15);
	gotoxy(10, 4);
	printf("����������������ŷ������������");
	for(i=0;i<10;i++)
	{
		fread(&s[i],sizeof(struct ranking),1,fp); //�������Ͽ��� ������ �̱�
		
		if(i==0)
		{
			gotoxy(10, i+5);
			printf("��");
			textcolor(12);
			printf("%3d��",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("��");
		}
		else if(i==1)
		{
			gotoxy(10, i+5);
			printf("��");
			textcolor(10);
			printf("%3d��",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("��");
		}
		else if(i==2)
		{
			gotoxy(10, i+5);
			printf("��");
			textcolor(14);
			printf("%3d��",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("��");
		}
		else if(i<7)
		{
			gotoxy(10, i+5);
			printf("��");
			textcolor(7);
			printf("%3d��",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("��");
		}
		else
		{
			gotoxy(10, i+5);
			printf("��");
			textcolor(8);
			printf("%3d��",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("��");
		}
	}
	fclose(fp);//���ϴ���
	gotoxy(10, i+5);
	printf("������������������������������"); //Ʋ ����
	//�ʱ�ȭ
	gotoxy(24,i+5);
	printf("��ŷ �ʱ�ȭ : R");
	while(1)
	{
		gotoxy(12, 5);
		if(clock()-pre_clock>125)
		{
			color=rand()%14+1;
			pre_clock=clock();
			while((color==10)||(color==14))
				color=rand()%15;
			textcolor(color);
			printf("%3d��",1);
			gotoxy(19, 5);
			printf("%9s",s[0].get_c);
			gotoxy(28, 5);
			printf("%10d",s[0].get_i);
			textcolor(15);
		}
		if(kbhit())
		{
			user=getch();
			if((user=='r')||(user=='R'))
			{
				fp=fopen("TP.dat","wb");												
				for(i=0;i<10;i++)
				{
					s[i].get_i=0;
					strcpy(s[i].get_c,"\0"); //�ʱ�ȭ
				}
				for(i=0;i<10;i++)
					fwrite(&s[i],sizeof(struct ranking),1,fp);
				fclose(fp);//���ϴ���
				for(i=0;i<10;i++)
				{
					fread(&s[i],sizeof(struct ranking),1,fp); //�������Ͽ��� ������ �̱�
		
					if(i==0)
					{
						gotoxy(10, i+5);
						printf("��");
						textcolor(12);
						printf("%3d��",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("��");
					}
					else if(i==1)
					{
						gotoxy(10, i+5);
						printf("��");
						textcolor(10);
						printf("%3d��",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("��");
					}
					else if(i==2)
					{
						gotoxy(10, i+5);
						printf("��");
						textcolor(14);
						printf("%3d��",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("��");
					}
					else if(i<7)
					{
						gotoxy(10, i+5);
						printf("��");
						textcolor(7);
						printf("%3d��",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("��");
					}
					else
					{
						gotoxy(10, i+5);
						printf("��");
						textcolor(8);
						printf("%3d��",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("��");
					}
				}
				fclose(fp);//���ϴ���
			}
			else
				break;
		}
	}
}

int ranking_made(unsigned int score)
{
	struct ranking {//���������� �ҷ��� ���� ����ü ��������
		unsigned int get_i;
		char get_c[20];
	}s[11];//����ü ���� s
	int i,j,least,count=0;//ī���ð���i
	char c;
	struct ranking temp;
	FILE *fp;
	fp=fopen("TP.dat","rb"); //�б��������� ����
	if(fp==NULL)
	{
		struct ranking s[10]={0, "\0"};
		fp=fopen("TP.dat","w+b");
		for(i=0;i<10;i++)
		{
			s[i]=s[0];
			fwrite(&s[i],sizeof(struct ranking),1,fp);
		}
		fclose(fp);
		fp=fopen("TP.dat","rb");
	}
	s[10].get_i=score;
	clear();
	gotoxy(4,5);
	printf("��ŷ�� ����� �̸��� �Է����ּ���."); //��� ���ſ� �� �̸� ����
	for(i=0;i<11;i++)
		s[10].get_c[i]='\0';
	gotoxy(5,8);
	printf("������������");
	for(i=0;i<10;i++)
	{
		s[10].get_c[i]=getch();
		if(s[10].get_c[i]==13)
			break;
		if(i==9&&!(s[10].get_c[9]==back_space))
		{
			s[10].get_c[9]='\0';
			i--;
		}
		if(s[10].get_c[i]==back_space&&i>0)
		{
			s[10].get_c[i]='\0';
			s[10].get_c[i-1]='\0';
			i=i-2;
		}
		gotoxy(6,7);
		printf("%-9s", s[10].get_c);
	}
	s[10].get_c[i]='\0';
	if(s[10].get_c[0]=='\0')
		strcpy(s[10].get_c,"NO_NAME");
	for(i=0;i<10;i++)
		fread(&s[i],sizeof(struct ranking),1,fp); //�������Ͽ��� ����
	fclose(fp);
	for(i=0;i<10;i++)
	{
		least=i;
		for(j=i+1;j<11;j++)
		{
			if(s[j].get_i<s[least].get_i)
				least=j;
		}
		temp=s[i];
		s[i]=s[least];
		s[least]=temp;
	}
	fp=fopen("TP.dat","wb"); //���Ͽ� �ٽ� �Է��ϱ�
	for(i=10;i>0;i--)
		fwrite(&s[i],sizeof(struct ranking),1,fp);
	fclose(fp);
	return 0;
}