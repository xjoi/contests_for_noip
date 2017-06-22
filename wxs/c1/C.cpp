#include <bits/stdc++.h>
using namespace std;
char c[105][105];
int h[105],ans[105];
vector<int> f[105];
void add(int x,int y){
	int l=min(strlen(c[x]),strlen(c[y]));
	int i;
	for(i=0;i<l&&c[x][i]==c[y][i];i++);
	if(i==l){
		if(strlen(c[x])>strlen(c[y]))ans[1]=66666;
		return;
	}
	h[c[y][i]-96]++;
	f[c[x][i]-96].push_back(c[y][i]-96);
}
void run(){
			// for(int j=1;j<=26;j++)cout<<h[j]<<' ';cout<<endl;
	for(int x=1;x<=26;x++){
		int kkk=0;
		for (int i=1;i<=26;++i){
			if(!h[i]){
				kkk=1;
				ans[x]=i;
				// cout<<i<<endl;
				for(int j=0;j<f[i].size();++j){
					h[f[i][j]]--;
				}
				h[i]=666;
				break;
			}
		}if(!kkk)return;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",c[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			add(i,j);
			if(ans[1]==66666){
				puts("Impossible");
				return 0;
			}
		}
	}
	run();
	if(ans[26]==0)puts("Impossible");
	else for(int i=1;i<=26;i++){
		printf("%c",ans[i]+96);
	}
	return 0;
}
