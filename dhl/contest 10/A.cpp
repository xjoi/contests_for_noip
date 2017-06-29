#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int a[400000];
char s[400000];
int n;
int sta[400000],top=0;

int main()
{
	
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
		a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
	{
		int num=a[i];
		//cout<<num<<" "<<sta[top]<<endl;
		if(top!=0&&sta[top]==1-num)
			{top--;continue;}
		sta[++top]=num;
	}
	cout<<top<<endl;
	
	return 0;
}
