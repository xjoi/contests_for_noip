#include<cstdio>
#include<cstring>
#define N 210
#define P 1000000007
using namespace std;
int fat[N],sz[N],in[N],gro;
bool used[N][N],flag=0,is_cir;
int father(int x) {if(fat[x]!=x) fat[x]=father(fat[x]); return fat[x];}
int main()
{
	int n,m,tmp,i;
	scanf("%d %d",&n,&m); gro=n;
	if(n==2) {puts("1"); return 0;}
	for(i=1;i<=n;i++) sz[i]=1,fat[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&tmp);
		if(used[tmp][i]) continue;
		used[tmp][i]=used[i][tmp]=1;
		in[i]+=1; in[tmp]+=1;
		int fx=father(tmp),fy=father(i);
		if(fx!=fy)
		{
			fat[fx]=fy; 
			sz[fy]+=sz[fx]; sz[fx]=0;
			gro--;
		}
		else is_cir=1;
	}
	for(i=1;i<=n;i++) if(in[i]>2) {flag=1; break;}
	if(flag || (is_cir&&gro>1)) {puts("0"); return 0;}
	long long ans=1;
	for(i=1;i<gro;i++) ans=(ans*i)%P;
	for(i=1;i<=n;i++) if(sz[i]>1) ans=(ans<<1)%P;
	printf("%I64d\n",ans);
	return 0;
}
