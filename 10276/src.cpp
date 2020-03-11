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

bool isquare(long double x) 
{   
	long double sr = sqrt(x); 
	return ((sr - floor(sr)) == 0); 
} 

void getall(vector<int>& v,int n,int& s)
{
	int i=0;
	if(n==INT_MAX)
	{
		s=-1;
		return;
	}
	for(;i<v.size();i++)
		if(v[i]==0||isquare(v[i]+n))
		{
			v[i]=n;
			s=s+1;
			break;
		}
	if(i==v.size())
		return ;
	getall(v,n+1,s);				
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n,0);
		int s=0;
		getall(v,1,s);
		cout<<s;
		cout<<endl;
	}
	return 0;
}
