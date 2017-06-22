using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 101
#define r(x) scanf("%d",&x)
long long kk[N];
int k,n,m;
long long x;
bool can[100000001];
int main()
{
	r(k);cin>>x;r(n);r(m);
	if(n==1&&m==1)
	{
		kk[3]=1;
		for(int i=4;i<=k;i++)kk[i]=kk[i-1]+kk[i-2];
		if(kk[k]==x)
		{
			cout<<"A"<<endl;
			cout<<"C";
			return 0;
		}
	}
	int n1=(n)/2;
	int m1=(m)/2;
		for(kk[1]=0;kk[1]<=n1;kk[1]++)
		{
			bool flag=0;
			for(kk[2]=0;kk[2]<=m1;kk[2]++)
			{
				for(int i=3;i<=k;i++)kk[i]=0;
				{
					bool hh=0;
					for(int i=3;i<=k;i++) 
					{
						kk[i]=kk[i-1]+kk[i-2];
						if(kk[i]>x) {hh=1;break;}
					}
					if(hh) break;
//					if(kk[k]>x&&kk[2]==0){flag=1;break;}
					if(kk[k]>x) break;
					if(kk[k]==x)
					{
						for(int i=1;i<=n-kk[1]*2;i++) cout<<"H";for(int i=1;i<=kk[1];i++)cout<<"AC";cout<<endl;
						for(int i=1;i<=m-kk[2]*2;i++) cout<<"H";for(int i=1;i<=kk[2];i++)cout<<"AC";
						return 0;
					}
				}
//				if(flag) break;
			}
		}
		for(kk[1]=0;kk[1]<=n1;kk[1]++)
		{
			bool flag=0;
			for(kk[2]=0;kk[2]<=m1;kk[2]++)
			{
				for(int i=3;i<=k;i++)kk[i]=0;
				{
					bool hh=0;
					for(int i=3;i<=k;i++) 
					{
						kk[i]=kk[i-1]+kk[i-2];
						if(i!=3) kk[i]+=(i%2);
						if(kk[i]>x) {hh=1;break;}
					}
					if(hh) break;
//					if(kk[k]>x&&kk[2]==0){flag=1;break;}
					if(kk[k]>x) break;
					if(kk[k]==x&&kk[1]*2!=n&&kk[2]*2<m-1)
					{
						cout<<"H";for(int i=1;i<=n-kk[1]*2-1;i++) cout<<"H";for(int i=1;i<=kk[1];i++)cout<<"AC";cout<<endl;
						cout<<"C";for(int i=1;i<=m-kk[2]*2-2;i++) cout<<"H";for(int i=1;i<=kk[2];i++)cout<<"AC";cout<<"A";
						return 0;
					}
				}
//				if(flag) break;
			}
		}
		for(kk[1]=0;kk[1]<=n1;kk[1]++)
		{
			bool flag=0;
			for(kk[2]=0;kk[2]<=m1;kk[2]++)
			{
				for(int i=3;i<=k;i++)kk[i]=0;
				{
					bool hh=0;
					for(int i=3;i<=k;i++) 
					{
						kk[i]=kk[i-1]+kk[i-2];
						kk[i]+=(i%2);
						if(kk[i]>x) {hh=1;break;}
					}
					if(hh) break;
//					if(kk[k]>x&&kk[2]==0){flag=1;break;}
					if(kk[k]>x) break;
					if(kk[k]==x&&kk[1]*2<n-1&&kk[2]*2<m-1)
					{
						cout<<"H";for(int i=1;i<=n-kk[1]*2-2;i++) cout<<"H";for(int i=1;i<=kk[1];i++)cout<<"AC";cout<<"A"<<endl;
						cout<<"C";for(int i=1;i<=m-kk[2]*2-2;i++) cout<<"H";for(int i=1;i<=kk[2];i++)cout<<"AC";cout<<"A";
						return 0;
					}
				}
//				if(flag) break;
			}
		}
		for(kk[1]=0;kk[1]<=n1;kk[1]++)
		{
			bool flag=0;
			for(kk[2]=0;kk[2]<=m1;kk[2]++)
			{
				for(int i=3;i<=k;i++)kk[i]=0;
				{
					bool hh=0;
					for(int i=3;i<=k;i++) 
					{
						kk[i]=kk[i-1]+kk[i-2];
						if(i%2==0)kk[i]+=1;
						if(kk[i]>x) {hh=1;break;}
					}
					if(hh) break;
//					if(kk[k]>x&&kk[2]==0){flag=1;break;}
					if(kk[k]>x) break;
					if(kk[k]==x&&kk[1]*2<n&&kk[2]*2<m)
					{
						cout<<"C";for(int i=1;i<=n-kk[1]*2-1;i++) cout<<"H";for(int i=1;i<=kk[1];i++)cout<<"AC";cout<<endl;
						for(int i=1;i<=m-kk[2]*2-1;i++) cout<<"H";for(int i=1;i<=kk[2];i++)cout<<"AC";cout<<"A";
						return 0;
					}
				}
//				if(flag) break;
			}
		}
		for(kk[1]=0;kk[1]<=n1;kk[1]++)
		{
			bool flag=0;
			for(kk[2]=0;kk[2]<=m1;kk[2]++)
			{
				for(int i=3;i<=k;i++)kk[i]=0;
				{
					bool hh=0;
					for(int i=3;i<=k;i++) 
					{
						kk[i]=kk[i-1]+kk[i-2];
						kk[i]++;
						if(kk[i]>x) {hh=1;break;}
					}
					if(hh) break;
//					if(kk[k]>x&&kk[2]==0){flag=1;break;}
					if(kk[k]>x) break;
					if(kk[k]==x&&kk[1]*2<n-1&&kk[2]*2<m-1)
					{
						cout<<"C";for(int i=1;i<=n-kk[1]*2-2;i++) cout<<"H";for(int i=1;i<=kk[1];i++)cout<<"AC";cout<<"A"<<endl;
						cout<<"C";for(int i=1;i<=m-kk[2]*2-2;i++) cout<<"H";for(int i=1;i<=kk[2];i++)cout<<"AC";cout<<"A";
						return 0;
					}
				}
//				if(flag) break;
			}
		}
		for(kk[1]=0;kk[1]<=n1;kk[1]++)
		{
			bool flag=0;
			for(kk[2]=0;kk[2]<=m1;kk[2]++)
			{
				for(int i=3;i<=k;i++)kk[i]=0;
				{
					bool hh=0;
					for(int i=3;i<=k;i++) 
					{
						kk[i]=kk[i-1]+kk[i-2];
						if(i!=3)kk[i]++;
						if(kk[i]>x) {hh=1;break;}
					}
//					if(hh) break;
					if(kk[k]>x&&kk[2]==0){flag=1;}
					if(kk[k]>x) break;
					if(kk[k]==x&&kk[1]*2<n-1&&kk[2]*2<m-1)
					{
						cout<<"C";for(int i=1;i<=n-kk[1]*2-2;i++) cout<<"H";for(int i=1;i<=kk[1];i++)cout<<"AC";cout<<"H"<<endl;
						cout<<"C";for(int i=1;i<=m-kk[2]*2-2;i++) cout<<"H";for(int i=1;i<=kk[2];i++)cout<<"AC";cout<<"A";
						return 0;
					}
				}
//				if(flag) break;
			}
		}
		for(kk[1]=0;kk[1]<=n1;kk[1]++)
		{
			bool flag=0;
			for(kk[2]=0;kk[2]<=m1;kk[2]++)
			{
				for(int i=3;i<=k;i++)kk[i]=0;
				{
					bool hh=0;
					for(int i=3;i<=k;i++) 
					{
						kk[i]=kk[i-1]+kk[i-2];
						if(i==3)kk[i]++;
						if(kk[i]>x) {hh=1;break;}
					}
//					if(hh) break;
					if(kk[k]>x&&kk[2]==0){flag=1;}
					if(kk[k]>x) break;
					if(kk[k]==x&&kk[1]*2<n&&kk[2]*2<m)
					{
						for(int i=1;i<=n-kk[1]*2-2;i++) cout<<"H";for(int i=1;i<=kk[1];i++)cout<<"AC";cout<<"A"<<endl;
						cout<<"C";for(int i=1;i<=m-kk[2]*2-2;i++) cout<<"H";for(int i=1;i<=kk[2];i++)cout<<"AC";;
						return 0;
					}
				}
//				if(flag) break;
			}
		}
		cout<<"Happy new year!";return 0;
}
