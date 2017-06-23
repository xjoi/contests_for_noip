#include<bits/stdc++.h>
using namespace std;
int n,k,x; 
vector<int> v[800000];
int ans=0,point=-9;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x;
		int ok=0;
		int sum=0;
		int p=-9;
		for(int j=0;j<x;j++)
		{
			int t1;cin>>t1;
			v[i].push_back(t1);
			if(t1==1) ok=1;
			if(ok==1) if(j!=0&&v[i][j]-v[i][j-1]>1) ok=0;
			if(!ok&&j!=0) sum++;
			if(ok==1) p=t1;
			//if(ok==0&&point==-9&&j!=0) point=v[i][j-1];
		}
		if(point==-9&&p!=-9) point=p;
		if(sum!=0)
			ans+=sum;
	}
//	cout<<point<<endl;
	if(point==-9) ans+=n-1;
	else 
		ans+=n-point;
	cout<<ans<<endl;
	return 0;
}
