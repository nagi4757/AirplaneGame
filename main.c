#include "Team.h"

void main()
{
	int sel, temp=1; //����ڰ� �������� ������ ���� �����ϱ� ����, temp �� ���� ���ð� ����
	int i, j;
	unsigned int t_score;
	char player_name[10];
	int hp, bomb, enemy, bullet;
	FILE *fp;

	system("mode con: cols=50 lines=20"); //�⺻ �ܼ� ȭ�� ũ�� ����
	cursor(); //_Ŀ�� �� ���̰�

	textcolor(6); //���⼭���� �⺻ �� Ʋ
	printf("\n �ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�\n");
	for(i=0;i<16;i++)
	{
		printf(" ��");
		for(j=0;j<22;j++)
			printf("��");
		printf("��\n");
	}
	printf(" �ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�\n"); //�� Ʋ ��

#if online==1
	textcolor(13);
	gotoxy(43, 19);
	printf("������");
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

	while(1) //�⺻���� Ÿ��Ʋ�� ���� �ݺ�
	{
		sel=title(temp); //���� ������ ������ Ÿ��Ʋ�� �ҷ����� ���� ���� �� �ޱ�

		temp=sel; //�������� ��� ���� ���� ������ ����

		switch(sel)
		{
			case 1: //���� ����
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
			case 2: //���� ����
				gotoxy(4, 3);
				readme();
				clear();
				break;
			case 3: //��ŷ
				gotoxy(4, 3);
				ranking_load();
				clear();
				break;
			case 4: //������ �Ұ�
				credit();
				getch();
				clear();
				break;
			case 5: //����
				gotoxy(4, 3);
				option_config(&hp, &bomb, &enemy, &bullet);
				clear();
				break;
			case 6: //���� ����
				exit(1);
		}
	}
}