#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define ft first
#define sd second

// solution1  DFS
/*
void dfs(vector<vector<int>> &dist,vector<vector<int>> &road,int aim,int nowt,int nowd){

    for(int r:road[nowt]){
        if(nowd+dist[nowt][r]<dist[aim][r]){
            dist[aim][r]=nowd+dist[nowt][r];
            dfs(dist,road,aim,r,dist[aim][r]);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
    vector<vector<int>> road(n+1,vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        dist[a][b]=min(dist[a][b],c);
        road[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        int mind=dist[i][i];
        for(int r:road[i]){
            dfs(dist,road,i,r,dist[i][r]);
        }
        if(dist[i][i]==INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[i][i]<<endl;
        }
    }
    
    return 0;
}
*/

// Bellman - Ford  after_contest 超大数据超时
/*
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    vector<array<int, 3>> road(m);
    for (int i = 0; i < m; i++)
    {
        array<int, 3> r;
        cin >> r[0] >> r[1] >> r[2];

        dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2]);
        road[i] = r;
    }

    for (int i = 1; i <= n; i++)
    {
        while(true)
        {
            bool over=true;
            for (auto &r : road)
            {
                if(dist[i][r[0]]+r[2]<dist[i][r[1]]){
                    dist[i][r[1]]=dist[i][r[0]]+r[2];
                    over=false;
                }
            }
            if (over)
            {
                break;
            }
            
        }
        if(dist[i][i]!=1e9)
            cout<<dist[i][i]<<endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}
*/

// Floyd  全部超时
/*
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    vector<array<int, 3>> road(m);
    for (int i = 0; i < m; i++)
    {
        array<int, 3> r;
        cin >> r[0] >> r[1] >> r[2];

        dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2]);
        road[i] = r;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] != 1e9)
            cout << dist[i][i] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
*/


// 带权值排序的 BFS , 141 ms

// 2002个 vector<pair>
vector<pair<int, int>> G[2002];
// 优先队列，使用递增顺去， 每次取出 最小的
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
int dist[2002];
bool used[2002];

// 该算法是广度优先算法
// 而且加上了边权的排序
void solve(int s,int n)
{
    // 清空 que
    while (!que.empty())
        que.pop();

    // 列表赋初值
    for (int i = 0; i < 2002; i++)
    {
        used[i] = false;
        dist[i] = 1e9;
    }
    // 起始值设0
    dist[s] = 0;


    // 压入第一条边 0 s
    // 权值比较, 因此 pop 取出的是 weight 最小的
    // 因此不需要考虑重复搜索
    que.push(mp(0, s));
    while (!que.empty())
    {
        // 取出第一条边
        auto p = que.top();
        que.pop();

        // 如果该目标点已经被搜索过, 则不做任何操作
        if (used[p.sd])
            continue;
        used[p.sd] = true;

        // 对于从 该边目标点出发的所有边
        for (auto ed : G[p.sd])
        {
            // 如果当前距离 > 从该点到下一点
            if (dist[ed.ft] > dist[p.sd] + ed.sd)
            {
                // 替换
                dist[ed.ft] = dist[p.sd] + ed.sd;
                // 压入新边
                que.push(mp(dist[ed.ft], ed.ft));
            }
        }
    }
    int ret = 1e9;


    // 对于所有起始点
    for (int i = 1; i <= n; i++)
    {
        // 的所有边
        for (auto ed : G[i])
        {
            // 目标点如果等于 s
            if (ed.ft == s)
                // 因为 dist[s] 已经被设置成 0 
                // 进行比较 dist[i] + ed.sd 
                // s 到 i 点的距离 + i 到 s 的距离
                ret = min(ret, dist[i] + ed.sd);
        }
    }
    if (ret == 1e9)
        cout << "-1" << endl;
    else
        cout << ret << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 存入 vector<pair>
        G[a].push_back(mp(b, c));
    }
    for (int i = 1; i <= n; i++)
        solve(i,n);
}