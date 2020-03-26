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
	int a,b,c;
	int h[10000]={0};
	while(cin>>a>>b>>c)
	{
		for(int i=a;i<c;i++)
			if(h[i]<b)
				h[i]=b;
	}
	int prev=h[0];
	bool started=false;
	for(int i=0;i<10000;i++)
	{
		if(prev!=h[i])
		{
			if(started)
				cout<<" ";
			prev=h[i];
			cout<<i<<" "<<prev;
			started=true;
		}
	}
	cout<<endl;
	return 0;
}
