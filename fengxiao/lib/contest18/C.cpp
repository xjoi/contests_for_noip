#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100010],ans[100010]; int lst=0;
struct P {int v,pos;} a[100010];
bool cmp(P a,P b) {return a.v==b.v ? a.pos<b.pos : a.v>b.v;}
int main()
{
	scanf("%s",s); int n=strlen(s);
	for(int i=0;i<n;i++) a[i+1].v=s[i]-'a',a[i+1].pos=i+1;
	sort(a+1,a+n+1,cmp);
	int now=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].pos>now) ans[++lst]=a[i].v+'a',now=a[i].pos;
	}
	for(int i=1;i<=lst;i++) printf("%c",ans[i]);
	return 0;
}
