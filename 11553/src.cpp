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

int solve(vector<vector<int>>& m)
{
	int n=m.size();
	vector<int> perm(n);
	iota(perm.begin(),perm.end(),0);
	int minimum=INT_MAX;
	do
	{
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=m[i][perm[i]];
		if(sum<minimum)
			minimum=sum;

	}while(next_permutation(perm.begin(),perm.end()));
	return minimum;
}

int main()
{
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{
		int n;
		vector<vector<int>> m;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			vector<int> temp;
			for(int j=0,x;j<n&&cin>>x;j++,temp.push_back(x));
			m.push_back(temp);
		}
		cout<<solve(m)<<endl;
	}
	return 0;
}
