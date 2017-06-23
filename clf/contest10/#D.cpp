#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
const int N=200005;
struct node{LL l,r;int num;}is[N];
struct node1{LL len;int num;}bri[N];
struct nc{
	bool operator()(node a,node b){return a.r>b.r;}
};
LL l[N],r[N];
int link[N];
priority_queue<node,vector<node>,nc> pq;
inline bool cmp(node a,node b) {return (a.l==b.l)?(a.r<b.r):(a.l<b.l);}
inline bool cmp1(node1 a,node1 b) {return a.len<b.len;}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d%I64d",&l[i],&r[i]);
	for(int i=1;i<=m;i++) scanf("%I64d",&bri[i].len),bri[i].num=i;
	for(int i=1;i<n;i++) {
		is[i]=(node){l[i+1]-r[i],r[i+1]-l[i],i};
	}
	sort(is+1,is+n,cmp);
	sort(bri+1,bri+m+1,cmp1);
	node tmp;
	int p=1;
	for(int i=1;i<=m;i++) {
		while(is[p].l<=bri[i].len&&p<n) {
			pq.push(is[p]);
			p++;
		}
		bool fl=0;
		while(!pq.empty()) {
			tmp=pq.top();
			pq.pop();
			if(tmp.r>=bri[i].len) {
				link[tmp.num]=bri[i].num;
				fl=1;
				break;
			}
		}
	}
	for(int i=1;i<n;i++) if(!link[i]) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<n;i++) printf("%d ",link[i]);
	return 0;
}
