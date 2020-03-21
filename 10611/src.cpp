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

int main() {

	int n,q;
	cin>>n;
	vector<int> monkeys;
	for(int i=0,x;i<n&&cin>>x;i++,monkeys.push_back(x));
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int m;
		cin>>m;
		auto left=lower_bound(monkeys.begin(),monkeys.end(),m);
		auto right=upper_bound(monkeys.begin(),monkeys.end(),m);
		int high=right-monkeys.begin();
		int low=left-1-monkeys.begin();
		if(left-1==monkeys.end()||low<0)
			printf("X %d\n",monkeys[high]);
		else if(right==monkeys.end())
			printf("%d X\n",monkeys[low]);
		else 
			printf("%d %d\n",monkeys[low],monkeys[high]);
		

	}
	return 0;
}
