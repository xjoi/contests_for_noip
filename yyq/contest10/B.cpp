#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int gear[maxn];
int n;
bool flag;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&gear[i]);
    for(int i=1;i<=n;i++)
    {
        flag=true;
        for(int j=0;j<n;j++)
        {
            if(gear[j]==j)
                continue;
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
            goto END;
        for(int j=0;j<n;j++)
        {
            if(j%2==0)
            {
                gear[j]++;
                if(gear[j]>n-1)
                    gear[j]=0;
        	}
            else
            {
                gear[j]--;
                if(gear[j]<0)
                    gear[j]=n-1;
            }
        }
    }
    END:
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
