#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,fx,fy;
char ch[5];
set<pair<int,int> >Q;
main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&x,&y);
	scanf("%s",&ch);
	fy=ch[1]=='R'?1:-1;
	fx=ch[0]=='D'?1:-1;
	int T=1000000;
	long long ans=1,h=m+n-2;
	if(x==1||x==n||y==1||y==m)Q.insert(make_pair(x,y));
	while(T --> 0){
		int di=min(fx==1?n-x:x-1,fy==1?m-y:y-1);
		x+=fx*di;y+=fy*di;ans+=di;
		fx=x==1?1:x==n?-1:fx;
		fy=y==1?1:y==m?-1:fy;
		Q.insert(make_pair(x,y));
		if(Q.size()==m+n-2)break;
		// cout<<x<<' '<<y<<' '<<fx<<' '<<fy<<endl;
		// cout<<Q.size()<<endl;
	}
	if(T==-1)puts("-1");
	else cout<<ans<<endl;
	return 0;
}
