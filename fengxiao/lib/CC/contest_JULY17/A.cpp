#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,cnt=0,name[110];
char upper(char ch)
{
	if(ch>='A' && ch<='Z') return ch;
	else return ch-'a'+'A';
}
char lower(char ch)
{
	if(ch>='a' && ch<='z') return ch;
	else return ch-'A'+'a';
}
int main()
{
	int i,j; char ch=0;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
		while(ch!='\n')
		{
			ch=getchar(); cnt=0;
			while(ch!=' ' && ch!='\n')
			{
				if(cnt==0) name[++cnt]=upper(ch);
				else name[++cnt]=lower(ch);
				ch=getchar();
			}
			if(ch!='\n') printf("%c. ",name[1]);
			else break;
		}
		for(j=1;j<=cnt;j++) printf("%c",name[j]); puts("");
		ch=0;
	}
	
	return 0;
}
