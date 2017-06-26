#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int n;
stack<int> sta;
int main()
{
	int i,j;
	scanf("%d",&n); getchar();
	for(i=1;i<=n;i++)
	{
		char ch=getchar();
		int num=(ch=='1')?1:0;
		if(!sta.empty() && sta.top()==(!num)) sta.pop();
		else sta.push(num);
	}
	printf("%d",sta.size());
	return 0;
}
