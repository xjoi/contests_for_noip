#include<bits/stdc++.h>
using namespace std;
int tot=0;
int num;
int x;
int n,c;
int main()
{
	cin>>n>>c;
	cin>>num;
	x=num;
	tot++;
	n--;
	while(n--)
	{
		cin>>num;
		if(num-x<=c)
			tot++;
		else
			tot=1;
		x=num;
	}
	cout<<tot<<endl;
	return 0;
}
