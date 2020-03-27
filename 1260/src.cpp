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

int main()
{
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
		int n;
		cin>>n;
		vector<int> a;
		for(int i=0,x;i<n&&cin>>x;i++,a.push_back(x));
		int s=0;
		for(int i=1;i<n;i++)
			s=s+count_if(a.begin(),a.begin()+i,[a,i](int x){return x<=a[i];});
		cout<<s<<endl;
	}
	return 0;
}
