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

bool isRound(string s)
{
	int a[10]={0};
	int i=0,c=0;
	while(1)
	{
		char x=s[i];
		if(a[x-'0']==1)
			return false;
		a[x-'0']=1;
		i=(i+(x-'0'))%s.size();
		c++;
		if(i==0&&c==s.size()) 
			break;
	}
	return true;
}

int main()
{
	string s;
	int c=0;
	for(int i=1;i<INT_MAX;i++)
		if(isRound(to_string(i)))
		{
			cout<<i<<endl;
		}
	return 0;
}
