#include<cstdio>
#include<map>
#include<string>
#include<cmath>
using namespace std;
map<int,pair<char,int> >mp;
map<int,pair<char,int> >::iterator it;
char c;
int n,Q,x,y,ans;
int main(){
	scanf("%d%d",&n,&Q);
	mp[0]=make_pair('L',0);
	mp[n+1]=make_pair('U',0);
	for(int i=1;i<=Q;i++){
		scanf("%d%d %c",&x,&y,&c);
		it=mp.lower_bound(x);
		ans=0;
		if(it->first!=x){
		    if(c=='L')it--;
			if(it->second.first==c)ans=it->second.second+abs(it->first-x);else ans=abs(it->first-x);
		}
		if(ans)mp[x]=make_pair(c,ans);
		printf("%d\n",ans);
	}
}
