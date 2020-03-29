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
	string s;
	while(1)
	{
		vector<unordered_map<char,char>> p;
		while(cin>>s&&s[0]!='e')
		{
			if(s[0]=='#')
				return 0;
			stringstream ss(s);
			unordered_map<char,char> r;
			while(getline(ss,s,','))
				r[s[0]]=s[2];
			p.push_back(r);
		}
		int m=INT_MAX,ans=-1;
		string token="gyorb";
		for(int i=0;i<p.size();i++)
		{
			int dif=0;
			for(int j=0;j<p.size();j++)
			{
				if(i!=j)
				{
					for(auto x:token)
						if(p[i][x]!=p[j][x])
							dif++;

				}
			}
			if(dif<m)
			{
				m=dif;
				ans=i;
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
