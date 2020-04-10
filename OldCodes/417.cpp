//UVA 417
#include <iostream>
using namespace std;
int A[50][50];
int main()
{
string s;A[0][0]=1;
for(int i=1;i<27;i++)
for(int j=0;j<i+1;j++)
(j==0||j==i)?A[i][j]=1:A[i][j]=A[i-1][j]+A[i-1][j-1];
while(getline(cin,s))
{int i;
for(i=0;i<s.size()-1;i++)
if(s[i]>=s[i+1])
{cout<<"0\n";break;}
if(i!=s.size()-1)
continue;
int sum=1;
while(i){sum=sum+A[26][i];i--;}
int l=s.size();char c='a';
while(i<l){int t='z'-c;
while(c<s[i]){sum=sum+A[t][l-i-1];c++;t--;}
c++;i++;}
cout<<sum<<endl;
}
return 0;
}
