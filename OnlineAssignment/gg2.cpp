#include <vector>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    int num;
    cin >> num; // Reading input from STDIN
    vector<vector<int>> distance(num + 1, vector<int>(num + 1, -1));
    vector<vector<int>> edges(num + 1);
    for (int e = 1; e < num; e++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int ans = INT_MAX;
    for (int node = 1; node <= num; node++)
    {
        int dis = 0;
        int far = 0;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            far = dis;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                int nownode = q.front();
                q.pop();
                distance[node][nownode] = dis;

                for (int edge : edges[nownode])
                {
                    if (distance[node][edge] == -1)
                    {
                        q.push(edge);
                    }
                }
            }
            dis++;
        }
        ans = min(ans, far);
    }
    cout << ans << endl;
}
