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
	vector<vector<int>> helper;
	vector<int> init={2,3};
	for(int j=0;j<19;j++)
	{
		helper.push_back(init);
		vector<int> temp;
		for(auto x:init)
			temp.push_back(2*x);
		for(auto x:init)
			temp.push_back(2*x+1);
		init=temp;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<helper[a-2][b-1]<<endl;
	}
	
	return 0;
}
