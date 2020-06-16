#include <bits/stdc++.h>

using namespace std;

long long int get_mx(vector<long long int> &p)
{
	vector<long long int> pp={1};
	for(long long int i=1;i<=p.size();i++)
	{
		pp.push_back(pp[i-1]*p[i-1]);
	}
	long long int mx=INT_MIN;
	for(long long int i=1;i<pp.size();i++)
	{
		for(long long int j=0;j<i;j++)
		{
			if(!pp[j])
				continue;
			auto loc = pp[i]/pp[j];
			if(loc>mx)
				mx=loc;
		}
	}
	return mx;
}

void compute(vector<vector<long long int>> &p)
{
	long long int mx=INT_MIN;
	for(auto x:p)
	{
		auto temp=get_mx(x);
		if(temp>mx)
			mx=temp;
	}
	cout<<mx<<endl;
}

int main()
{
	long long int n;
	vector<vector<long long int>> p;
	vector<long long int> pp;
	while(cin>>n)
	{
		if(n==-999999)
		{
			if(pp.size())
				p.push_back(pp);
			compute(p);
			p={};
			pp={};
			continue;
		}
		if(n==0)
		{
			pp.push_back(n);
			p.push_back(pp);
			pp={};
			continue;
		}
		pp.push_back(n);
	}
	return 0;
}
