#include<cstdio>
char st[101],en[101];
int f[101];
int n,m,k,x;
char map(int x){
	if(x==1) return 'A';
	if(x==2) return 'C';
	if(x==3) return 'D';
}
bool check(int lenth,int total,char st,char en){
	char c[101]={' '}; c[1]=st; int nowcnt=0; c[total]=en;
	for(int i=2;i<total;++i) if(nowcnt<lenth){
		c[i]=c[i-1]=='A'?'C':'A';
		if(c[i-1]=='A'&&c[i]=='C') ++nowcnt;
	}else{
		c[i]='D';
	}
	if(c[total-1]=='A'&&c[total]=='C') ++nowcnt; return nowcnt==lenth;
}
bool dp(){
	for(int i=3;i<=k;++i){
		st[i]=st[i-2]; en[i]=en[i-1]; f[i]=f[i-1]+f[i-2];
		if(en[i-2]=='A'&&st[i-1]=='C') ++f[i];
		if(f[i]>x) return 0;
	}
	return f[k]==x;
}
bool check2(int lenth,int total,char st,char en){
	char c[101]={' '}; c[1]=st; int nowcnt=0; c[total]=en;
	for(int i=2;i<total;++i) if(nowcnt<lenth){
		c[i]=c[i-1]=='A'?'C':'A';
		if(c[i-1]=='A'&&c[i]=='C') ++nowcnt;
	}else{
	 c[i]='D';
	}
	for(int i=1;i<=total;++i) printf("%c",c[i]); printf("\n");
}
int main(){
	scanf("%d%d%d%d",&k,&x,&n,&m);
	for(int i=1;i<=3;++i) for(int j=1;j<=3;++j) for(int k=1;k<=3;++k) for(int l=1;l<=3;++l){
		if(n==1&&i!=j) continue; if(m==1&&k!=l) continue;
		st[1]=map(i); en[1]=map(j); st[2]=map(k); en[2]=map(l);
		for(int l1=0;l1<=n/2;++l1) for(int l2=0;l2<=m/2;++l2){
			if(check(l1,n,st[1],en[1])&&check(l2,m,st[2],en[2])){
				f[1]=l1; f[2]=l2;
				if(dp()){
					check2(l1,n,st[1],en[1]); check2(l2,m,st[2],en[2]);
					return 0;
				}
			}
		}
	}
	printf("Happy new year!");
}
