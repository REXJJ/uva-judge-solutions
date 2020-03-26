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
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
		int d;
		vector<tuple<string,int,int>> db;
		cin>>d;
		for(int i=0;i<d;i++)
		{
			string s;
			int l,u;
			cin>>s>>l>>u;
			db.push_back(make_tuple(s,l,u));
		}
		int qs;
		cin>>qs;
		for(int i=0;i<qs;i++)
		{
			int m;
			cin>>m;
			int count=0;
			string ans;
			for(auto x:db)
			{
				if(m>=get<1>(x)&&m<=get<2>(x))
				{
					ans=get<0>(x);
					count++;
				}
			}
			cout<<((count==1)?ans:"UNDETERMINED");
			cout<<endl;
		}
		if(tc!=t-1)
			cout<<endl;
	}
	return 0;
}
