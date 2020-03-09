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

unordered_map<int,vector<int>> get_map(vector<vector<int>>& adj)
{
	unordered_map<int,vector<int>> m;
	for(int i=0;i<adj.size();i++)
		for(int j=0;j<adj.size();j++)
			if(adj[i][j])
				m[i].push_back(j);
	return m;
}

void get_paths(int node,unordered_map<int,vector<int>>& m,int n,vector<vector<int>>& p,vector<int>& lp,unordered_set<int>& v)
{
	if(v.find(node)!=v.end())
		return;
	if(n==0)
	{
		lp.push_back(node);
		p.push_back(lp);
		lp.pop_back();
		return;
	}
	v.insert(node);
	lp.push_back(node);
	for(auto x:m[node])
		get_paths(x,m,n-1,p,lp,v);
	lp.pop_back();
	v.erase(node);
}

int main()
{
	int n,p;
	while(cin>>n>>p)
	{
		vector<vector<int>> adj;
		for(int i=0;i<n;i++)
		{
			vector<int> temp;
			for(int j=0,k;j<n&&cin>>k;j++)
				temp.push_back(k);
			adj.push_back(temp);
		}
		unordered_map<int,vector<int>> mp=get_map(adj);
		vector<vector<int>> paths;
		unordered_set<int> visited;
		vector<int> local_path;
		get_paths(0,mp,p,paths,local_path,visited);
		if(paths.size()==0||paths[0].size()==0)
			cout<<"no walk of length "<<p<<endl;
		for(auto x:paths)
		{
			cout<<"(";
			for(int i=0;i<x.size()&&cout<<x[i]+1;i++)
				if(i<x.size()-1)
					cout<<",";
			cout<<")\n";
		}
		if(int dump=1&&cin>>dump)
			cout<<"\n";
	}
	return 0;
}
