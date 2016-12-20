//
//  main.cpp
//  POJ2387 Til the Cows Come Home
//
//  Created by Irony Jian on 12/20/16.
//  Copyright © 2016 Irony Jian. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define N 1005
#define T 2005
#define INF 1<<30
using namespace std;

class Node
{public:
    int id;
    int w;
    Node(int kid,int kw);
};

Node::Node(int kid,int kw)
{
    id=kid;
    w=kw;
}
int dis[T];
bool visit[N];
vector<vector<Node>> v;
struct cmp
{
    bool operator()(int p1, int p2)
    {
        return dis[p1]>dis[p2];
    }
};

priority_queue<int,vector<int>,cmp> pq;


void dijkstra_heap(){
    int p;
    dis[1]=0;
    pq.push(1);
    while(!pq.empty())
    {
        p=pq.top();
        visit[p]=true;
        pq.pop();
        for(int i=0;i<v[p].size();i++){
            Node k=v[p][i];
            if(!visit[k.id]&&(k.w+dis[p]<dis[k.id]))
            {
                dis[k.id]=k.w+dis[p];
                pq.push(k.id);
            }
        }
           
    }
}

int main() {

    int n,t;
    int a,b,c;
    cin>>n>>t;
    v.clear();
    v.resize(n+3);
    for(int i=0;i<=n;i++) visit[i]=false;
    for(int i=0;i<=n;i++) dis[i]=INF;
    
    
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back(Node(b,c));
    }
    
    dijkstra_heap();
    cout<<dis[n];
    return 0;
}





