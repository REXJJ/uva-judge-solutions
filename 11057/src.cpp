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
	int n;
	while(cin>>n)
	{
		unordered_set<int> looked;
		vector<int> books;
		vector<pair<int,int>> solutions;
		for(int i=0,x;i<n&&cin>>x;i++,books.emplace_back(x));
		int s;
		cin>>s;
		sort(books.begin(),books.end());
		for(int i=0;i<books.size();i++)
		{
			if(looked.find(books[i])==looked.end())
			{
				auto x = lower_bound(books.begin(),books.end(),s-books[i]);
				if(x!=books.end()&&(*x==(s-books[i]))&&x!=books.begin()+i)
				{
					looked.insert({books[i],*x});
					solutions.push_back(make_pair(books[i],*x));
				}

			}
		}
		auto sol = max_element(solutions.begin(),solutions.end(),[](pair<int,int> a,pair<int,int> b){return (a.first-a.second)<(b.first-b.second);});
		printf("Peter should buy books whose prices are %d and %d.\n\n",sol->first,sol->second);
	}
	return 0;
}
