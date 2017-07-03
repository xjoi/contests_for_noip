#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
bool book[10000005];
int main()
{
	cin>>a>>b>>c>>d;
	memset(book,0,sizeof book);
	for(int i=0;i<=1000;i++)
		book[b+i*a]=true;
	for(int i=0;i<=1000;i++)
		if(book[d+i*c])
		{
			cout<<d+i*c<<endl;
			return 0;
		}
	cout<<"-1"<<endl;
	return 0;
}
