#include<bits/stdc++.h>
using namespace std;
int ans=0;
string s;
int n;
int main()
{
	scanf("%d",&n);
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
	        ans++;
		else
	        ans--; 
	}
	printf("%d\n",abs(ans));
	return 0;
} 
