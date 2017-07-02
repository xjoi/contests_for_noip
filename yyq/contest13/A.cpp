#include<bits/stdc++.h>
using namespace std;
string s;
int mid=-1;
int lefts[1000005],rights[1000005];
long long sumleft=0,sumright=0;
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(mid==-1&&s[i]>='0'&&s[i]<='9')
			lefts[i+1]=s[i]-'0';
		if(s[i]=='^')
			mid=i+1;
		if(mid!=-1&&s[i]>='0'&&s[i]<='9')
			rights[i+1-mid]=s[i]-'0';
	}
	for(int i=1;i<=s.length();i++)
		sumleft+=lefts[i]*(mid-i);
	for(int i=1;i<=s.length();i++)
		sumright+=rights[i]*i;
//	cout<<sumleft<<" "<<sumright<<endl;
	if(sumleft==sumright)
		puts("balance");
	if(sumleft<sumright)
		puts("right");
	if(sumleft>sumright)
		puts("left");
	return 0;
}
