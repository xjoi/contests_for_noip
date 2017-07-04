#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int sta[500010];
string ss;
bool cmp(int a,int b){return a>b;}
int main(){
	int n,top=0,x,cnt=0,ans=0;cin >>n;
	for (int i=1;i<=2*n;++i){
		cin >>ss;if (ss[0]=='a') cin >>x;
		if (ss[0]=='a') sta[++top]=x;
		else{
			if (top==0){++cnt;continue;}
			if (sta[top]!=++cnt) ++ans,top=0;else --top;
		}
	}
	cout <<ans<<endl;return 0;
}
