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
	int c=0;
	while(cin>>n&&n)
	{
		vector<int> s;
		for(int i=0,x;i<n&&cin>>x;i++,s.push_back(x));
		int m;
		cin>>m;
		vector<int> a;
		for(int i=0;i<s.size();i++)
			for(int j=0;j<s.size();j++)
				if(i!=j)
					a.push_back(s[i]+s[j]);
		cout<<"Case "<<++c<<":"<<endl;
		for(int i=0;i<m;i++)
		{
			int x;
			cin>>x;
			int ans=*min_element(a.begin(),a.end(),[x](int a,int b){return abs(a-x)<abs(b-x);});
			cout<<"Closest sum to "<<x<<" is "<<ans<<"."<<endl;
		}
	}
	return 0;
}
