#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,k,m,temp;
int doll[maxn];
int cnt;
int main()
{
    scanf("%d%d",&n,&k);
    cnt=0;
    for(int j=1;j<=k;j++)
    {
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            scanf("%d",&doll[i]);
        if(doll[0]==1)
        {
            temp=m;
            for(int i=0;i<m;i++)
            {
                if(doll[i]==i+1)
                    cnt++;
                else
                    break;
            }
        }
    }
    printf("%d\n",((n-temp)-(k-1))+(temp-cnt)+(n-cnt));
    return 0;
}
