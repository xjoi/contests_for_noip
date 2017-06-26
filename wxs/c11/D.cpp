#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],d[10005],m,n,k,inq[10005],z[10005],t[10005];
int main(){
	memset(d,0x7f,sizeof d);
	int flag=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",a+i,b+i);
		z[a[i]]=1;t[b[i]]=1;
		if(a[i]==n&&b[i]==m)flag=i;
	}
	if(!flag){
		++k;
		a[k]=n;b[k]=m;
	}
	queue<int> Q;
	for(int i=1;i<=k;i++){
		if(a[i]==1&&b[i]==1)Q.push(i),d[i]=0;
	}
	while(!Q.empty()){
		int x=Q.front();Q.pop();inq[x]=0;
//		cout<<x<<' '<<d[x]<<endl;
		for(int i=1;i<=k;i++){
			if(x!=i&&(abs(a[i]-a[x])<3||abs(b[i]-b[x])<3)){
				int fff;
				if(!flag&&i==k){
					if(!(abs(a[i]-a[x])<2||abs(b[i]-b[x])<2))continue;
				}
				if((a[i]==a[x]&&abs(b[i]-b[x])<2||abs(a[i]-a[x])<2&&b[i]==b[x])||!flag&&i==k)fff=d[x];
				else fff=d[x]+1;
				if(fff<d[i]){
					d[i]=fff;
					if(!inq[i])inq[i]=1,Q.push(i);
				}
			}
		}
	}
	if(flag==0&&d[k]==0x7f7f7f7f||flag&&d[flag]==0x7f7f7f7f)puts("-1");
	else printf("%d",d[k]+(flag?0:1));
	return 0;
}
