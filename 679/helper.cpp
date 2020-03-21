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
	vector<int> init={2,3};
	for(int j=0;j<19;j++)
	{
		cout<<"{";
		for(int i=0;i<init.size();i++)
		{
			cout<<init[i];
			if(i<init.size()-1)
				cout<<",";
		}
		cout<<"}"<<endl;
		vector<int> temp;
		for(auto x:init)
			temp.push_back(2*x);
		for(auto x:init)
			temp.push_back(2*x+1);
		init=temp;
	}
	
	return 0;
}
