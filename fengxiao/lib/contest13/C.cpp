#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std ;
int cnt[20];
string b[]={"1869","6198","1896","9186","9168","6189","8691"};
string s;
int main()
{
	int i;
	cin>>s; int ls=s.size();
	for (i=0;i<ls;i++) cnt[s[i]-'0']++;
	cnt[1]--;cnt[8]--;cnt[6]--;cnt[9]--;
	int tmp=0;
	for(i=1;i<10;i++)
		while(cnt[i])
		{
			printf("%d",i);
			tmp=tmp*10+i; tmp=tmp%7;
			cnt[i]--;
		}
	cout<<b[tmp];
	while(cnt[0]--) printf("0");
	return 0 ;
}
