#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char s[50010];
int b[27];
int main()
{
    scanf("%s",s);
    int flag=true;
    int len=strlen(s);
    if(len<26)
    {
        printf("-1\n");
        return 0;
    }
    memset(b,0,sizeof(b));
    for(int i=0;i<=len-26&&flag==true;i++)
	{
        memset(b,0,sizeof(b));
        int cnt1=0,cnt2=0;
        for(int j=i;j<i+26;j++)
		{
            if(s[j]>='A'&&s[j]<='Z')
			{
               b[s[j]-'A']++;
            }
            else
				cnt2++;
        }
        for(int j=0;j<26;j++)
            if(b[j]==1)
				cnt1++;
        if(cnt2+cnt1==26)
        {
            int t=0;
            for(int j=i;j<i+26;j++)
			{
                if(s[j]=='?')
                    {
                        for(;t<26;t++)
						{
                            if(b[t]==0)
							{
                                s[j]='A'+t;
                                t++;
                                break;
                            }
                        }
                    }
            }
            flag=false;
        }
    }
    for(int i=0;i<len;i++)
	{
        if(s[i]=='?')
            s[i]='Z';
    }
    if(flag==true)
		printf("-1\n");
    else
		printf("%s\n",s);
    return 0;
}
