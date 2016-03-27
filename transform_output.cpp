#include<cstdio>

using namespace std;

char str[20];
int sodoku[10][10];

int main()
{
	int temp;
	scanf("%s",str);
	scanf("%d",&temp);
	while(temp)
	{
		if(temp>0)
		{
			temp--;
			int i=temp/81+1,j=(temp%81)/9+1,k=temp%9+1;
			sodoku[i][j]=k;
		}
		scanf("%d",&temp);
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			printf("%d",sodoku[i][j]);
			if(j<9&&j%3==0)printf("|");
		}
		printf("\n");
		if(i<9&&i%3==0)printf("---+---+---\n");
	}
	return 0;
}
