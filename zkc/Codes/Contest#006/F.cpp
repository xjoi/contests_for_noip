#include <bits/stdc++.h>
using namespace std;

struct app{
    char name[50],gender;
    string tena;
    int num1,num2;
    double pts;
};

vector<app> a;
map<string,int> team;
set<int> mao,osc;

int n,cases,m,r,s,q;
bool ispr[10001];

void primeinit() {
    memset(ispr,1,sizeof ispr);
    ispr[1]=0;
    for(int i=2;i<10000;i++) {
        if(!ispr[i]) continue;
        int j=2*i;
        while(j<=10000) {
            ispr[j]=0;
            j+=i;
        }
    }
}

bool cmp(app a,app b) {
    if(a.pts>b.pts) return true;
    else if(b.pts>a.pts) return false;
    else return strcmp(a.name,b.name)==-1;
}

void solve() {
    mao.clear();
    osc.clear();
    team.clear();
    a.clear();
    cin>>n>>m>>r;
    int j;
    for(int i=1;i<=r;i++) {
        cin>>j;
        mao.insert(j);
    }
    cin>>s;
    for(int i=1;i<=s;i++) {
        cin>>j;
        osc.insert(j);
    }
    cin>>q;
    for(int i=1;i<=q;i++) {
        int prize;
        string name;
        cin>>name>>prize;
        team[name]=prize;
    }
    for(int i=1;i<=n;i++) {
        app one;
        //scanf("%s %s %c%d%d",&one.name,&one.tena,&one.gender,&one.num1,&one.num2);
        cin>>one.name>>one.tena>>one.gender>>one.num1>>one.num2;
        one.pts=0.00;
        int pri=team[one.tena];
        if(pri==1) {
            one.pts+=36.0;
        } else if(pri==2) {
            one.pts+=27.0;
        } else if(pri==3) {
            one.pts+=18.0;
        }
        if(one.gender=='F') one.pts+=33.0;
        int no;
        for(int j=1;j<=one.num1;j++) {
            cin>>no;
            if(mao.find(no)!=mao.end()) {
                one.pts+=2.5;
            } else if(osc.find(no)!=osc.end()) {
                one.pts+=1.5;
            } else if(ispr[no]) {
                one.pts+=1.0;
            } else one.pts+=0.3;
        }
        vector<int> jnjam;
        for(int j=1;j<=one.num2;j++) {
            cin>>no;
            jnjam.push_back(no);
        }
        if(one.num2>=3){
            sort(jnjam.begin(),jnjam.end());
            one.pts+=max(0.0,(jnjam[one.num2-3]-1200.0)/100.0)*1.5;
        }
        a.push_back(one);
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<m;i++) {
        //printf("%s %.3llf\n",a[i].name,a[i].pts);
        cout<<a[i].name<<" ";
        cout<<fixed<<setprecision(3)<<a[i].pts<<endl;
    }
}

int main() {
    primeinit();
    cin>>cases;
    while(cases--) {
        solve();
    }
    return 0;
}
