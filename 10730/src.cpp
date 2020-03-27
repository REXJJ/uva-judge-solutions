#include <bits/stdc++.h>

using namespace std;

bool correct(vector<int>& v)
{
	for(int i=0;i<v.size();i++)
	{
		int n=v.size();
		int a[n]={0};
		for(int k=0;k<=i;k++)
			a[v[k]]=1;
		for(int j=i+1;j<v.size();j++)
		{
			int e=2*v[j]-v[i];
			a[v[j]]=1;
			if(e>=0&&e<n) 
				if(a[e]==0)
					return false;
		}

	}
	return true;
}

int main()
{
	int n;
	while(cin>>n&&n)
	{
		char xxx;
		cin>>xxx;
		vector<int> v;
		for(int i=0,x;i<n&&cin>>x;i++,v.push_back(x));
		if(correct(v))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
