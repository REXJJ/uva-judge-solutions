#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long int t;
	cin>>t;
	for(unsigned long long int tc=0;tc<t;tc++)
	{
		unsigned long long int d;
		cin>>d;
		vector<unsigned long long int> p;
		for(unsigned long long int i=0,x;i<=d&&cin>>x;i++,p.emplace_back(x));
		unsigned long long int f,k;
		cin>>f>>k;
		unsigned long long int s=0,n=ceil((sqrt(1+ceil(double(2*k)/double(f))*4)-1)/2);
		for(unsigned long long int i=0;i<=d;i++)
			s=s+p[i]*pow(n,i);
		cout<<s<<endl;
	}
	return 0;
}
