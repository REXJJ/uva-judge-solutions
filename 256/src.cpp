#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> ans={{"00","01","81"},{"0000","0001","2025","3025","9801"},{"000000","000001","088209","494209","998001"},{"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"}};
int main()
{
	int n;
	while(cin>>n)
		copy(ans[(n-2)/2].begin(),ans[(n-2)/2].end(),ostream_iterator<string>(cout,"\n"));
	return 0;
}
