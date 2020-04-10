#include <iostream>
#include <utility>
#include <map>
#include <iterator>
#include <math.h>
#include <fstream>
using namespace std;
int round1(double a){a=a*10000;for(int i=0;i<4;i++){a=a/10;a=round(a);}return a;}
int main(){string st;int c=0;map<string,int> m;ofstream f;
f.open("example.txt");
while(1){
getline(cin,st);
if(st=="****END_OF_INPUT****")
break;
else{
if(st=="****END_OF_TEXT****"){f<<c<<" ";double sum=0.0,div;
for(map<string,int>::iterator i=m.begin();i!=m.end();i++)
{div=(i->second)*log10(c/(i->second));sum+=div;}
double sum1=sum/c;
sum/=c;sum=sum*10;sum=round(sum);sum/=10;
f<<sum<<" ";sum=sum1/(log10(c))*100;
f<<round(sum)<<endl;
c=0;m.clear();
continue;}
string s;char d[1000];int j=0;
for(string::iterator i=st.begin();i<=st.end();i++)
{
if(*i<=90&&*i>=65)
{d[j]=*i;j++;}
else if(*i<=122&&*i>=97)
{d[j]=*i-32;j++;}
else
{d[j]='\0';j=0;}
if(!j&&!d[0]=='\0')
{s=d;
map<string,int>::iterator j=m.find(s);
if(j==m.end()){m.insert({s,1});}
else {j->second++;}
c++;
}
}
}

}
return 0;}
