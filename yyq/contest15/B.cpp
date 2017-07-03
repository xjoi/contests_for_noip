#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int a[maxn];
int solve(int n)
{
    map<int,int> maple;
    for(int i=0;i<n;i++)
    {
        if(maple.find(-a[i])!=maple.end())
            return 0;
        maple[a[i]]=1;
    }
    return 1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int flag = 1;
    for(int i=0;i<m;i++)
    {
        int len;
        scanf("%d",&len);
        for(int i=0;i<len;i++)
            scanf("%d",&a[i]);
        if(solve(len))
            flag = 0;
    }
    if(flag)
        puts("NO");
    else
        puts("YES");
    return 0;
}
