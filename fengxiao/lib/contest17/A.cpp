#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<int,int> key;
int main()
{
	int i,j,n,p,a;
	scanf("%d %d",&p,&n);
	for(i=1;i<=n;i++) {scanf("%d",&a); if(!key[a%p]) key[a%p]=1; else {printf("%d\n",i); return 0;}}
	puts("-1");
	return 0;
}
