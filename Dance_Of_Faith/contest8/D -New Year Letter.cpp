#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int f[100];
main(){
	int k,n,m,x;cin >>k>>x>>n>>m;
	for (int i=0;i<=n/2;++i)
	for (int j=0;j<=m/2;++j)
	for (int a=0;a<=1;++a)
	for (int b=0;b<=1;++b)
	for (int c=0;c<=1;++c)
	for (int d=0;d<=1;++d){
		if (i*2+a+b>n||j*2+c+d>m) continue;
		f[1]=i;f[2]=j;int t=0;
		if (b!=0&&c!=0) t++;
		for (int z=3;z<=k;++z){
			f[z]=f[z-1]+f[z-2];
			if (t) ++f[z],t--;
			if (d!=0&&a!=0&& z%2==0&&z>3) ++f[z];
			if (d!=0&&c!=0&& z%2==1&&z>3) ++f[z];
		}
		if (f[k]==x){
			if (a!=0) cout <<'C';
			for (int z=1;z<=i;++z) cout <<"AC";
			for (int z=1;z<=n-i*2-a-b;++z) cout <<'B';
			if (b!=0) cout <<'A';cout <<endl;
			if (c!=0) cout <<'C';
			for (int z=1;z<=j;++z) cout <<"AC";
			for (int z=1;z<=m-j*2-c-d;++z) cout <<'B';
			if (d!=0) cout <<'A';return 0;
		}
	}
	puts("Happy new year!");return 0;
}
