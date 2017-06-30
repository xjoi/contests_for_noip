#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
int ans=0;
double len[5],x[5],y[5];
void check4()
{
	if (len[1]==len[3])
	{
		if ((y[1]-y[2])*(x[3]-x[4])-(y[3]-y[4])*(x[1]-x[2])!=0)
		if ((y[2]-y[3])*(x[4]-x[1])-(y[4]-y[1])*(x[2]-x[3])==0)
		{
			ans=2;
			return;
		}
	}
	if (len[2]==len[4])
	{
		if ((y[2]-y[3])*(x[4]-x[1])-(y[4]-y[1])*(x[2]-x[3])!=0)
		if ((y[1]-y[2])*(x[3]-x[4])-(y[3]-y[4])*(x[1]-x[2])==0)
		{
			ans=2;
			return;
		}
	}
}
void check3()
{
	if ((x[2]-x[1])*(x[4]-x[1])+(y[2]-y[1])*(y[4]-y[1])==0) ans=8;
}
void check2()
{
	if (len[1]==len[3])
	{
		ans=4;
		check3();
	}
}
void check1()
{
	if ((len[1]==len[2]&&len[3]==len[4])||(len[1]==len[4]&&len[2]==len[3]))
	{
		ans=2;
		check2();
	}
	else if ((len[1]==len[3]&&len[2]==len[4])&&(x[2]-x[1])*(x[4]-x[1])+(y[2]-y[1])*(y[4]-y[1])==0) ans=4;
	else check4();
}
using namespace std;
int main()
{
	for (int i=1;i<=4;++i)
	cin>>x[i]>>y[i];
	len[1]=sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
	len[2]=sqrt((x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]));
	len[3]=sqrt((x[3]-x[4])*(x[3]-x[4])+(y[3]-y[4])*(y[3]-y[4]));
	len[4]=sqrt((x[4]-x[1])*(x[4]-x[1])+(y[4]-y[1])*(y[4]-y[1]));
	check1();
	cout<<ans<<endl;
}
