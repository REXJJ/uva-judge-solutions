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
	int n,t=0;
	while(cin>>n)
	{
		vector<int> v;
		for(int i=0,x;i<n&&cin>>x;i++,v.emplace_back(x));
		long long int k=0,m=0;
		for(;k<v.size();k++)
		{
			for(int i=0;i<v.size();i++)
			{
				long long int mm=1;
				for(int j=i;j<=i+k&&j<v.size();j++)
					mm*=v[j];
				if(mm>m)
					m=mm;
			}

		}
		printf("Case #%lld: The maximum product is %lld.\n\n",++t,m);
	}
	return 0;
}
