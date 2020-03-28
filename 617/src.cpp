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

bool possible(int sp,vector<tuple<float,int,int,int>> &p)
{
	for(auto x:p)
	{
		float d=get<0>(x);
		int g=get<1>(x),y=get<2>(x),r=get<3>(x);
		float t=(float(d)*3600.0/float(sp));
		t=fmod(t,(g+y+r));
		if(t>g+y)
			return false;
	}	
	return true;
}

int main()
{
	int n,cs=0;
	while(cin>>n&&n>-1)
	{
		vector<tuple<float,int,int,int>> s;
		float l;
		for(int i=0,r,g,b;i<n&&cin>>l>>r>>g>>b;i++,s.push_back(make_tuple(l,r,g,b)));
		int prev=30;
		cout<<"Case "<<++cs<<": ";
		vector<int> ans;
		for(int i=30;i<=60;i++)
			if(possible(i,s))
				ans.push_back(i);
		if(ans.size()==0)
			cout<<"No acceptable speeds.";
		else
		{
			vector<pair<int,int>> p;
			int prev=ans[0],now=ans[0];
			for(int i=1;i<ans.size();i++)
			{
				if(ans[i]==now+1)
				{
					now++;
					continue;
				}
				p.push_back(make_pair(prev,now));
				prev=ans[i];
				now=ans[i];
			}
			p.push_back(make_pair(prev,now));
			if(p.size()==0)
				cout<<prev<<endl;
			else
			{
				for(int i=0;i<p.size()-1;i++)
				{
					if(p[i].first!=p[i].second)
						cout<<p[i].first<<"-"<<p[i].second<<", ";
					else
						cout<<p[i].first<<", ";
				}
				if(p[p.size()-1].first!=p[p.size()-1].second)
					cout<<p[p.size()-1].first<<"-"<<p[p.size()-1].second;
				else
					cout<<p[p.size()-1].first;
			}

		}
		cout<<endl;
	}
	return 0;
}
