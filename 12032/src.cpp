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

bool simulate(vector<int>& ladder,int k)
{
	if(k<ladder[0])
		return false;
	if(k==ladder[0])
		k--;
	for(int i=0;i<ladder.size()-1;i++)
	{
		int x=ladder[i+1]-ladder[i];
		if(k<x)
			return false;
		if(x==k)
			k--;
	}
	return true;
}

int getK(vector<int>& ladder)
{
	int start=0,end=ladder[ladder.size()-1];
	int k=end;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(simulate(ladder,mid))
		{
			if(mid<k)
				k=mid;
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	return k;
}

int main()
{
	int t;
	cin>>t;
	for(int test_cases=0;test_cases<t;test_cases++)
	{
		int n;
		cin>>n;
		vector<int> ladder;
		for(int i=0,x;i<n&&cin>>x;i++,ladder.push_back(x));
		cout<<"Case "<<test_cases+1<<": "<<getK(ladder);
		cout<<endl;
	}
	return 0;
}
