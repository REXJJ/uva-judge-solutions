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

int main()
{
	int n;
	vector<int> test;
	while(cin>>n&&n)
	{
		test.push_back(n);
	}
	vector<int> temp(test.begin(),test.end());
	sort(temp.begin(),temp.end());
	auto tt=unique(temp.begin(),temp.end());
	temp.resize(distance(temp.begin(),tt));
	unordered_map<int,vector<pair<string,string>>> ans;
	string s="0123456789";
	do
	{
		int a=stoi(string(s.begin(),s.begin()+5));
		int b=stoi(string(s.begin()+5,s.end()));
		for(auto x:temp)
		{
			if(a*x==b)
				ans[x].push_back(make_pair(string(s.begin()+5,s.end()),string(s.begin(),s.begin()+5)));	
		}
	}while(next_permutation(s.begin(),s.end()));
	for(int i=0;i<test.size();i++)
	{
		if(ans[test[i]].size()==0)
			cout<<"There are no solutions for "<<test[i]<<"."<<endl;
		for(auto x:ans[test[i]])
		{
			cout<<x.first<<" / "<<x.second<<" = "<<test[i]<<endl;
		}
		if(i!=test.size()-1)
			cout<<endl;
	}
	return 0;
}
