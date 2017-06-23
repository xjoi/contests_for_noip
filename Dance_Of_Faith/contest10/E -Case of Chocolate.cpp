#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
map<int,pair<char,int> > mp;map<int,pair<char,int> >::iterator dis;
int main(){
	int n,Q,x,y;char ch;cin >>n>>Q;
	mp[0]={'U',0};mp[n+1]={'L',0};
	for (int i=1;i<=Q;++i){
		scanf("%d %d %c",&x,&y,&ch);
		dis=mp.lower_bound(x);
		if (dis->first==x){puts("0");continue;}
		if (ch=='L') --dis;
		int aa=abs(dis->first-x);
		if (dis->second.first==ch) aa+=dis->second.second;
		cout <<aa<<endl;mp[x]={ch,aa};
	}
	return 0;
}
