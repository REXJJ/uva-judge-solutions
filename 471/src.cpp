#include <bits/stdc++.h>

using namespace std;

bool repeated(unsigned long long int n)
{
	unsigned long long int a=0;
	while(n)
	{
		if(a&1<<(n%10))
			return false;
		a=a|1<<(n%10);
		n=n/10;
	}
	return true;
}


int main()
{
	unsigned long long int t;
	cin>>t;
	for(unsigned long long int tt=0;tt<t;tt++)
	{
		unsigned long long int n;
		cin>>n;
		for(unsigned long long int i=1;;i++)
		{
			if(!repeated(i))
				continue;
			unsigned long long int a=n*i;
			if(a>9876543210)
				break;
			if(repeated(a))
				cout<<a<<" / "<<i<<" = "<<n<<endl;
		}
		if(tt<t-1)
			cout<<endl;
	}
	return 0;
}
