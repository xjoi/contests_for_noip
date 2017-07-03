#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int ans[7]={1869,6198,1896,1689,1986,1968,1698};
int main()
{
	string s;
	cin>>s;
	int a[10]={},tmp=0;
	for(int i=0;i<s.size();i++)a[s[i]-'0']++;
	a[1]--,a[6]--,a[8]--,a[9]--;
	for(int i=1;i<10;i++)while(a[i]--)cout<<i,tmp=(tmp*10+i)%7;
	cout<<ans[tmp];
	while(a[0]--)cout<<0;
	cout<<endl;
	return 0;
}
