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

void color(int count,int node,unordered_map<int,vector<int>>& graph,vector<int>& scheme,vector<int>& global_scheme,int& max_node,int no_black)
{
	print(count,"---------------");
	if(count==0)
	{
		if(no_black>max_node)
		{
			max_node=no_black;
			global_scheme=scheme;
		}
		return;
	}
	bool black_possible=true;
	for(int i=0;i<graph[node].size();i++)
	{
		auto child=graph[node][i];
		if(scheme[child-1]==0)
		{
			black_possible=false;
			break;
		}
	}
	if(black_possible)
	{
		scheme[node-1]=0;
		color(count-1,node+1,graph,scheme,global_scheme,max_node,no_black+1);
	}
	scheme[node-1]=1;
	color(count-1,node+1,graph,scheme,global_scheme,max_node,no_black);
	scheme[node-1]=-1;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int nodes,edges;
		cin>>nodes>>edges;
		unordered_map<int,vector<int>> graph;
		for(int j=0,x,y;j<edges&&cin>>x>>y;j++,graph[x].push_back(y),graph[y].push_back(x));
		vector<int> scheme(nodes,-1);
		vector<int> global_scheme(nodes,-1);
		int max_node=-1;
		color(nodes,1,graph,scheme,global_scheme,max_node,0);
		cout<<max_node<<endl;
		vector<int> output;
		for(int i=0;i<global_scheme.size();i++)
			if(global_scheme[i]==0)
				output.push_back(i+1);
		for(int i=0;i<output.size();i++)
		{
			cout<<output[i];
			if(i!=output.size()-1)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
