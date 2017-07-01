#include<bits/stdc++.h>
using namespace std;
long long i,n,m,k=1,f,x,r[300001];
string s;
int main()
{
	cin>>n; 
	for (i=1;i<=2*n;i++)
	{
		cin>>s;
		if (s=="add")
		{
			cin>>x;
			f++;
			r[f]=x;
		}
		else
		{
			if(f>0&&r[f]!=k)
			{
				f=0;
				m++;
			}
			else if(f>0)
				f--;
			k++;
		}
	}
	cout<<m<<endl;
	return 0;
}
