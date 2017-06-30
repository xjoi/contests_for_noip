#include<cstdio>
#include<queue>
using namespace std;
const int N=100001;
queue<int> a;
int main(){
	int n,k,out=0,step=0; scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		int cnt; scanf("%d",&cnt);
		for(;!a.empty();) a.pop();
		for(int j=1;j<=cnt;++j){
			int x; scanf("%d",&x);
			a.push(x);
		}
		if(a.front()==1){
			int nowcnt=0;
			for(;!a.empty()&&a.front()==nowcnt+1;a.pop()) nowcnt=a.front();
			out+=a.size()+1; step+=a.size();
		}else out+=a.size(),step+=a.size()-1;
	}
	printf("%d",out+step-1); return 0;
}
