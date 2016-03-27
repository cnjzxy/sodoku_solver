#include<cstdio>
#include<vector>

using namespace std;

int variables=9*9*9;

int clauses=0;
vector<int>clause[100000];

inline int get_idx(int x,int y,int num)
{
	return (x-1)*81+(y-1)*9+(num-1)+1;
}

int main()
{
	//for each grid
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			for(int k1=1;k1<9;k1++)
				for(int k2=k1+1;k2<=9;k2++)
				{
					clauses++;
					clause[clauses].push_back(-get_idx(i,j,k1));
					clause[clauses].push_back(-get_idx(i,j,k2));
					clause[clauses].push_back(0);
				}
			
			clauses++;
			for(int k=1;k<=9;k++)
				clause[clauses].push_back(get_idx(i,j,k));
			clause[clauses].push_back(0);
		}
	//for each grid
	
	//for each row
	for(int i=1;i<=9;i++)
		for(int k=1;k<=9;k++)
		{
			for(int j1=1;j1<9;j1++)
				for(int j2=j1+1;j2<=9;j2++)
				{
					clauses++;
					clause[clauses].push_back(-get_idx(i,j1,k));
					clause[clauses].push_back(-get_idx(i,j2,k));
					clause[clauses].push_back(0);
				}
		}
	//for each row
	
	//for each column
	for(int j=1;j<=9;j++)
		for(int k=1;k<=9;k++)
		{
			for(int i1=1;i1<9;i1++)
				for(int i2=i1+1;i2<=9;i2++)
				{
					clauses++;
					clause[clauses].push_back(-get_idx(i1,j,k));
					clause[clauses].push_back(-get_idx(i2,j,k));
					clause[clauses].push_back(0);
				}
		}
	//for each column
	
	//for each block
	for(int i=1;i<9;i+=3)	
		for(int j=1;j<9;j+=3)
			for(int k=1;k<=9;k++)
			{
				for(int g1=0;g1<8;g1++)
					for(int g2=g1+1;g2<9;g2++)
					{
						clauses++;
						clause[clauses].push_back(-get_idx(i+g1/3,j+g1%3,k));
						clause[clauses].push_back(-get_idx(i+g2/3,j+g2%3,k));
						clause[clauses].push_back(0);
					}
			}
	//for each block
	
	//read input
	for(int i=1;i<=9;i++)
	{
		char str[10];
		scanf("%s",str);
		for(int j=0;j<9;j++)
			if(str[j]!='0')
			{
				clauses++;
				clause[clauses].push_back(get_idx(i,j+1,str[j]-'0'));
				clause[clauses].push_back(0);
			}
	}
	//read input
	
	//print expression
	printf("p cnf %d %d",variables,clauses);
	for(int i=1;i<=clauses;i++)
	{
		for(vector<int>::iterator it=clause[i].begin();it!=clause[i].end();it++)
			if((*it)!=0)
				printf("%d ",*it);
		printf("0\n");
	}
	return 0;
}
