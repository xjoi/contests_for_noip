#include<cstdio>
#include<cstring>
using namespace std;
char ch[50010];
int a[50010];
int h=0,t=25,cnt[1000],count=0,ls;
bool flag[1000];
void print()
{
	int p=-1;
	//for(int i=h;i<=t;i++) printf("%c",ch[i]); puts("");
	for(int i=0;i<ls;i++)
	{
		//printf("%d ",i);
		if(i>=h && i<=t)
		{
			if(ch[i]!='?') printf("%c",ch[i]);
			else 
			{
				for(p=p+1;p<=25;p++) if(!flag[p]) {printf("%c",p+'A'); break;}
			}
		}
		else 
		{
			if(ch[i]=='?') printf("A");
			else printf("%c",ch[i]); 
		}
	}
}
int main()
{
	int i;
	scanf("%s",ch);
	ls=strlen(ch);
	if(ls<26) {puts("-1"); return 0;}
	for(i=0;i<ls;i++) a[i]=ch[i]=='?' ? 28 : ch[i]-'A';
	for(i=0;i<26;i++)
		{cnt[a[i]]++; if(cnt[a[i]]==1) flag[a[i]]=1; else flag[a[i]]=0;}
	
	for(i=0;i<26;i++) if(flag[i]) count++;
	if(count+cnt[28]==26) {print(); return 0;}
	while(t<ls-1)
	{//printf("%d ",t);
		cnt[a[h++]]--;
		if(cnt[a[h-1]]==1) flag[a[h-1]]=1; else flag[a[h-1]]=0;
		cnt[a[++t]]++;
		if(cnt[a[t]]==1) flag[a[t]]=1; else flag[a[t]]=0;
		count=0;
		//printf("%d %d\n",cnt[0], flag[0]);
		for(i=0;i<26;i++)
			if(flag[i]) count++;
		if(count+cnt[28]==26) {print();return 0;}
	}
	puts("-1");
	return 0;
}
