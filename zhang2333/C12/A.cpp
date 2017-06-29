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
long double n,m,k,mi=10000000000000000;
int ans;

int main()
{
	cin>>n>>m>>k;
	k+=1.0;
	ans=(k*m/n);
	if (ans>k-1) ans=k-1;
	cout<<ans;
}
