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

void get_sol(vector<int>& game)
{
	int n=game.size()-6;
	if(n<0)
		return;
	for(int a=0;a<=n;a++)
	for(int b=a+1;b<=n+1;b++)
	for(int c=b+1;c<=n+2;c++)
	for(int d=c+1;d<=n+3;d++)
	for(int e=d+1;e<=n+4;e++)
	for(int f=e+1;f<=n+5;f++)
		cout<<game[a]<<" "<<game[b]<<" "<<game[c]<<" "<<game[d]<<" "<<game[e]<<" "<<game[f]<<"\n";
}

int main()
{
	bool status=false;
	while(true)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		if(n&&status)
			cout<<endl;
		vector<int> game;
		for(int i=0,x;i<n&&cin>>x;i++,game.push_back(x));
		get_sol(game);
		status=true;
	}
	return 0;
}
