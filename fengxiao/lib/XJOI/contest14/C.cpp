#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define N 200010
using namespace std;
int prime[N],k;
int n,len;
int cnt[N],ans[N];
bool ha[N];
inline void clear() {memset(ans,0,sizeof(ans));memset(cnt,0,sizeof(cnt)); len=ans[1]=1;}
void get_p()
{
    int i,j;
    memset(ha,0,sizeof(ha));
    ha[0]=ha[1]=1; k=0;
    for(i=2;i<=10000;i++)
    {
        if(!ha[i]) prime[++k]=i;
        for(j=1;j<=k;j++)
        {
            if(prime[j]*i>10000) break;
            ha[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    int i,j;
    get_p();
    while(scanf("%d",&n)==1 && n)
    {
        clear();
        for(i=1;i<=n;i++)
        {
            int tmp=i,pos=0;
            while(tmp>1)
            {
                pos++;
                while(tmp%prime[pos]==0) {cnt[pos]++; tmp/=prime[pos];}
            }
        }
        for(i=1;i<=k;i++)
            if(cnt[i])
            {
                cnt[i]=cnt[i]*2+1;
                for(j=1;j<=len;j++) ans[j]*=cnt[i];
                for(j=1;j<=len;j++)
                {
                    ans[j+1]+=ans[j]/10000;
                    ans[j]%=10000;
                }
                while(ans[len+1]!=0)
                {
                    len++;
                    ans[len+1]+=ans[len]/10000;
                    ans[len]%=10000;
                }
            }
        cout<<ans[len]; for(i=len-1;i>=1;i--) cout<<setw(4)<<setfill('0')<<ans[i]; puts("");
    }
}
