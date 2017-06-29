#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int a[400000];
char s[400000];
int n;
int sta[400000],top=0;
vector<int> v;

int main()
{
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int ok=0;
		v.clear();
		for(int j=0;j<n;j++)
		{
			if(j&1)	v.push_back((a[j]-i+n)%n);
			else
				v.push_back((a[j]+i+n)%n);
		}
		for(int k=0;k<v.size()-1;k++)
			if(v[k]!=v[k+1]-1) ok=1;
		if(!ok)
			{cout<<"Yes\n";return 0;}
			
	}
	cout<<"No\n";
	return 0;
}
