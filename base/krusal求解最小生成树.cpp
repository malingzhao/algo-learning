#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
//INF 表示一个大数 用于表示无法找到最小生成树的情况
const int N = 100010, M = 200010, INF = 0x3f3f3f3f;
int n, m;
int p[N];

struct Edge {
    int a, b , w;
    //对边按照权重进行排序
    bool operator< (const Edge &W) const {
        return w  < W.w;
    }

}edges[M];

//并查集相关函数 实现压缩路径的查找操作 找到x 所属的集合
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    sort(edges, edges + m);

    //每个节点成为一个集合
    for(int i=1 ; i <= n ; i++) p[i] = i;

    int res = 0, cnt = 0;

    //遍历每条边，尝试每个边都加入生成树
    for(int i=0; i < m;i ++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        //使用find 函数 判断两条边是否属于同一个集合
        a = find(a), b = find(b);
        if(a != b){
            //如果不是属于一个集合， 则将这条边加入到生成树，并将两个集合合并
            p[a] = b;
            res += w;
            cnt ++;
        }
    }
    if(cnt  < n - 1) return INF;
    return res;
}



int  main(){
    scanf("%d%d",&n, &m);
    for(int i=0; i < m ; i++){
        int a, b,w ;
        scanf("%d%d%d",&a, &b , &w);
        edges[i] = {a, b, w};
    }
    int t = kruskal();
    if(t == INF) puts("impossible");
    else printf("%d", t);
    return 0;
}



