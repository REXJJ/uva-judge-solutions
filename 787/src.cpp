#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

void compute(vector<long long int> &p)
{
    if(p.size()==0)
    {
        std::cout<<0<<std::endl;
        return;
    }
    long long int mx = p[0];
    vector<ll> dp = {p[0]};
    for(ll i=1;i<p.size();i++)
    {
        dp.push_back(dp[i-1]*p[i]);
    }
    for(ll i=0;i<p.size();i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(dp[j]==0)
                continue;
            auto x = dp[i]/dp[j];
            mx = max(mx,x);
        }
    }
    std::cout<<mx<<std::endl;
}

int main()
{
	long long int n;
	vector<long long int> p;
	while(cin>>n)
	{
		if(n==-999999)
		{
			compute(p);
			p={};
			continue;
		}
        p.push_back(n);
	}
	return 0;
}
