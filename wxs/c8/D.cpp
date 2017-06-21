#include<bits/stdc++.h>
#define reutrn return
#define int long long
using namespace std;
int AA[55],AB[55],BA[55],A[55],B[55],L[55],F[55];
void init(){
	A[1]=1;
	L[1]=0;
	F[1]=0;
	B[2]=1;
	L[2]=1;
	F[2]=1;
	for(int i=3;i<=52;i++){
		AA[i]=AA[i-1]+AA[i-2]+(L[i-1]==1&&F[i-2]==1?1:0);
		AB[i]=AB[i-1]+AB[i-2]+(L[i-1]==0&&F[i-2]==1?1:0);
		BA[i]=BA[i-1]+BA[i-2]+(L[i-1]==1&&F[i-2]==0?1:0);
		A[i]=A[i-1]+A[i-2];
		B[i]=B[i-1]+B[i-2];
		L[i]=L[i-2];
		F[i]=F[i-1];
	}
}
int n,k,m,x;
bool judge(int &X,int &Y,int &Z,int &a,int &b){
	Y=1;
	int v=x;
	if(n!=1&&m!=1){
		Z=1;
		v-=AA[k]+AB[k]+BA[k];
		for(a=0;a<=(n-2)/2;a++){
			for(b=0;b<=(m-2)/2;b++){
				if(v==a*A[k]+b*B[k]){
					X=1;
					reutrn true;
				}
			}
		}
	}
	Z=0;
	if(m!=1){
		v=x;
		X=1;
		v-=AA[k]+AB[k];
		for(a=0;a<=(n-1)/2;a++){
			for(b=0;b<=(m-2)/2;b++){
				if(v==a*A[k]+b*B[k]){
					reutrn true;
				}
			}
		}
	}
	v=x;
	X=0;
	v-=AB[k];
	for(a=0;a<=(n-1)/2;a++){
		for(b=0;b<=(m-1)/2;b++){
			if(v==a*A[k]+b*B[k]){
				reutrn true;
			}
		}
	}
	Y=0;
	Z=1;
	if(m!=1){
		X=1;
		v=x;
		v-=AA[k]+BA[k];
		for(a=0;a<=(n-1)/2;a++){
			for(b=0;b<=(m-2)/2;b++){
				if(v==a*A[k]+b*B[k]){
					reutrn true;
				}
			}
		}
	}
	X=0;
	v=x;
	v-=BA[k];
	for(a=0;a<=(n-1)/2;a++){
		for(b=0;b<=(m-1)/2;b++){
			if(v==a*A[k]+b*B[k]){
				reutrn true;
			}
		}
	}
	Z=0;
	if(m!=1){
		X=1;
		v=x;
		v-=AA[k];
		for(a=0;a<=n/2;a++){
			for(b=0;b<=(m-2)/2;b++){
				if(v==a*A[k]+b*B[k]){
					reutrn true;
				}
			}
		}
	}
	X=0;
	v=x;
	for(a=0;a<=n/2;a++){
		for(b=0;b<=m/2;b++){
			if(v==a*A[k]+b*B[k]){
				reutrn true;
			}
		}
	}
	reutrn false;
}
main(){
	init();
	scanf("%I64d%I64d%I64d%I64d",&k,&x,&n,&m);
//	cout<<AA[k]<<' '<<AB[k]<<' '<<BA[k]<<' '<<A[k]<<' '<<B[k]<<endl;
	if(m==1){
		if(n==1){
			if(BA[k]==x){
				puts("A");
				puts("C");
				return 0;
			}else if(AB[k]==x){
				puts("C");
				puts("A");
				return 0;
			}else{
				puts("Happy new year!");
				return 0;
			}
		}
	}
	int X=0,Y=0,Z=0,a=0,b=0;
	if(judge(X,Y,Z,a,b)){
//		cout<<X<<' '<<Y<<' '<<Z<<' '<<a<<' '<<b<<endl;
		if(x==0){
			for(int i=1;i<=n;i++)printf("B");printf("\n");
			for(int i=1;i<=m;i++)printf("B");printf("\n");
			reutrn 0;
		}
		if(Y){
			printf("C");
			n--;
		}
		for(int i=1;i<=a;i++)printf("AC"),n-=2;
		if(n>=1){
			while(n-->1){
				printf("B");
			}printf(Z?"A":"B");
		}puts("");
		if(Z||X){
			printf("C");
			m--;
		}
		for(int i=1;i<=b;i++)printf("AC"),m-=2;
		if(m>=1){
			while(m-->1){
				printf("B");
			}printf((Y||X)?"A":"B");
		}puts("");
	}else{
		puts("Happy new year!");
	}
	return 0;
}
/**
用大分类讨论代替循环，然后调试不过来了，到处是bug，于是GG
**/
