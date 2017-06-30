# 比赛中解决的问题
## A 
>  主要算法:暴力
### Problem description
>  输入n个数，当第i个数和第i-1个数的差大于c时，这个数之前的数全部清空，求最后剩下的数

### Solution
>  直接暴力

### Code
```cpp
  cin>>x; sum=1;
  for (int i=2;i<=n;++i){
    cin>>y; if (y-x>c) sum=1; else sum++; x=y;
  }
```
*****


## B
> 主要算法：暴力，字符串
### Problem description
> 输入一个字符串，其中含有问号和大写字母，问号代表任何大写字母，求是否能使字符串中含有26个连续字母中对应A-Z，并输出处理后字符串

### Solution
> 循环0-（length-26），暴力求出以此位之后26个字母是否符合

### Code
```cpp
  for (int j=i;j<i+26;++j) 
    if (str[j]>='A'&&str[j]<='Z') bo[str[j]-'A']=1; else sum++;
  for (int j=0;j<26;++j) if (!bo[j]) a[++tot]=j;
  if (sum<tot) continue;
```
*****

## C
> 主要算法：数学
### Problem description
> 最开始给你一个数字x = 2，有两种操作：

> 第一种是+操作， 每操作一次可以让x + 一次k，可以操作无数次，k为当前等级，k的等级最开始为1；

> 第二种操作是开方，即把x开方，开方之后，你的等级k就会上升一个等级，即k++；并且这时候你开方得到的数字必须是k+1之后的倍数 ，要让自己的等级k == n +1，问你每上升一级，要按多少次+；

### Solution
> 通过对小数据的探究

>第一关 2+1*2=4 sqrt(4)=2=1*2

>第二关 2+2*17=36 sqrt(36)=6=2*3

>第三关 6+3*46=144 sqrt(144)=12=3*4

>由此我们可以大胆猜测，每次的步数就是k*(k+1)*(k+1)-(k-1)

### Code
```cpp
   for(i=2;i<=n;i++) cout<<(i+1)*(i+1)*i-i+1<<endl;
```
*****

# 赛后补题
## D
>主要算法：最短路
### Problem description
> 已知最短路长度，部分边权，求剩下的未知边权

### Solution
> 首先把边权为0的边用vector存起来，其他该怎么建怎么建，然后跑一遍dij，如果最短路小于L，那么其他的0边无论怎么变化，最短路不会变化，这时输出NO，如果等于L，直接输出这个图，vector里面的0边搞成INF输出就行了。

>最短路大于L的情况，这时就需要添加0边来看是否能找到最短路等于L的方案。具体的实现方法是把vector存的边一条一条的添加进原图中，添加的时候边权设为1。添加一条跑一次dij，如果添加到某条边使得最短路<=L，把最后添加进的这条边的权值加上L-dis[t]，然后记录下这条边在vector的位置，输出这个图，剩余的0边权值改为INF输出即可。如果添加了所有边进去还是找不到最短路<=L的方案，那么就不存在方案，输出NO。(摘自某大佬博客）

### Code
```cpp
void dij()      ///堆优化dij  
{  
    for(int i = 0;i < N;i++) dis[i] = INF,vis[i] = false;  
    dis[s] = 0;  
    priority_queue<Node> q;  
    q.push(Node(s,0));  
    while(!q.empty()){  
        Node u = q.top();  
        q.pop();  
        if(vis[u.id]) continue;  
        vis[u.id] = true;  
        for(int i = head[u.id];i != -1;i = E[i].next){  
            int v = E[i].v;  
            if(!vis[v] && dis[v] > dis[u.id]+E[i].w){  
                dis[v] = dis[u.id]+E[i].w;  
                q.push(Node(v,dis[v]));  
            }  
        }  
    }  
}  
  
int main()  
{  
    memset(head,-1,sizeof head);  
    cin>>n>>m>>L>>s>>t;
    for(int i = 1;i <= m;i++){  
        int u,v;  LL w;  
        cin>>u>>v>>w;
        if(w!=0){  
            add(u,v,w); add(v,u,w);  
        }  
        else{  
            node edge;  
            edge.u = u,edge.v = v,edge.w = w,edge.next = -1;  
            V.push_back(edge);  
        }  
    }  
    dij();  
    if(dis[t] < L){     
        puts("NO");  return 0;  
    }  
    else if(dis[t] == L){ 
        puts("YES");  
        for(int i = 0;i < top;i += 2){  
            cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<endl;
        }  
        for(int i = 0;i < V.size();i++){  
            cout<<V[i].u<<" "<<V[i].v<<" "<<V[i].w<<endl;
        }  
    }  
    int pos = -1;  
    for(int i = 0;i < V.size();i++){  
        add(V[i].u,V[i].v,1);  
        add(V[i].v,V[i].u,1);  
        dij();  
        if(dis[t] <= L){  
            E[top-2].w += L-dis[t];  
            E[top-1].w += L-dis[t];  
    		pos = i;  break;  
        }  
    }  
    if(pos == -1){  
        puts("NO");  
        return 0;  
    }  
    puts("YES");  
    for(int i = 0;i < top;i += 2){  
        cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<endl;
    }  
    for(int i = pos+1;i < V.size();i++){  
        cout<<E[i].u<<" "<<E[i].v<<" "<<INF<<endl;
    }  
    return 0;  
}  

```
*****

## E
### Problem description
> 

### Solution
> 
