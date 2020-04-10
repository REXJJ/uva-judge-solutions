#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n,c=0;
  vector<int> a;

  while(cin>>n)
  {
    a.push_back(n);
    sort(a.begin(),a.end());
    c++;
    (c%2==0)?cout<<(a[(c-1)/2]+a[c/2])/2<<endl:cout<<a[c/2]<<endl;

  }
  return 0;
}
