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

typedef pair<int,int> fraction;

bool operator<(fraction a,fraction b)
{
	if(a.second==0)
		return false;
	if(b.second==0)
		return true;
	double c=double(a.first)/double(a.second);
	double d=double(b.first)/double(b.second);
	return c-d<0.0000000000000000000000001;
}

fraction operator+(fraction a,fraction b)
{
	return make_pair(a.first+b.first,a.second+b.second);
}

ostream & operator <<(ostream &out, fraction a)
{
	out<<a.first<<" "<<a.second<<endl;
	return out;
}

string getAns(fraction p,fraction t,fraction q,fraction n)
{
	if(t==n)
		return "";
	if(t<n)
	{
		fraction b=t+q;
		return "R"+getAns(t,b,q,n);

	}
	fraction a=t+p;
	return "L"+getAns(p,a,t,n);
}

int main()
{
	int a,b;
	while(cin>>a>>b&&!(a==1&b==1))
	{
		fraction n=make_pair(a,b);
		fraction p=make_pair(0,1);
		fraction q=make_pair(1,0);
		fraction t=make_pair(1,1);
		string ans=getAns(p,t,q,n);
		cout<<ans<<endl;
	}
	return 0;
}
