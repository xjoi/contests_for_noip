#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>
using namespace std;
int n,m,k,tmp;
set<int> S;
int main()
{
	int i,j;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		S.clear();
		int flag=0;
		cin>>k;
		for (j=1;j<=k;j++)
		{
			cin>>tmp;
			S.insert(tmp);
			if (S.find(-tmp)!=S.end()) flag=1;
		}
		if(!flag){puts("YES"); return 0;}
	}
	puts("NO");
}
