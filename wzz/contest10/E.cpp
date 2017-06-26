using namespace std;
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<iostream>
map< int,pair<char,int> >M;
map< int,pair<char,int> > ::iterator it;
int q,ans;
int n;
int x,y;
char cyz666;
int main()
{
	cin>>n>>q;
	M[0]=make_pair('U',0);
	M[n+1]=make_pair('L',0);
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d %c",&x,&y,&cyz666);
		it=M.lower_bound(x);
		if(it->first==x) {puts("0");continue;} 
		if(cyz666=='L') it--; 
		ans=0;   
		ans=abs(x-(it->first)); 
		if(it->second.first==cyz666) ans+=(it->second.second);
		if (ans==-79) cout<<endl<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
		M[x]=make_pair(cyz666,ans);
		printf("%d\n",ans);
	}
}
