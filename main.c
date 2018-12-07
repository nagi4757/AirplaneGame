#include "Team.h"

void main()
{
	int sel, temp=1; //사용자가 최종으로 선택한 것을 저장하기 위함, temp 는 이전 선택값 저장
	int i, j;
	unsigned int t_score;
	char player_name[10];
	int hp, bomb, enemy, bullet;
	FILE *fp;

	system("mode con: cols=50 lines=20"); //기본 콘솔 화면 크기 설정
	cursor(); //_커서 안 보이게

	textcolor(6); //여기서부터 기본 겉 틀
	printf("\n ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
	for(i=0;i<16;i++)
	{
		printf(" ▒");
		for(j=0;j<22;j++)
			printf("　");
		printf("▒\n");
	}
	printf(" ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"); //겉 틀 끝

#if online==1
	textcolor(13);
	gotoxy(43, 19);
	printf("배포판");
#endif
	
	fp=fopen("TP.setting","r");
	if(fp==NULL)
	{
		fp=fopen("TP.setting","w");
		fprintf(fp,"10\n3\n1\n1");
		fclose(fp);
		fp=fopen("TP.setting","r");
	}
	fscanf(fp,"%d\n%d\n%d\n%d",&hp, &bomb, &enemy, &bullet);
	fclose(fp);

	while(1) //기본으로 타이틀을 무한 반복
	{
		sel=title(temp); //전에 선택한 값으로 타이틀을 불러오고 최종 선택 값 받기

		temp=sel; //정해지면 방금 값을 이전 값으로 저장

		switch(sel)
		{
			case 1: //게임 시작
				t_score=0;
				gotoxy(4, 3);
				t_score=body(hp, bomb, enemy, bullet);
				clear();
				gotoxy(20, 8);
				textcolor(12);
				printf("GAME OVER");
				gotoxy(15, 10);
				textcolor(15);
				printf("Please press any key");
				getch();
				clear();
				if(t_score>0)
					ranking_made(t_score);
				clear();
				ranking_load();
				clear();
				break;
			case 2: //게임 설명
				gotoxy(4, 3);
				readme();
				clear();
				break;
			case 3: //랭킹
				gotoxy(4, 3);
				ranking_load();
				clear();
				break;
			case 4: //제작자 소개
				credit();
				getch();
				clear();
				break;
			case 5: //설정
				gotoxy(4, 3);
				option_config(&hp, &bomb, &enemy, &bullet);
				clear();
				break;
			case 6: //게임 종료
				exit(1);
		}
	}
}