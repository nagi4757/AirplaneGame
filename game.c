#include "Team.h"

#define MAX_SHOOT 10 //ȭ�� �� �ִ� ź ��
#define MAX_ENEMY 100 //ȭ�� �� �ִ� �� ��

struct unit //���� ����ü
{
	int loc_x;
	int loc_y;
	int prv_x;
	int prv_y;
	int style;
	int m_t;
	int hp;
	int bomb;
};

struct rand_spawn
{
	int x;
	int next_x;
	int time;
	int next_time;
};

void maping(int dot[][20], unsigned int score, int hp, int bomb);
void enemy_rand_spawn(int *a, int *b);
int random();

unsigned int body(int l, int b, int e, int bul)
{
	int ch[20][20]={0}; //��
	unsigned int score=0; //�ʱ� ����
	int i, j;
	int arrow;
	int temp_clock;
	int enemy_count=0;
	short first=1;
	int time_set;
	struct unit player={6, 14, 6, 14, 2, 0, l, b}; //�ʱ� ����� ��
	struct unit shoot[MAX_SHOOT]={14, 18, 14, 18, 3, 0, 0, 0}; //�ʱ� ź ��
	struct unit enemy[MAX_ENEMY]={13, 17, 13, 17, 1, 0, 0, 0}; //�ʱ� �� ��
	struct rand_spawn s_e={6, 6, 0, 0};

	if(e==2)
		time_set=5;
	else if(e==1)
		time_set=10;
	else if(e==0)
		time_set=20;

	for(i=1;i<MAX_SHOOT;i++) //ź �ʱ�ȭ
		shoot[i]=shoot[0];
	for(i=1;i<MAX_ENEMY;i++) //�� �ʱ�ȭ
		enemy[i]=enemy[0];

	textcolor(6);
	for(i=2;i<18;i++)
	{
		gotoxy(29, i);
		printf("��");
	}
	gotoxy(35, 10);
	printf("MENU : M");
	gotoxy(34, 12);
	printf("TEAM");
	gotoxy(37, 13);
	printf("PROJECT");
	while(1)
	{
		while(1)
		{
			if(player.hp<=0)
				return score;

			//�� ������ �޴� ó��
			for(i=0;i<MAX_SHOOT;i++)
			{
				for(j=0;j<MAX_ENEMY;j++)
				{
					if(((shoot[i].loc_x==enemy[j].loc_x)&&(shoot[i].loc_y==enemy[j].loc_y))||((shoot[i].prv_x==enemy[j].loc_x)&&(shoot[i].prv_y==enemy[j].loc_y)))
					{
						enemy[j].hp--;
						shoot[i].loc_y=18;
						ch[(shoot[i].prv_y)][(shoot[i].prv_x)]=0;
						if(enemy[j].hp<=0)
						{
							enemy[j].loc_y=17;
							ch[(enemy[j].prv_y)][(enemy[j].prv_x)]=0;
							if(score<65530)
								score=score+10;
							enemy_count--;
							if(random()%101>=(100-bul))
							{
								if(random()%2==1)
								{
									if(player.hp<12)
									{
										player.hp++;
									}
								}
								else
								{
									if(player.bomb<6)
										player.bomb++;
								}
							}
						}
					}
				}
			}
			//������ �޴� ó�� ��

			//�÷��̾� ������ �޴� ó��
			for(i=0;i<MAX_ENEMY;i++)
			{
				if((enemy[i].loc_x==player.loc_x&&enemy[i].loc_y==player.loc_y)||enemy[i].loc_y==16)
				{
					player.hp--;
					enemy[i].loc_y=17;
					ch[(enemy[i].prv_y)][(enemy[i].prv_x)]=0;
					gotoxy(33, 4);
					printf("������������\a");
					enemy_count--;
				}
			}
			//������ ó�� ��
						
			//������� ź�� ó��
			for(i=0;i<MAX_SHOOT;i++)
			{
				if(shoot[i].prv_y==18)
					continue;

				shoot[i].prv_x=shoot[i].loc_x;
				shoot[i].prv_y=shoot[i].loc_y;
				
				if(((clock()/300))-shoot[i].m_t==1)
				{
					shoot[i].m_t=(clock()/300);
					
					if(shoot[i].loc_y==0)
					{
						shoot[i].loc_y=18;
						ch[(shoot[i].prv_y)][(shoot[i].prv_x)]=0;
						continue;
					}
					shoot[i].loc_y--;
				}

				ch[(shoot[i].prv_y)][(shoot[i].prv_x)]=0;
				ch[(shoot[i].loc_y)][(shoot[i].loc_x)]=shoot[i].style;
			}
			//ź ��
			
			//����� ó��
			ch[player.prv_y][player.prv_x]=0;
			player.prv_x=player.loc_x;
			player.prv_y=player.loc_y;
			ch[player.loc_y][player.loc_x]=player.style;
			//����� ��

			maping(ch, score, player.hp, player.bomb); //ȭ�� ����
			
			//������� �� ó��
			if(first==1)
			{
				temp_clock=clock();
				first--;
			}
			if((s_e.time<=(clock()-temp_clock)/100))
			{
				enemy_count++;
				temp_clock=clock();
				enemy_rand_spawn(&s_e.next_x, &s_e.next_time);
				s_e.time=(s_e.next_time*time_set);
				s_e.x=s_e.next_x;
				for(i=0;i<MAX_ENEMY;i++)
				{
					if(enemy[i].loc_y==17)
					{
						enemy[i].m_t=(clock()/350);
						enemy[i].prv_y=0;
						enemy[i].prv_x=s_e.x;
						enemy[i].loc_y=0;
						enemy[i].loc_x=s_e.x;
						enemy[i].hp=2;
						break;
					}
				}
			}
			for(i=0;i<MAX_ENEMY;i++)
			{
				if(enemy[i].prv_y==17)
					continue;
				enemy[i].prv_x=enemy[i].loc_x;
				enemy[i].prv_y=enemy[i].loc_y;
				
				if(((clock()/350))-enemy[i].m_t==1)
				{
					enemy[i].m_t=(clock()/350);
					enemy[i].loc_y++;
				}

				ch[(enemy[i].prv_y)][(enemy[i].prv_x)]=0;
				ch[(enemy[i].loc_y)][(enemy[i].loc_x)]=enemy[i].style;
			}
			//�� ��
			
			if(kbhit()) //����ڰ� Ű���带 ������
				break; //�ݺ� ����
		}
		arrow=getch(); //Ű�� �Է¹ޱ� ����
		if(arrow==extra||arrow==0) //Ȯ�� Ű�ڵ� �Ǵ�
		{
			arrow=getch();
			if(arrow==left) //���� �̵�
			{
				if(player.loc_x>0)
				{
					player.prv_x=player.loc_x;
					player.loc_x--;
				}
			}
			else if(arrow==right) //������ �̵�
			{
				if(player.loc_x<12)
				{
					player.prv_x=player.loc_x;
					player.loc_x++;
				}
			}
			else if((arrow==up)&&!(ch[player.loc_y-1][player.loc_x]==3)) //�̻���
			{
				for(i=0;i<MAX_SHOOT;i++)
				{
					if(shoot[i].loc_y==18)
					{
						shoot[i].m_t=(clock()/300);
						shoot[i].prv_y=player.loc_y-1;
						shoot[i].prv_x=player.loc_x;
						shoot[i].loc_y=player.loc_y-1;
						shoot[i].loc_x=player.loc_x;
						break;
					}
				}
			}
			else if(arrow==down) //��ź
			{
				if(player.bomb>0)
				{
					player.bomb--;
					gotoxy(33, 7);
					printf("������������");
					for(i=0;i<enemy_count;i++)
					{
						if(score<65530)
							score=score+10;
					}
					for(i=0;i<MAX_ENEMY;i++)
					{
						if(!(enemy[i].loc_y==17))
						{
							ch[(enemy[i].loc_y)][(enemy[i].loc_x)]=0;
							enemy[i].loc_y=17;
							ch[(enemy[i].prv_y)][(enemy[i].prv_x)]=0;
							enemy_count--;
						}
					}
				}
			}
		}
		else if(arrow=='m'||arrow=='M') //�޴��� ���ư���
		{
			int sel=0;

			clear();

			textcolor(15);
			gotoxy(13, 8);
			printf("������ �����Ͻðڽ��ϱ�?");
			
			while(1)
			{
				if(sel==0)
				{
					gotoxy(17, 10);
					textcolor(11);
					printf("��(Y)");
					textcolor(15);
					gotoxy(24, 10);
					printf("�ƴϿ�(N)");
				}
				else if(sel==1)
				{
					gotoxy(17, 10);
					printf("��(Y)");
					textcolor(11);
					gotoxy(24, 10);
					printf("�ƴϿ�(N)");
					textcolor(15);
				}

				arrow=getch(); //����Ű�� �Է¹ޱ� ����
				if(arrow==extra||arrow==0) //Ȯ�� Ű�ڵ� �Ǵ�
				{
					arrow=getch();
					if(arrow==left) //���� ����Ű�� ��
					{
						if(sel==1)
							sel--;
					}
					else if(arrow==right) //������ ����Ű�� ��
					{
						if(sel==0)
							sel++;							
					}
				}
				else if(arrow==enter) //������ ��
				{
					if(sel==0)
						return score;
					else
						return 0;
				}
				else if(arrow=='y'||arrow=='Y')
					return score;
				else if(arrow=='n'||arrow=='N')
					return 0;
			}
			break; //Ż��
		}
	}
	return 0;
}

