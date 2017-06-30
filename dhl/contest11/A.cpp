#include<bits/stdc++.h>
using namespace std;
int n;
int a[100][100];

int solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]!=1)
		{
			int ok=0;
			for(int k1=1;k1<=n;k1++)
				for(int k2=1;k2<=n;k2++)
				//	if(k1!=i&&k2!=j)
					if(a[i][j]==a[i][k1]+a[k2][j])
							ok=1;
			if(!ok) {return 0;}
		}
		return 1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	cout<<(solve()?"Yes\n":"No\n");
	return 0;
}
