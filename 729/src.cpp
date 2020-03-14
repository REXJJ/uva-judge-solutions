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

void hamm(int n,int h,vector<int>& num)
{
	if(n==0)
	{
		if(h) return;
		for(auto x:num)
			cout<<x;
		cout<<endl;
		return;
	}
	num.push_back(0);
	hamm(n-1,h,num);
	num.pop_back();
	if(h>0)
	{	
		num.push_back(1);
		hamm(n-1,h-1,num);
		num.pop_back();
	}
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,h;
		cin>>n>>h;
		vector<int> num;
		hamm(n,h,num);
		if(i<t-1)
			cout<<endl;
	}
	return 0;
}
