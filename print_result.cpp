#include<iostream>
#include<string>

using namespace std;

string str;
int temp;
int sudoku[10][10];

inline void read()
{
	cin>>str>>temp;
	
	while(temp)
	{
		if(temp>0)
		{
			temp--;
			
			int row=temp/81+1;
			int column=(temp%81)/9+1;
			int number=temp%9+1;
			sudoku[row][column]=number;
		}
		
		cin>>temp;
	}
}

inline void print()
{
	for(int row=1;row<=9;row++)
	{
		for(int column=1;column<=9;column++)
		{
			cout<<sudoku[row][column];

			if(column<9&&column%3==0)
				cout<<'|';
		}
		cout<<endl;

		if(row<9&&row%3==0)
			cout<<"---+---+---"<<endl;
	}
}

int main()
{
	read();
	
	print();
	
	return 0;
}
