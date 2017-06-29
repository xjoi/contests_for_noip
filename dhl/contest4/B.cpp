#include<bits/stdc++.h>
using namespace std;
int n;
char a[300];
int s2[2000],s1[2000];
int ans=0,sum=0,rans=0;
bool cmp(const int &a,const int &b)
{
	return a>b;
}

int judge1()
{
	sort(s1,s1+n);
	sort(s2,s2+n);
	for(int i=0;i<n;i++)
		if(s1[i]>=s2[i]) 	
			return 0;
	return 1;
	
}

int judge2()
{
	sort(s1,s1+n,cmp);
	sort(s2,s2+n,cmp);
	for(int i=0;i<n;i++)
		if(s1[i]<=s2[i]) 	
			return 0;
	return 1;
	
}

int main()
{
	cin>>n;
	scanf("%s",a);
	for(int i=0;i<n;i++)
		s1[i]=a[i]-'0';
	for(int i=n;i<n*2;i++)
		s2[i-n]=a[i]-'0';
	if(judge1()||judge2())
		cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
