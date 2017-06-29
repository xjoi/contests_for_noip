#include<cstdio>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int b[51][51][2][51][51],q[500000][4],anx,aum,num5,num10,x,n,k,h,t;
long long f[51][51][2],c[100][100];
void push(int px,int py,int pz,int i,int j,int val){
	int x=px+i,y=py+j,z=pz^1;i=abs(i),j=abs(j);
	if(anx&&val>anx)return;
	if(b[px][py][pz][x][y])return;
	
	if(pz==0)f[x][y][z]=(f[x][y][z]+(f[px][py][pz]*(c[num5-px][i]*c[num10-py][j])%MOD)%MOD)%MOD;
	else f[x][y][z]=(f[x][y][z]+(f[px][py][pz]*(c[px][i]*c[py][j])%MOD)%MOD)%MOD;
	q[++t][0]=x;q[t][1]=y;q[t][2]=z;q[t][3]=val;b[px][py][pz][x][y]=1;
	if(x==num5&&y==num10&&z==1&&!anx)anx=val;
}
void getC(){
	c[0][0]=1;
	for(int i=1;i<=90;i++)
	for(int j=0;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
}
int main(){
	getC();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		x==50?num5++:num10++;
	}
	f[0][0][0]=1;t++;
	q[t][0]=q[t][1]=q[t][2]=q[t][3]=0;b[0][0][0][0][0]=1;
	while(h<t){
		int x=q[++h][0],y=q[h][1],z=q[h][2],val=q[h][3];
		if(z==0){
			int xp=num5-x,yp=num10-y;
			for(int i=1;i<=min(yp,k/100);i++)push(x,y,z,0,i,val+1);
			for(int i=1;i<=min(xp,k/50);i++)
			for(int j=0;j<=min(yp,(k-i*50)/100);j++)
			push(x,y,z,i,j,val+1);
		}
		else{
			for(int i=1;i<=min(y,k/100);i++)push(x,y,z,0,-i,val+1);
			for(int i=1;i<=min(x,k/50);i++)
			for(int j=0;j<=min(y,(k-i*50)/100);j++)
			push(x,y,z,-i,-j,val+1);
		}
    }
    return anx==0?printf("%d\n%d",-1,0):printf("%d\n%d",anx,f[num5][num10][1]),0;
}
