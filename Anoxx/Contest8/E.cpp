#include<cstdio>
#include<algorithm>
#define db double
using namespace std;
struct node{
	db x1,x2,y1,y2;
}a[400][1000];
int n,k;
db y[400],ans[400],jx;
int cnt[400];
db cross(db y1,db y2,db y3,db y4){
	if(y1<=y3&&y2<=y4||y1>=y3&&y2>=y4)return 0;
	if(y2+y3-y1-y4==0)return 0;
	db xxx=(y3-y1)/(y2+y3-y1-y4);
	return xxx<0?-xxx:xxx;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)cnt[i]=1,a[i][0].x1=i-1,a[i][0].x2=i;
	for(int i=1;i<=n;i++){
		scanf("%lf",&y[0]);
		for(int j=1;j<=k;j++){
			scanf("%lf",&y[j]);
			int p=cnt[j];
			for(int l=0;l<p;l++){
				db y1=(y[j]-y[j-1])*(a[j][l].x1-j+1)+y[j-1];
				db y2=(y[j]-y[j-1])*(a[j][l].x2-j+1)+y[j-1];
				db x1=a[j][l].x1,x2=a[j][l].x2;
				db y3=a[j][l].y1,y4=a[j][l].y2,x3=a[j][l].x1,x4=a[j][l].x2;
				//printf("%lf %lf %lf %lf %lf %lf %lf %lf\n",x1,y1,x2,y2,x3,y3,x4,y4);
				db jx=0,jy=0;
				if(x2==x1)continue;
				if(jx=cross(y1,y2,y3,y4)){
				    jx=jx*(x2-x1)+x1;
				    jy=(y2-y1)/(x2-x1)*(jx-x1)+y1;
				    //("%lf %lf\n",jx,jy);
				    if(y1<=y3){
				    	ans[i]+=(y2-y4)/2*(x2-jx);
				    	a[j][l].x2=jx;a[j][l].y2=jy;
				    	a[j][cnt[j]].x1=jx;a[j][cnt[j]].y1=jy;
				    	a[j][cnt[j]].x2=x2;a[j][cnt[j]++].y2=y2;
					}
					else{
						ans[i]+=(y1-y3)/2*(jx-x1);
						a[j][l].x1=jx;a[j][l].y1=jy;
						a[j][cnt[j]].x1=x1;a[j][cnt[j]].y1=y1;
						a[j][cnt[j]].x2=jx;a[j][cnt[j]++].y2=jy;
					}
				}
				else if(y1>=y3&&y2>=y4){
					ans[i]+=(y1-y3+y2-y4)/2*(x2-x1);
					a[j][l].x1=x1;a[j][l].x2=x2;
					a[j][l].y1=y1;a[j][l].y2=y2;
				}
				//printf("%lf\n",ans[i]);
			}
			
		}ans[i]+=1e-15;
		printf("%.10lf\n",ans[i]);
	}
	return 0;
}
