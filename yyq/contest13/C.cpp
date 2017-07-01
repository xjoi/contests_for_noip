#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1001000];
char w[1001000];
bool mark[11];
ll len;
ll top=0,sum=0,SumZero=0;
int main()
{
    memset(mark,false,sizeof(mark));
    cin>>s;
    len=strlen(s);
    for(int i=0;i<len;++i)
    {
        if((s[i]=='1'||s[i]=='6'||s[i]=='8'||s[i]=='9')&&mark[s[i]-'0']==false)
            mark[s[i]-'0']=true;
        else if(s[i]=='0')
            SumZero++;
        else
            w[top++]=s[i];
    }
    for(int i=0;i<top;++i)
    {
        sum*=10;
        sum+=(w[i]-'0');
        sum%=7;
    }
    sum*=10000;
    sum%=7;
    for(int i=0;i<top;++i)
        printf("%c",w[i]);
    switch(sum)
    {
        case 0:
			printf("1869");
			break;
        case 6:
			printf("1968");
			break;
        case 5:
			printf("1689");
			break;
        case 4:
			printf("6198");
			break;
        case 3:
			printf("8691");
			break;
        case 2:
			printf("9861");
			break;
        case 1:
			printf("8196");
			break;
    }
    while(SumZero--)
        printf("0");
    putchar('\n');
    return 0;
}
