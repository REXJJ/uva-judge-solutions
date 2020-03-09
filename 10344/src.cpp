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

bool find_c(vector<int>& v,int i,int s)
{
	if(i==v.size())
	{
		if(s==23)
			return true;
		return false;
	}
	return find_c(v,i+1,s+v[i])|| find_c(v,i+1,s-v[i])|| find_c(v,i+1,s*v[i]);
}
	

int main()
{
	while(true)
	{
		vector<int> v;
		for(int i=0,a;i<5&&cin>>a;i++)
			v.push_back(a);
		if(accumulate(v.begin(),v.end(),0)==0)
			break;
		sort(v.begin(),v.end());
		bool f=false;
		do
		{
			if(find_c(v,1,v[0]))
			{
				f=true;
				break;
			}
		}while(next_permutation(v.begin(),v.end()));
		if(f)	
			cout<<"Possible";
		else
			cout<<"Impossible";
		if(accumulate(v.begin(),v.end(),0)!=0)
			cout<<endl;
	}
	return 0;
}
