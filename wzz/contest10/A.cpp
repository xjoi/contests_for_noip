using namespace std;
#include<bits/stdc++.h>
int n,len,ans;
char s[1000001];
int main()
{
	cin>>n;
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='0') ans++;else ans--;
	}
	cout<<abs(ans);
}
