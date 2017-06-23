#include<cstdio>
#include<string>
using namespace std;
char s[300000];
int n,ans;
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++)
	ans+=s[i]=='0'?1:-1;
	printf("%d",ans>0?ans:-ans);
}
