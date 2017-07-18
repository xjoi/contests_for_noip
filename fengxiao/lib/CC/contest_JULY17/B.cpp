#include<cstdio>
#include<cstring>
#include<iostream>
#define N 1000010
using namespace std;
int ls;
char s[N+100];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s; ls=strlen(s);
		int i=0,cnt=0,top=1,b=1;
		while(i<ls)
		{
			char t=s[i]; cnt=0;
			for(i=i;i<ls;i++)
				if(s[i]==t) cnt++;
				else if(s[i]=='=');
				else break;
			if(t == '<') top=max(top,b+cnt),b+=cnt;
			if(t == '>') top=max(top,cnt+1),b=1;
		}
		cout<<top<<endl;
	}
	return 0;
}
/*1
<<<>>><<<><<><><>>===>><<<>>*/
