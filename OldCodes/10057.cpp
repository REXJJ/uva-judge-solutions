#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;

  while(cin>>n)
  {
    vector<int> b;
    int ans1,ans2,median1,median2;
    for(int i=0;i<n;i++)
    {
      int a;
      cin>>a;
      b.push_back(a);
    }
    sort(b.begin(),b.end());
    ans1=0;
    if(n%2==0)
    {
      median1=b[(n-1)/2];
      median2=b[(n/2)];
      ans2=(median2-median1)+1;
      for(int j=0;j<n;j++)
      if(b[j]==median1||b[j]==median2)
      ans1++;
    }
    else
    {
      median1=b[n/2];
      ans2=1;
      for(int j=0;j<n;j++)
      if(b[j]==median1)
      ans1++;
    }



    cout<<median1<<" "<<ans1<<" "<<ans2<<endl;
  }
  return 0;
}
