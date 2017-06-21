#include<cstdio>
int xx=0,yy=0;
int main(){
	int a,b,ans=0; scanf("%d%d",&a,&b);
	for(;a;){
		ans+=1; --a; ++xx; if(xx==b) xx=0,++a;
	}
	printf("%d",ans); return 0;
}
