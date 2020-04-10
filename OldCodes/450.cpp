#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct person
{
  string qua[8];
};

bool pcompare(person a, person b) { return a.qua[3]< b.qua[3]; }

int main()
{
  vector<person> a;
  int t;
  string s;
  cin>>t;
  getchar();
  while(t--)
  {
    string dep;
    getline(cin,dep);
    while(getline(cin,s)&&s.size())
    {
      person p;
      p.qua[0]=dep;
      string word="";
      int z=1;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]!=',')
        word+=s[i];
        if(s[i]==',')
        {
          p.qua[z]=word;
          z++;
          word="";
        }
      }
      if(z==7){p.qua[7]=word;
      a.push_back(p);}
    }

  }


sort(a.begin(),a.end(),pcompare);

for(auto x:a){
cout<<"----------------------------------------"<<endl;
cout<<x.qua[1]+" "<<x.qua[2]+" "+x.qua[3]<<endl;
cout<<x.qua[4]<<endl;
cout<<"Department: "<<x.qua[0]<<endl;
cout<<"Home Phone: "<<x.qua[5]<<endl;
cout<<"Work Phone: "<<x.qua[6]<<endl;
cout<<"Campus Box: "<<x.qua[7]<<endl;
}

  return 0;
}
