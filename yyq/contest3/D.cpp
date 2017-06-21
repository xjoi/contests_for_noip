#include<bits/stdc++.h> 
#define mod 1000000007
#define LL long long
#define M 1000005
using namespace std;
char p[M];
int n,m,x[M],l,ne[M];
LL po[M],pre[M];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",p+1);
    l=strlen(p+1);
    pre[l+1]=0;
    po[0]=1;
    for(int i=1;i<=l;i++)
        po[i]=po[i-1]*137LL%mod;
    for(int i=l;i;i--)
        pre[i]=(pre[i+1]+(p[i]-'a'+1)*po[l-i]%mod)%mod;
    LL ans=1;
    for(int i=1;i<=m;i++)
        scanf("%d",&x[i]);
    int L=0,ok=1;
    for(int i=1;i<=m;i++)
    {
        while(L+1<x[i])
            L++,ans=1LL*ans*26%mod;
        if(i!=1&&x[i-1]+l-1>=x[i])
        {
            int k=x[i-1]+l-1-x[i]+1;
            if (((pre[1]-pre[k+1]+mod)%mod)!=(pre[l-k+1]*po[l-k]%mod))
				ok=0;
        }
        if(!ok)
			break;
        L=x[i]+l-1;
    }
    while(L+1<=n)
        L++,ans=1LL*ans*26%mod;
    cout<<(ok*ans%mod+mod)%mod<<endl;
    return 0;
}
