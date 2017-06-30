#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
const int INF=1e9+7;
struct XY{int a,b,c,step;
	XY(int x,int y,int z,int s){
		a=x;b=y;c=z;step=s;
	}};
queue<XY> Q;
int C[100][100],dp[100][100][3],vis[100][100][3];
int n,k,A,B;

void INIT(){
	C[0][0]=1;
	for (int i=1;i<=50;++i){
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%INF;
	}
}

int BFS(){
	memset(vis,-1,sizeof(vis));
	while (!Q.empty()){
		int sz=Q.size(),step=0;
		while (sz--){
			XY fr=Q.front();Q.pop();
			int a=fr.a,b=fr.b,c=fr.c;
			step=fr.step;step++;
			if (c==0){
				for (int i=0;i<=a;++i)
					for (int j=0;j<=b;++j){
						if (i+j==0||i*50+j*100>k) continue;
						int tmp=dp[a][b][c]*C[a][i]%INF*C[b][j]%INF;
						if (vis[a-i][b-j][1]==-1){
							vis[a-i][b-j][1]=step;
							dp[a-i][b-j][1]+=tmp;
							dp[a-i][b-j][1]%=INF;
							Q.push(XY(a-i,b-j,1,step));
						}else if (vis[a-i][b-j][1]==step){
							dp[a-i][b-j][1]+=tmp;
							dp[a-i][b-j][1]%=INF;
						}
					}
			}else{
				for (int i=0;i<=A-a;++i)
					for (int j=0;j<=B-b;++j){
						if (i+j==0||i*50+j*50>k) continue;
						int tmp=dp[a][b][c]*C[A-a][i]%INF*C[B-b][j]%INF;
						if (vis[a+i][b+j][0]==-1){
							vis[a+i][b+j][0]=step;
							dp[a+i][b+j][0]+=tmp;
							dp[a+i][b+j][0]%=INF;
							Q.push(XY(a+i,b+j,0,step));
						}else if (vis[a+i][b+j][0]==step){
							dp[a+i][b+j][0]+=tmp;
							dp[a+i][b+j][0]%=INF;
						}
					}
			}
		}
		if (vis[0][0][1]!=-1) return step;
	}
	return -1;
}

main(){
	INIT();int x;
	cin >>n>>k;
	for (int i=1;i<=n;++i) cin >>x,x==50? ++A:++B;
	dp[A][B][0]=1;
	Q.push(XY(A,B,0,0));
	int res=BFS();
	cout <<res<<endl<<dp[0][0][1]<<endl;
	return 0;
}
