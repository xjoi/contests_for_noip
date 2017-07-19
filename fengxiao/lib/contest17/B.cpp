#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char s[1000010];
int v[100];
int main()
{
	int i,j,ls,n,ans=0;
	scanf("%s",s); ls=strlen(s);
	scanf("%d",&n);
	for(i=1;i<=26;i++) scanf("%d",&v[i]);
	int maxn=0,pos;
	for(i=1;i<=26;i++) if(v[i]>maxn) {maxn=v[i]; pos=i;}
	for(i=0;i<ls;i++) { ans+=v[s[i]-'a'+1]*(i+1);}
	for(i=1;i<=n;i++) ans+=(ls+i)*maxn;
	printf("%d",ans);
	return 0;
}
