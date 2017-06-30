#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype> 
#include<queue>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const int N=305;
int n,k,n1,n2;
struct node
{
    int x,y,z;
    node(){}
    node(int x0,int y0,int z0)
	{
		x=x0;
		y=y0;
		z=z0;
	}
};
LL dis[50][50][2],way[50][50][2],C[55][55];
queue<node> qu;
void prepare()
{
    for(int i=0;i<=50;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<=i;j++)
        	C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
}
LL cal(int x,int y,int z,int i,int j)
{
    return (way[x][y][z]*C[x][i]%MOD*C[y][j]%MOD);
}
void work()
{
    node t=node(n1,n2,0);
    dis[n1][n2][0]=0;
    way[n1][n2][0]=1;
    qu.push(t);
    int x,y,z,x0,y0,z0;
    while(!qu.empty())
    {
        x=qu.front().x;
		y=qu.front().y;
		z=qu.front().z;
		qu.pop();
        for(int i=0;i<=x;i++)
        {
            if(i*100>k)
				break;
            for(int j=0;j<=y;j++)
            {
                if((i==0&&j==0)||(i*100+j*50>k))
					continue;
                x0=n1-x+i; y0=n2-y+j; z0=1-z;
                if(dis[x0][y0][z0]==-1)
                {
                    qu.push(node(x0,y0,z0));
                    dis[x0][y0][z0]=dis[x][y][z]+1;
                    way[x0][y0][z0]=cal(x,y,z,i,j);
                }
                else
                	if(dis[x0][y0][z0]==dis[x][y][z]+1)
					   	way[x0][y0][z0]=(way[x0][y0][z0]+cal(x,y,z,i,j))%MOD;
            }
        }
    }
    cout<<dis[n1][n2][1]<<endl;
    cout<<way[n1][n2][1]<<endl;
}
int main()
{
    int x;
    scanf("%d%d",&n,&k);
    prepare();
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==100)
			n1++;
		else
			n2++;
    }
    work();
    return 0;
}