void maping(int dot[][20], int score, int hp, int bomb) //���� �� �� �����
{
	int i, j;
	
	for(i=2;i<18;i++)
	{
		gotoxy(3, i);
		for(j=0;j<13;j++)
		{
			if(dot[i-2][j]==1)
			{
				textcolor(12);
				printf("��");
			}
			else if(dot[i-2][j]==2)
			{
				textcolor(9);
				printf("��");
			}
			else if(dot[i-2][j]==3)
			{
				textcolor(14);
				printf("��");
			}
			else
				printf("��");
		}
	}

	textcolor(12);
	gotoxy(32, 3);
	printf("HP");
	gotoxy(33, 4);
	for(i=0;i<hp/2;i++)
		printf("��");
	if(hp%2==1)
		printf("��");

	textcolor(10);
	gotoxy(32, 6);
	printf("BOMB");
	gotoxy(33, 7);
	for(i=0;i<bomb;i++)
		printf("��");

	textcolor(11);
	gotoxy(32, 15);
	printf("SCORE");
	gotoxy(39, 16);
	printf("%0.7d", score);
}

void enemy_rand_spawn(int *a, int *b)
{
	*a=random()%13;
	*b=random()%3+1;
}

int random()
{
	srand(((unsigned)(time(NULL))+rand()*4));

	return rand();
}