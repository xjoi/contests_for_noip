#include<cstdio>
#include<cstring>
using namespace std;
char s[10000010]; int pos;
long long v=0;
int main()
{
	int i;
	scanf("%s",s);
	int  ls=strlen(s);
	for(i=0;i<ls;i++) if(s[i]=='^') {pos=i; break;}
	for(i=0;i<ls;i++)
		if(s[i]>='0'&& s[i]<='9')
			v+=(s[i]-'0')*(pos-i);
	if(v==0) puts("balance");
	else if(v>0) puts("left");
	else if(v<0) puts("right");
	return 0;
}
