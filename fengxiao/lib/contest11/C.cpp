#include<cstdio>
#include<stack>
#define N 300010
using namespace std;
int n,cnt=1,ans=0;
bool used[N];
stack<int> sta;
int main()
{
	int i; char ch[20];int tmp;
	scanf("%d",&n);
	n<<=1;
	while(n--)
	{
		scanf("%s",ch);
		if(ch[0]=='a')
		{
			scanf("%d",&tmp);
			sta.push(tmp);
		}
		else
		{
			if(!sta.size())
			{ if(used[cnt]) cnt++; continue;}
			if(sta.top()==cnt) {used[sta.top()]=1; sta.pop(); cnt++;}
			else {ans++; while(!sta.empty()) {used[sta.top()]=1; sta.pop();} if(used[cnt]) cnt++;}
		}
	}
	printf("%d",ans);
	return 0;
}
