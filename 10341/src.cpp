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

const double epsilon=1e-08;

constexpr double  eval(int p,int q,int r,int s,int t,int u,double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double binarySearch(int p,int q,int r,int s,int t,int u,double a,double b)
{
	double mid=(a+b)/2.0;
	double y=eval(p,q,r,s,t,u,mid);
	if(eval(p,q,r,s,t,u,a)*eval(p,q,r,s,t,u,b)>0)
		return 1000;
	if(fabs(y)<=epsilon)
		return mid;
	if(a>=b)
		return 1000;
	if(y>0)
		return binarySearch(p,q,r,s,t,u,mid,b);
	return binarySearch(p,q,r,s,t,u,a,mid);
}

int main()
{
	int p,q,r,s,t,u;
	while(cin>>p>>q>>r>>s>>t>>u)
	{
		double ans=binarySearch(p,q,r,s,t,u,0,1);
		if(ans==1000)
			cout<<"No solution";
		else
			printf("%.4f",ans);  
		cout<<endl;
	}
	return 0;
}
