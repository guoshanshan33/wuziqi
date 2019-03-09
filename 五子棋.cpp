#include<stdio.h>
#include<stdlib.h>
#define N 19
void DrawPanel();
int zouqihang();
int zouqilie();
int check(int x,int y);
void heqi();
void over();
void welcome();
int pieces[N][N]={0};
int flag = 1;

int main(void)
{
	int x, y;
	int winner;
	int countpieces = 0;
	welcome();
	DrawPanel();
	while(countpieces<N*N)
	{
		x = zouqihang();
		y = zouqilie();
		x = x-1;
		y = y-1;
		
		if (pieces[x][y]== 0)
		{
			pieces[x][y] = flag;
			countpieces++;
			
			if (flag == 1)
				flag =2;
			else
				flag= 1;
			winner = check(x,y);
			if(winner == 1)
			{
				printf("恭喜A★赢了！\n");
				break;
			}else if(winner == 2)
			{
				printf("恭喜B☆赢了！\n");
				break;
			}
		}else{
				printf("ERROR!\n");
				printf("落子行列错误，请随意按键重新输入！\n");
				getchar();
				getchar();
			}		
			DrawPanel();
			
	}
	if (countpieces == N*N)
	{
		heqi();
	}else
	{
		over();
	}
	
	return 0;
 } 
 
 
 
 void DrawPanel()
 {
 	int count = 1;
 	int i,j;
 	system("CLS");
 	for (i = 0;i<=N;i++)/*输出列标*/ 
 	{
 		if(i==0)
 		{
 			printf("  ");
 		}else
 		{
 			printf("%4d",count);
 			count++;
		 }
	}
	printf("\n");
	count = 1;
	for(i=0;i<N;i++)
	{
	 	for(j=-1;j<N;j++)
	 	{
	 		if(j == -1)
	 		{
	 			printf("%2d",count);
	 			count++;	
			}
	 		
			else
		    {
		 		if (pieces[i][j] == 0)
		 		{
		 			printf("   .");
		 		}
		 		else if(pieces[i][j] ==1)
				{
			 		printf("   @"); 
				}else if(pieces[i][j] ==2)
				{
					printf("   #"); 
				}
		    }
        }
        printf("\n");
    }
}


int zouqihang()
{
	int x;
	if(flag==1)
	{
		printf("玩家A★"); 
	}else
	{
		printf("玩家B☆"); 
	}
	printf("请输入要走棋子所在行数！\n");
	printf("x = ");
	scanf("%d",&x);
	while (x>N-1 || x<1)
	{
		printf("error!\n");
		if(flag == 1)
		{
			printf("玩家A★");
		}else
		{
			printf("玩家B☆");
		}
		printf("请输入要走棋子所在行数！\n");
		printf("x = ");
	    scanf("%d",&x);
	}
	return x;
}


int zouqilie()
{
	int y;
	if(flag==1)
	{
		printf("玩家A★"); 
	}else
	{
		printf("玩家B☆"); 
	}
	printf("请输入要走棋子所在行数！\n");
	printf("y = ");
	scanf("%d",&y);
	while (y>N-1 || y<1)
	{
		printf("error!\n");
		if(flag == 1)
		{
			printf("玩家A★");
		}else
		{
			printf("玩家B☆");
		}
		printf("请输入要走棋子所在列数！\n");
		printf("y = ");
	    scanf("%d",&y);
	}
	return y;
}

int check(int x,int y)
{
	/*检查行 */ 
	int count = 1;
	int i=x,j=y;
	j++;
	while(j<N && count<5)
	{
		if(pieces[i][j] == pieces[x][y])
		{
			count ++;
		}else
		{
			break;
		}
		j++;
	}
	j = y -1;
	while (j>=0 && count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
			count++;
		}else
		{
			break;
		}
		j--;
	}
	if(count == 5)
	{
		return pieces[x][y];
	}
	
	/*检查列*/ 
	i = x;
	j = y;
	count = 1;
	
	i = i+1;
	while(i<N && count<5)
	{
		if(pieces[i][j] == pieces[x][y])
		{
			count ++;
		}else
		{
			break;
		}
		i++;
	}
	i = x -1;
	while (i>=0 && count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
			count++;
		}else
		{
			break;
		}
		i--;
	}
	if(count == 5)
	{
		return pieces[x][y];
	}
	
	/*左斜行*/
	i = x;
	j = y;
	count = 1;
	
	i = i-1;
	j = j-1;
	while(i>=0 && j>=0 && count<5)
	{
		if(pieces[i][j] == pieces[x][y])
		{
			count ++;
		}else
		{
			break;
		}
		i--;
		j--;
	}
	i = x +1;
	j = y - 1;
	while (i<N && j>=0 &&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
			count++;
		}else
		{
			break;
		}
		i++;
		j--;
	}
	if(count == 5)
	{
		return pieces[x][y];
	}
	
	/*右斜行*/ 
	i = x;
	j = y;
	count = 1;
	
	i = x-1;
	j = y+1;
	while(i>=0 && j<N && count<5)
	{
		if(pieces[i][j] == pieces[x][y])
		{
			count ++;
		}else
		{
			break;
		}
		i--;
		j++;
	}
	i = x +1;
	j = y + 1;
	while (i<N && j<N &&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
			count++;
		}else
		{
			break;
		}
		i++;
		j++;
	}
	if(count == 5)
	{
		return pieces[x][y];
	}
	return 0;
}

/*信息模块*/
void heqi()
{
	system("CLS");
	printf("*****************************************************************************\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                              heqi                                         *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*****************************************************************************\n");
}

void over()
{
	system("CLS");
	printf("*****************************************************************************\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                           Game over                                       *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*****************************************************************************\n");
}

void welcome()
{
	system("CLS");
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
	printf("*                             Welcome                                      *\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	printf("Press any key, then start!");
	getchar();
}






    
	
