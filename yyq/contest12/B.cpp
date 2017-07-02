#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int vis[105][105];
int father[105];
int d[105],s[105];
ll ans;
int find(int x)
{
    return father[x]==x?x:father[x]=find(father[x]);
}
int main()
{
    int n,m,i,j,k,x;
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        s[i]=1;
        d[i]=0;
    }
    int sum=n,flag=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        if(vis[i][x]||vis[x][i])
			continue;
        vis[i][x]=vis[x][i]=1;
        d[i]++;
        d[x]++;
        if(find(x)!=find(i))
        {
            s[find(i)]+=s[find(x)];
            father[find(x)]=father[find(i)];
            sum--;
        }
        else
            flag=1;
    }
    if(n==2)
    {
        puts("1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(d[i]>2)
        {
        	puts("0");
            return 0;
        }
    if(sum>1&&flag)
    {
    	puts("0");
        return 0;
    }
    ans=1;
    for(int i=1;i<=sum-1;i++)
    	ans=(ans*i)%mod;
    for(int i=1;i<=n;i++)
    {
        if(father[i]==i&&s[i]>1)
            ans=(ans*2)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
