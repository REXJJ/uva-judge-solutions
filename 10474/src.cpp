#include <bits/stdc++.h>
#include <stdio.h>
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
	int n,q,c=0;
	while(scanf("%d%d",&n,&q),n&&q)
	{
		vector<int> marbles,queries;
		for(int i=0,x;i<n&&cin>>x;i++,marbles.push_back(x));
		for(int i=0,x;i<q&&cin>>x;i++,queries.push_back(x));
		printf("CASE# %d:\n",++c);
		sort(marbles.begin(),marbles.end());
		for(auto x:queries)
		{
			auto pos=lower_bound(marbles.begin(),marbles.end(),x);
			if(pos!=marbles.cend())
				if(*pos==x)
					cout<<x<<" found at "<<(pos-marbles.begin()+1)<<endl;
				else
					printf("%d not found\n",x);
			else
				printf("%d not found\n",x);
		}
	}
	return 0;
}
