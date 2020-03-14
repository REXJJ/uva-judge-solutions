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

bool solvable(vector<int>& bars,int n)
{
	for(int i=0;i<(1<<bars.size());i++)
	{
		int sum=0;
		for(int j=0;j<bars.size();j++)
		{
			if(i&(1<<j))
				sum+=bars[j];
			if(sum==n)
				return true;
		}
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,p;
		cin>>n>>p;
		vector<int> bars;
		for(int j=0,x;j<p&&cin>>x;j++,bars.push_back(x));
		cout<<(solvable(bars,n)?"YES":"NO");
		cout<<endl;
	}
	return 0;
}
