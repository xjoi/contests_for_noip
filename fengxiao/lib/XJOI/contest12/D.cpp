#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pii pair<int ,int >
#define F first
#define S second
#define mp make_pair
using namespace std;
int f,b,c,d,e,ls,cnt[500],ans;
pii a[6];
bool cmp(int a,int b) {return a>b;}
int main()
{
    int i,j,tmp; char ch[10];
    scanf("%d %d %d %d %d %d",&f,&b,&c,&d,&e,&ls); gets(ch);
    a[1]=mp(f,1); a[2]=mp(b,16); a[3]=mp(c,8); a[4]=mp(d,8); a[5]=mp(e,15);
    sort(a+1,a+6);
    for(i=1;i<=ls;i++) cnt[getchar()]++;
    sort(cnt+1,cnt+300+1,cmp);
    int k=1;
    for(i=1,k=1;i<=256&&cnt[i];i++,--a[k].S==0?++k:0) ans+=a[k].F*cnt[i];
    printf("%d",ans);
    return 0;
}
