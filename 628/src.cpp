#include <bits/stdc++.h>

using namespace std;


void process(vector<string>& dict, string& rules,int i,string word)
{
	if(i==rules.size())
	{
		cout<<word<<endl;
		return;
	}
	if(rules[i]=='#')
		for(auto x:dict)
			process(dict,rules,i+1,word+x);
	else
		for(int j=0;j<10;j++)
			process(dict,rules,i+1,word+to_string(j));
}

int main()
{
	int n,t;
	while(cin>>n)
	{
		vector<string> dict;
		for(int i=0;i<n;i++)
		{
			string d;
			cin>>d;
			dict.push_back(d);
		}
		cin>>t;
		vector<string> rules;
		for(int i=0;i<t;i++)
		{
			string d;
			cin>>d;
			rules.push_back(d);
		}
		string s="";
		cout<<"--"<<endl;
		for(auto x:rules)
			process(dict,x,0,s);
	}
	return 0;
}
