#include<cstdio>
#include<stack>
using namespace std;
stack<bool> a;
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int c=getchar();
		for(;c!='0'&&c!='1';c=getchar());
		c-='0'; if(!a.empty()&&(c^a.top())){
			a.pop();
		}else a.push(c);
	}
	printf("%d",a.size()); return 0;
}
