#include <bits/stdc++.h>

using namespace std;

void recurse(vector<int>& v,int m,long long int& mx,long long int sm,int s,int d)
{
	if(m>=5)
	{
		if(accumulate(v.begin()+m-5,v.begin()+m,0)>=0)
			return;
	}
	if(m==12)
	{
		if(sm>mx)
			mx=sm;
		return;
	}
	v[m]=s;
	recurse(v,m+1,mx,sm+s,s,d);
	v[m]=-d;
	recurse(v,m+1,mx,sm-d,s,d);
	v[m]=0;
}


int main()
{
	int s,d;
	while(cin>>s>>d)
	{
		vector<int> v(12,0);
		long long int m =-10;
		recurse(v,0,m,0,s,d);
		if(m>=0)
			cout<<m<<endl;
		else
			cout<<"Deficit"<<endl;
	}
	return 0;
}
