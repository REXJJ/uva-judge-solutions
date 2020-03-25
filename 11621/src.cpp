#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		unsigned long long int a=ceil(log2(n));
		vector<unsigned long long int> powers;
		for(unsigned long long int i=0;i<=a;i++)
			for(unsigned long long int j=0;j<=a;j++)
				if(i+j<=a)
					powers.push_back(pow(2,i)*pow(3,j));
		vector<unsigned long long int> filtered;
		copy_if(powers.begin(),powers.end(),back_inserter(filtered),[n](unsigned long long int a){return a>=n;});
		cout<<*min_element(filtered.begin(),filtered.end())<<endl;
	}
	return 0;
}
