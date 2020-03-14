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

unordered_set<int> prime={2,3,5,7,11,13,17,19,23,29,31};

void get_sol(int t,int n,vector<int>& ring,unordered_set<int>& in)
{
	if(t==0)
	{
		int i=0;
		for(;i<ring.size()-1;i++)
			if(prime.find(ring[i]+ring[i+1])==prime.end())
				break;
		if(i==ring.size()-1&&prime.find(ring[ring.size()-1]+ring[0])!=prime.end())
		{
			
			for(int j=0;j<ring.size()-1;j++)
				cout<<ring[j]<<" ";
			cout<<ring[ring.size()-1];
			cout<<endl;
		}
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(in.find(i)==in.end()&&prime.find(ring[ring.size()-1]+i)!=prime.end())
		{
			in.insert(i);
			ring.push_back(i);
			get_sol(t-1,n,ring,in);
			ring.pop_back();
			in.erase(i);
		}
	}
}

int main()
{
	int n,c=0;
	while(cin>>n)
	{
		if(c) cout<<endl;
		cout<<"Case "<<++c<<":"<<endl;
		vector<int> ring={1};
		unordered_set<int> in={1};
		get_sol(n-1,n,ring,in);
	}
	return 0;
}
