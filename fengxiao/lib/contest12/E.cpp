#include<cstdio>
#include<cstring>
#define N 1000010
using namespace std;
int n,a[N];
int f[N][2],pa[N][2],p[N],path1[N],path2[N]; //f[i][0]->a[i]放在第一个序列时第二个序列的最优值
void clear() {memset(f,-1,sizeof(f)); memset(pa,-1,sizeof(pa)); memset(p,0,sizeof(p));} 
bool judge(int t1,int t2)
{
	int i,len1=0,len2=0;
	clear();
	f[1][0]= (t2) ? 0 : n+1; f[1][1]= (t1) ? 0 :n+1;
	for(i=2;i<=n;i++) 
	{
        if(f[i-1][0]!=-1) 
		{
            if((a[i]<a[i-1]) ^ t1)  
				{pa[i][0]=0; f[i][0]=f[i-1][0];}
            if((a[i]<f[i-1][0]) ^ t2) 
				{pa[i][1]=0; f[i][1]=a[i-1];}
        }
        if(f[i-1][1]!=-1) 
		{
            if((a[i]<f[i-1][1]) ^ t1) 
                if(f[i][0]==-1 || ((a[i-1]>f[i][0]) ^ t2)) 
					{pa[i][0]=1;f[i][0]=a[i-1];}
            if((a[i]<a[i-1]) ^ t2) 
                if(f[i][1]==-1 || ((f[i-1][1]>f[i][1])^t1)) 
					{pa[i][1]=1;f[i][1]=f[i-1][1];}
        }
    }
    if(f[n][0]!=-1 || f[n][1]!=-1)
    {
		if(f[n][0]!=-1) for(int i=n,pos=0;i>=1;i--) {p[i]=pos; pos=pa[i][pos];}
		else if(f[n][1]!=-1) for(int i=n,pos=1;i>=1;i--) {p[i]=pos; pos=pa[i][pos];}
		for(i=1;i<=n;i++)
			{if(p[i]) path1[++len1]=a[i]; else path2[++len2]=a[i];}
		if(len1==0) {path1[++len1]=path2[len2--];}
		if(len2==0) {path2[++len2]=path1[len1--];}
		printf("%d %d\n",len1,len2);
		for(i=1;i<=len1;i++) printf("%d ",path1[i]); puts("");
		for(i=1;i<=len2;i++) printf("%d ",path2[i]); 
		return true;
	}
	return false;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			if(judge(i,j))
				return 0;
	puts("Fail");
	return 0;
}
