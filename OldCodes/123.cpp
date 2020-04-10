#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
inline bool caseInsCharCompareN(char a, char b) {
     return(toupper(a) == toupper(b));
  }


  bool caseInsCompare(const string& s1, const string& s2) {
     return((s1.size() == s2.size()) &&
            equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
 }
vector<string> toArray(string z)
{
  vector<string> str;
  string st="";
  for(int i=0;i<z.length();i++)
  {

    if(z[i]!=' ')
    st=st+z[i];
    if(z[i]==' '||i==z.length()-1)
    {
      str.push_back(st);
      st="";
    }

  }
return str;
}
int main()
{
  string s;
  vector<string> st1,st2;
  set<string> st3;
  int t=0;
  while(getline(cin,s))
  {
    if(s=="::"){
    t=1;
    continue;
  }
    (t)?st2.push_back(s):st1.push_back(s);
  }
  for(auto z:st2)
  {
    vector<string> str = toArray(z);

        for(auto x:str)
    {
    int status=0;
    transform(x.begin(), x.end(), x.begin(), ::toupper);
    for(auto y:st1){
    transform(y.begin(), y.end(), y.begin(), ::toupper);
    if(x==y)
    status=1;}
    if(!status)
    st3.insert(x);
  }
  }
  vector<string> st4;
  for(auto x:st3)
  st4.push_back(x);
  sort(st4.begin(),st4.end());
  for(auto x:st4){
  for(auto y:st2)
  {
    vector<string> str=toArray(y);
    for(auto z:str)
    {
      string c=z;
      transform(c.begin(),c.end(),c.begin(),::toupper);
      if(c==x)
      {
      string yy=y;
      string sss="";
      for(int i=0;i<yy.length();i++)
      {
        if(yy[i]!=' ')
        sss+=yy[i];
        if(yy[i]==' '||i==yy.length()-1)
        {
          if(caseInsCompare(sss,x)){
          transform(sss.begin(),sss.end(),sss.begin(),::toupper);}
          else
          transform(sss.begin(),sss.end(),sss.begin(),::tolower);
        cout<<sss;
        (i==yy.length()-1)?cout<<endl:cout<<" ";
        sss="";
        }
      }

      }

    }
  }
}
  //cout<<x<<endl;
  return 0;
}
