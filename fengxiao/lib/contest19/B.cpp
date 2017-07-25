#include<bits/stdc++.h>
using namespace std;
char s[1000010];
map<int,int> key;
int ap[100010],cnt=0;
inline bool isd(int x) {return x>='0' && x<='9';}
inline bool ok(int i) {return isd(s[i]) && isd(s[i+1]) && s[i+2]=='-' && isd(s[i+3]) && isd(s[i+4]) && s[i+5]=='-' && 
							  isd(s[i+6]) && isd(s[i+7]) && isd(s[i+8]) && isd(s[i+9]);}
inline bool isok(int x)
{
	int a=x/1000000,b=x/10000-x/1000000*100,c=x%10000;
	//printf("%d %d %d\n",a,b,c);
	if(b>12 || b<1 || a<1 || a>31 || c<2013 || c>2015) return false;
	if(b==2 && a>28) return false;
	else if(b<=7)
	{
		if(b&1 && a>31) return false;
		else if(!(b&1)  && a>30) return false; 
	}
	else if(b>7)
	{
		if(b&1 &&a>30) return false;
		else if(!(b&1) &&a>31) return false;
	}
	return true;
}
inline void print(int x)
{
	int a=x/1000000,b=x/10000-x/1000000*100,c=x%10000;
	printf("%02d-%02d-%4d",a,b,c);
}
int main()
{
	scanf("%s",s);int ls=strlen(s);
	for(int i=0;i<=ls-10;i++)
	{
		if(ok(i))
		{
			int num=0;
			num=(s[i]-'0')*1e7+(s[i+1]-'0')*1e6+(s[i+3]-'0')*1e5+(s[i+4]-'0')*1e4+(s[i+6]-'0')*1e3+(s[i+7]-'0')*1e2+(s[i+8]-'0')*1e1+(s[i+9]-'0')   ;
			if(isok(num))
			{
				key[num]++;
				if(key[num]==1) ap[++cnt]=num;
			}
		}
	}
	int pos=0,maxn=0;
	for(int i=1;i<=cnt;i++)
		if(key[ap[i]]>maxn)
		{
			maxn=key[ap[i]];
			pos=ap[i];
		}
	print(pos);
	return 0;
}
