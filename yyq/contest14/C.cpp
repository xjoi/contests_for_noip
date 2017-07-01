#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
        if(i==1)
            printf("2\n");
        else
            cout<<(ll)(i+1)*(i+1)*i-(i-1)<<endl;
    }
    return 0;
}
