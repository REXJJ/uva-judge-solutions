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

void find_path(vector<vector<char>>& maze,int r,int c,vector<int>& path,int n,bool& f)
{
	string code="@IEHOVA#";
	print("Number: ",n);
	if(code[n]=='#')
	{
		print("Nearly Reached: ",maze[r][c]);
		if(maze[r][c]=='#')
		{
			f=true;
			return;
		}
		return;
	}
	print("Now: ",code[n]);
	print("Maze: ",maze[r][c]);
	if(code[n]!=maze[r][c])
		return;
	if(f==false&&r-1>=0)
	{
		path.push_back(0);
		find_path(maze,r-1,c,path,n+1,f);
		if(!f)
			path.pop_back();
	}
	if(f==false&&c-1>=0)
	{
		path.push_back(1);
		find_path(maze,r,c-1,path,n+1,f);
		if(!f)
			path.pop_back();
	}
	if(f==false&&c+1<maze[0].size())
	{
		path.push_back(2);
		find_path(maze,r,c+1,path,n+1,f);
		if(!f)
			path.pop_back();
	}
}

int main()
{
	int n,a,b;
	cin>>n;
	for(int ii=0;ii<n;ii++)
	{
		cin>>a>>b;
		print(a,b);
		vector<vector<char>> maze;
		for(int i=0;i<a;i++)
		{
			vector<char> temp;
			char ch;
			for(int j=0,c;j<b;j++)
			{
				cin>>ch;
				temp.push_back(ch);
			}
			maze.push_back(temp);
		}
		int row,col;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if(maze[i][j]=='@')
				{
					row=i;
					col=j;
					break;
				}
		print(row,col);		
		vector<int> path;
		bool found=false;
		find_path(maze,row,col,path,0,found);
		for(int i=0;i<path.size();i++)
		{
			int x=path[i];
			if(x==0)
				cout<<"forth";
			else if(x==1)
				cout<<"left";
			else 
				cout<<"right";
			if(i!=path.size()-1)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
