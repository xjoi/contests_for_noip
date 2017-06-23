#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,ans,p;
int main(){
	scanf("%d%d",&a,&b);p=0;
	while(a){
		ans+=a;
		p+=a;
		a=p/b;
		p=p%b;
	}
	printf("%d",ans);
}
