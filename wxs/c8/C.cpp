#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,idx;
}a[1000000];
bool operator<(Node A,Node B){
	return A.x<B.x;
}
int n;
int rank[1000000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].idx=i;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i].x==a[i-1].x){
			a[i].x++;
			int j=1+i;
			while(j<=n&&a[j].x>=a[i-1].x&&a[j].x<=a[j-1].x){
				a[j].x=a[i-1].x+j-i+1;
				j++;
			}
		}
	}
	for(int i=1;i<=n;i++)rank[a[i].idx]=a[i].x;
	for(int i=1;i<=n;i++)printf("%d ",rank[i]);
	return 0;
}
/**
一开始打萎了
**/
