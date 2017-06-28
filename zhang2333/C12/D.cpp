#include <cstdio>  
#include <cstring> 
#include <iostream>  
#include <algorithm>  
#include <queue>  
#include <vector> 
#include <stdlib.h> 
#include <time.h>
#include <cmath>
#define eps 0.00000001
using namespace std;
long long n,k,a,t=0;

int main()
{
	while (clock()<980);
	cin>>n>>k;
	for (int i=1;i<=k;i++)
	{
		cin>>a;
		t+=a;
		if (i>1) t=max((long long)0,t-n);
	}
	cout<<t;
}
