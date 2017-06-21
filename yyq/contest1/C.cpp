#include<bits/stdc++.h>
using namespace std;
int ord[33],edge[110][110],in[33];
char mat[110][110],ans[33];
vector<int> s;
bool vis[33];
void topo()
{
	bool flag=1;
	int ret=0;
	for(int i=1;i<=26;++i)
		ret+=vis[i];
	memset(in,0,sizeof(in));
	s.clear();
	int cnt=1;
	queue<int> qu;
	while(!qu.empty())
		qu.pop();
	int x=0;
	for(int i=1;i<=26;++i)
	{
		if(!vis[i])
			continue;
		int t=0;
		for(int j=1;j<=26;++j)
			t+=edge[j][i];
		in[i]=t;
		if(!t)
		{
			qu.push(i);
			++x;
			s.push_back(i);
		}
	}
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();
		for(int i=1;i<=26;++i)
		{
			if(!edge[u][i])
				continue;
			edge[u][i]=0;
			in[i]--;
			if(in[i]==0)
			{
				++x;
				qu.push(i);
				s.push_back(i);
			}
		}
	}
	if(x<ret)
	{
		printf("Impossible\n");
		return;
	}
	x=0;
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<s.size();++i)
	{
		ans[x++]=s[i]-1+'a';
		vis[s[i]]=1;
	}
	for(int i=1;i<=26;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			ans[x++]=i-1+'a';
		}
	}
	for(int i=x-1;i>=0;--i)
		printf("%c", ans[i]);
	printf("\n");
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(vis,0,sizeof(vis));
	memset(edge,0,sizeof(edge));
	for(int i=1;i<=n;++i)
		scanf("%s", mat[i]);
	bool x=true;
	for(int i=2;i<=n;++i)
	{
		int len1=strlen(mat[i-1]);
		int len2=strlen(mat[i]);
		bool flag=false;
		char s,b;
		for(int j=0;j<min(len1,len2);++j)
		{
			if(mat[i][j]==mat[i-1][j])
				continue;
			else
			{
				s=mat[i-1][j];
				b=mat[i][j];
				flag=true;
				break;
			}
		}
		if(!flag&&len1>len2)
		{
			x=false;
			break;
		}
		else if(flag)
		{
			if(edge[b-'a'+1][s-'a'+1]==0)
			{
				edge[b-'a'+1][s-'a'+1]=1;
				vis[b-'a'+1]=1;
				vis[s-'a'+1]=1;
			}
			else if(edge[s-'a'+1][b-'a'+1])
			{
				x=false;
				break;
			}
		}
	}
	if(!x)
	{
		printf("Impossible\n");
		return 0;
	}
	topo();
	return 0;
}
