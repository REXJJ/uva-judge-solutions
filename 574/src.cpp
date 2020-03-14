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

struct VectorHash 
{
	size_t operator()(const std::vector<int>& v) const 
	{
		std::hash<int> hasher;
		size_t seed = 0;
		for (int i : v) 
			seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		return seed;				    
	}	
};

unordered_set<vector<int>,VectorHash> sols;

void get_ans(int id,vector<int>& list,vector<int>& ans,bool& status,int r)
{
	if(id==list.size()+1)
		return;
	int sum=accumulate(ans.begin(),ans.end(),0);
	if(sum==r)
	{
		vector<int> temp(ans.begin(),ans.end());
		sort(temp.begin(),temp.end(),greater<int>());
		if(sols.find(temp)!=sols.end())
			return;
		sols.insert(temp);
		for(int i=0;i<temp.size()-1;i++)
			cout<<temp[i]<<"+";
		cout<<temp[temp.size()-1]<<endl;
		status=true;
		return;
	}
	if(sum>r)
		return;
	for(int i=id;i<list.size();i++)
	{
		ans.push_back(list[i]);
		get_ans(i+1,list,ans,status,r);
		ans.pop_back();
	}
}

int main()
{
	while(true)
	{
		int s,n;
		cin>>s>>n;
		if(s==0&&n==0)
			break;
		vector<int> l;
		for(int i=0,a;i<n&&cin>>a;i++,l.push_back(a));
		sort(l.begin(),l.end(),greater<int>());
		vector<int> ans;
		bool status=false;
		cout<<"Sums of "<<s<<":"<<endl;
		sols.clear();
		get_ans(0,l,ans,status,s);
		if(!status)
			cout<<"NONE"<<endl;
	}
	return 0;
}
