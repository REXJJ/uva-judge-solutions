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
	int n;
	while(cin>>n&&n)
	{
		int mx=0,mxx=INT_MIN;
		for(int i=0,x;i<n&&cin>>x;i++)
		{
			mx=max(x,mx+x);
			if(max(mx,mxx)>mxx)
				mxx=mx;
		}
		if(mxx>0)
			cout<<"The maximum winning streak is "<<mxx<<"."<<endl;
		else
			cout<<"Losing streak."<<endl;
	}
	return 0;
}
