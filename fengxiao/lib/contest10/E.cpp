#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#define F first
#define S second
#define pici 
using namespace std;
int n,m,ans;
map<int,pair<char ,int > > Map;
map<int,pair<char ,int > >::iterator it;
char c[20];
inline int abs(int a) {return a>0?a:-a;}
int main()
{
	int i,x,y;
	scanf("%d %d",&n,&m);
	Map[0]={'U',0}; Map[n+1]={'L',0};
	while(m--)
	{
		scanf("%d%d%s",&x,&y,c);
		it=Map.lower_bound(x);
		if(it->F==x)  {puts("0");continue;}
		if(c[0]=='L') it--;
		ans=abs((it->F)-x);
		if(it->S.F==c[0])ans+=it->S.S;
		printf("%d\n",ans);
		Map[x]={c[0],ans};
	}
	return 0;
}
