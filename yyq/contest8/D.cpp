#include<bits/stdc++.h>
using namespace std;
typedef  long long LL;
LL sum;
int n,m,kk;
LL calc(int num,LL sumx,int sx,int tx,LL sumy,int sy,int ty)
{
	if(num==2)
		return sumy;
	int dq=0;
	if(tx==1&&sy==1)
		dq++;
	return calc(num-1,sumy,sy,ty,sumx+sumy+dq,sx,ty);
}
void print(LL sumx,LL sx,LL tx,LL n)
{
	string ans;
	ans.resize(n);
	int i=0;
	if(sx==1)
		ans[i++]='C';
	if(tx==1)
		ans[--n]='A';
	while(sumx--)
		ans[i++]='A',ans[i++]='C';
	while(i<n)
		ans[i++]='Z';
	cout<<ans<<endl;
}
bool check(LL x,LL y,int sx,int tx,int sy,int ty)
{
	if(x*2+sx+tx>n)
		return false;
	if(y*2+sy+ty>m)
		return false;
	LL dq=calc(kk,x,sx,tx,y,sy,ty);
	if(dq==sum)
	{
		print(x,sx,tx,n);
		print(y,sy,ty,m);
		return true;
	}
	else
		return false;
}
int main()
{
	scanf("%d%I64d%d%d",&kk,&sum,&n,&m);
	for(int i=0;i*2<=n;++i)
		for(int j=0;j*2<=m;++j)
			for(int k=0;k<16;++k)
				if (check(i,j,k&1,(k>>1)&1,(k>>2)&1,(k>>3)&1))
					return 0;
	printf("Happy new year!\n");
	return 0;
}
