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

constexpr double f(int p,int q,int r,int s,int t,int u,double x)
{
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

constexpr double fd(int p,int q,int r,int s,int t,int u,double x)
{ 
	return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;
}

double newton(int p,int q,int r,int s,int t,int u){
	if (f(p,q,r,s,t,u,0)==0) return 0;
	for (double x=0.5; ;){             
		double x1 = x - f(p,q,r,s,t,u,x)/fd(p,q,r,s,t,u,x);      
		if (fabs(x1-x) < epsilon) return x;  
		x = x1;
	}

}
int main()
{
	int p,q,r,s,t,u;
	while(cin>>p>>q>>r>>s>>t>>u)
	{
		if (f(p,q,r,s,t,u,0) * f(p,q,r,s,t,u,1) > 0)
			puts("No solution");
		 else 
			printf("%.4lf\n",newton(p,q,r,s,t,u));
	}
	return 0;
}
