#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,cnt[2]={0};
char s[2333333];
int main()
{
	scanf("%d\n",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
		cnt[s[i]-'0']++;
	printf("%d",cnt[0]>cnt[1]?cnt[0]-cnt[1]:cnt[1]-cnt[0]);
}
/*读入要小心哦。。*/
