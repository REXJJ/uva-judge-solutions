#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  string s;
  while(getline(cin,s)&&s!="#")
  {
    (next_permutation(s.begin(),s.end()))?cout<<s<<endl:cout<<"No Successor"<<endl;
  }
  return 0;
}
