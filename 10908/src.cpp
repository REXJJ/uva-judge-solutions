#include <bits/stdc++.h>

using namespace std;

void print(){}
template<typename T,typename... Args>
void print(T Contents, Args... args) 
{
#ifdef DBG
	std::cout<< (Contents) << std::endl;print(args...);
#endif
}

int main()
{
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
		int m,n,q;
		cin>>m>>n>>q;
		vector<string> sq;
		for(int i=0;i<m;i++)
		{
			string s;
			cin>>s;
			sq.push_back(s);
		}
		cout<<m<<" "<<n<<" "<<q<<endl;
		for(int i=0,x,y;i<q&&cin>>x>>y;i++)
		{
			int j=2;
			for(;;j++)
			{
				int a=x-j/2,b=y-j/2;
				if(a<0||b<0||x+j/2>=m||y+j/2>=n)
					break;
				for(int k=a;k<=x+j/2;k++)
					for(int l=b;l<=y+j/2;l++)
						if(sq[k][l]!=sq[x][y])
							goto last;
			}
last:
			cout<<j-1<<endl;
		}

	}
	return 0;
}
