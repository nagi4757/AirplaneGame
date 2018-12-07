#include "Team.h"

void ranking_load()
{
	struct ranking { //이진파일을 불러서 넣을 구조체 변수선언
		unsigned int get_i;
		char get_c[20];
	}s[10]; //구조체 변수 s
	int i; //카운팅개념i
	int pre_clock=clock();
	char user=0;
	int color;
	FILE *fp;
	fp=fopen("TP.dat","rb"); //불러올 파일열기.
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
	printf("┌─────랭─킹─────┐");
	for(i=0;i<10;i++)
	{
		fread(&s[i],sizeof(struct ranking),1,fp); //이진파일에서 데이터 뽑기
		
		if(i==0)
		{
			gotoxy(10, i+5);
			printf("│");
			textcolor(12);
			printf("%3d위",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("│");
		}
		else if(i==1)
		{
			gotoxy(10, i+5);
			printf("│");
			textcolor(10);
			printf("%3d위",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("│");
		}
		else if(i==2)
		{
			gotoxy(10, i+5);
			printf("│");
			textcolor(14);
			printf("%3d위",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("│");
		}
		else if(i<7)
		{
			gotoxy(10, i+5);
			printf("│");
			textcolor(7);
			printf("%3d위",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("│");
		}
		else
		{
			gotoxy(10, i+5);
			printf("│");
			textcolor(8);
			printf("%3d위",i+1);
			gotoxy(19, i+5);
			printf("%9s",s[i].get_c);
			gotoxy(28, i+5);
			printf("%10d",s[i].get_i);
			textcolor(15);
			gotoxy(38, i+5);
			printf("│");
		}
	}
	fclose(fp);//파일닫음
	gotoxy(10, i+5);
	printf("└─────────────┘"); //틀 구현
	//초기화
	gotoxy(24,i+5);
	printf("랭킹 초기화 : R");
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
			printf("%3d위",1);
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
					strcpy(s[i].get_c,"\0"); //초기화
				}
				for(i=0;i<10;i++)
					fwrite(&s[i],sizeof(struct ranking),1,fp);
				fclose(fp);//파일닫음
				for(i=0;i<10;i++)
				{
					fread(&s[i],sizeof(struct ranking),1,fp); //이진파일에서 데이터 뽑기
		
					if(i==0)
					{
						gotoxy(10, i+5);
						printf("│");
						textcolor(12);
						printf("%3d위",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("│");
					}
					else if(i==1)
					{
						gotoxy(10, i+5);
						printf("│");
						textcolor(10);
						printf("%3d위",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("│");
					}
					else if(i==2)
					{
						gotoxy(10, i+5);
						printf("│");
						textcolor(14);
						printf("%3d위",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("│");
					}
					else if(i<7)
					{
						gotoxy(10, i+5);
						printf("│");
						textcolor(7);
						printf("%3d위",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("│");
					}
					else
					{
						gotoxy(10, i+5);
						printf("│");
						textcolor(8);
						printf("%3d위",i+1);
						gotoxy(19, i+5);
						printf("%9s",s[i].get_c);
						gotoxy(28, i+5);
						printf("%10d",s[i].get_i);
						textcolor(15);
						gotoxy(38, i+5);
						printf("│");
					}
				}
				fclose(fp);//파일닫음
			}
			else
				break;
		}
	}
}

int ranking_made(unsigned int score)
{
	struct ranking {//이진파일을 불러서 넣을 구조체 변수선언
		unsigned int get_i;
		char get_c[20];
	}s[11];//구조체 변수 s
	int i,j,least,count=0;//카운팅개념i
	char c;
	struct ranking temp;
	FILE *fp;
	fp=fopen("TP.dat","rb"); //읽기형식으로 열기
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
	printf("랭킹에 등록할 이름을 입력해주세요."); //기록 갱신에 들어갈 이름 생성
	for(i=0;i<11;i++)
		s[10].get_c[i]='\0';
	gotoxy(5,8);
	printf("──────");
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
		fread(&s[i],sizeof(struct ranking),1,fp); //이진파일에서 추출
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
	fp=fopen("TP.dat","wb"); //파일에 다시 입력하기
	for(i=10;i>0;i--)
		fwrite(&s[i],sizeof(struct ranking),1,fp);
	fclose(fp);
	return 0;
}