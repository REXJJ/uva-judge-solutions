#include <bits/stdc++.h>

using namespace std;

void print(){}
template<typename T,typename... Args>
void print(T Contents, Args... args) 
{
#ifdef DBG
	std::cout<< (Contents) << std::endl;print(args...);
#endif
}

bool isSafe(vector<vector<int>>& board,int row, int col) 
{ 
	int n=board.size();
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (board[i][j]) 
			return false; 
	for (int i = row, j = col; j<n && i >=0; i--, j++) 
		if (board[i][j]) 
			return false; 
	return true;
}

int solution(vector<vector<int>>& board,int n,int k,int r,int c)
{
	if(k==0)
	{
		for(auto x:board)
		{
			for(auto y:x)
				cout<<y<<" ";
			cout<<endl;
		}
		cout<<"------------------------"<<endl;
		return 1;
	}
	int s=0;
	for(int i=r;i<n;i++)
		for(int j=c;j<n;j++)
			if(isSafe(board,i,j))
			{
				board[i][j]=1;
				s=s+solution(board,n,k-1,i,j);
				board[i][j]=0;
			}
	return s;
}

int solution2(vector<vector<int>>& board,int pos,int k)
{
	if(k==0)
		return 1;
	int n=board.size();
	if(pos==n*n)
		return 0;
	if(pos>n*n-k)
		return 0;
	int s=0,r=pos/n,c=pos%n;
	if(isSafe(board,r,c))
	{
		board[r][c]=1;
		s=s+solution2(board,pos+1,k-1);
		board[r][c]=0;
	}
	s=s+solution2(board,pos+1,k);
	return s;	
}

int main()
{
	int n,k;
	vector<int> sol;
	while(scanf("%d %d",&n,&k),(n||k))
	{
		vector<vector<int>> board(n,vector<int>(n,0));
		int ans=solution2(board,0,k);
		cout<<ans<<endl;
	}
	return 0;
}
