#include<cstdio>
#include<cstring>
#define ll long long
#define N 50010
using namespace std;
ll a[N],n,K,sum[N],cnt[1000010],ans;
int main()
{
    ll T;
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%I64d %I64d",&K,&n); ans=0; memset(cnt,0,sizeof(cnt));
        cnt[0]=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=(sum[i-1]+a[i])%K;
            ans+=cnt[sum[i]];
            cnt[sum[i]]++;
        }
        printf("%d\n",ans);
    }
     
    return 0;
}
