#include <bits/stdc++.h>

using namespace std;

int counter=0;

vector<unsigned long long int> v;

void boardPrinter(vector<vector<int>>& board)
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			if(board[i][j])
				cout<<"1 ";
			else
				cout<<"0 ";
		cout<<endl;
	}
}

void numberPrinter(unsigned long long int b)
{
	unsigned long long int f=1;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			unsigned long long t=(f<<(i*8+j));
			if(b&t)
				cout<<"1 ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
}
bool isSafe(vector<vector<int>>& board,int row, int col) 
{ 
	for(int i=0;i<row;i++)
		if(board[i][col])
			return false;
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (board[i][j]) 
			return false; 
	for (int i = row, j = col; j<8 && i >=0; i--, j++) 
		if (board[i][j]) 
			return false; 
	return true;
}
void helper(vector<vector<int>>& board,int row)
{
	if(row==8)
	{
		unsigned long long int b=0,f=1;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				if(board[i][j])
					b=b|f<<(8*i+j);
		cout<<b<<endl;	
		boardPrinter(board);
		cout<<"-------------------"<<endl;
		numberPrinter(b);
		cout<<"-------------------"<<endl;
		cout<<"-------------------"<<endl;
		v.push_back(b);
		counter++;
		return;
	}
	for(int j=0;j<8;j++)
	{
		if(isSafe(board,row,j))
		{
			board[row][j]=1;
			helper(board,row+1);
			board[row][j]=0;
		}
	}
}

int main()
{
	vector<vector<int>> board(8,vector<int>(8,0));
	helper(board,0);
	cout<<counter<<endl;
	cout<<"{";
	for(auto x:v)
		cout<<x<<",";
	cout<<"}"<<endl;
	return 0;
}
