#include <bits/stdc++.h>

using namespace std;

void print(){std::cout<<endl;}
template<typename T,typename... Args>
void print(T Contents, Args... args) 
{
#ifdef DBG
	std::cout<< (Contents) <<" ";print(args...);
#endif
}

vector<vector<int>> mat;
int N,M;

pair<int,int>  summer(int i,int ii,int j,int jj)
{
	int ones=0,zeros=0;
	for(int s=i;s<ii;s++)
		for(int t=j;t<jj;t++)
		{
			ones+=mat[s][t]==1;
			zeros+=mat[s][t]==0;
		}
	return {ones,zeros};
}

string ans="";

int unprocess(string& s,int id,int i,int ii,int j,int jj)
{
	if(i<0||j<0||ii>N||jj>M||i>ii||j>jj||i>=N||j>=M||i==ii||j==jj)
		return id-1;
	if(id>=s.size())
		return id;
	if(s[id]!='D')
	{
		for(int ss=i;ss<ii;ss++)
			for(int t=j;t<jj;t++)
				mat[ss][t]=int(s[id]-'0');
		return id;
	}
	int midi=i+ceil(float(ii-i)/2.0),midj=j+ceil(float(jj-j)/2.0);
	id=unprocess(s,id+1,i,midi,j,midj);
	id=unprocess(s,id+1,i,midi,midj,jj);
	id=unprocess(s,id+1,midi,ii,j,midj);
	id=unprocess(s,id+1,midi,ii,midj,jj);
	return id;
}

void printAns()
{
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if((i+1)%50==0)
			cout<<endl;
	}
}
void process(int i,int ii,int j,int jj)
{
	if(i<0||j<0||ii>N||jj>M||i>ii||j>jj||i>=N||j>=M)
		return;
	if(i==ii||j==jj)
		return;
	pair<int,int> t = summer(i,ii,j,jj);
	if(t.first==0)
	{
		ans=ans+"0";
		return;
	}
	else if(t.second==0)
	{
		ans=ans+"1";
		return;
	}
	else
	{
		ans=ans+"D";
		int midi=i+ceil(float(ii-i)/2.0),midj=j+ceil(float(jj-j)/2.0);
		process(i,midi,j,midj);
		process(i,midi,midj,jj);
		process(midi,ii,j,midj);
		process(midi,ii,midj,jj);
	}
}

char compli(char x)
{
	if(x=='B')
		return 'D';
	return 'B';
}

int main()
{
	char m;
	while(cin>>m&&m!='#')
	{
		cin>>N>>M;
		mat=vector<vector<int>>(N,vector<int>(M,0));
		cout<<compli(m)<<right<<setw(4)<<N<<right<<setw(4)<<M<<endl;
		if(m=='B')
		{
			string s="";
			do
			{
				string temp;
				cin>>temp;
				s=s+temp;;
			}while(s.size()<N*M);

			int count=0;
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
					mat[i][j]=int(s[count++]-'0');
			process(0,N,0,M);
			printAns();
			cout<<endl;

		}
		else
		{
			string s;
			cin>>s;
			auto t=unprocess(s,0,0,N,0,M);
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)
					ans+=to_string(mat[i][j]);
			}
			printAns();
			if(ans.size()%50!=0)
				cout<<endl;
		}
		ans="";
	}
	return 0;
}
