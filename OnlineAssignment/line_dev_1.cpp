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
#include <cstring>

#include <iostream>
using namespace std;

// 0 down   1 left  2 up  3 right
int mov[5]{1, 0, -1, 0, 1};
int m = 0, n = 0;

int getStateNum(vector<int> &state)
{
    int res = 0;
    for (int i = 0; i < 6; i++)
    {
        res *= 10;
        res += state[i];
    }
    return res;
}

vector<int> roll(vector<int> &state, int direct)
{
    // 0 up
    // 1 south
    // 2 west
    // 3 east
    // 4 north
    // 5 down

    vector<int> newState(8);
    newState[6] = state[6] + mov[direct];
    newState[7] = state[7] + mov[direct + 1];

    switch (direct)
    {
    case 0:
        newState[0] = state[4];
        newState[1] = state[0];
        newState[2] = state[2];
        newState[3] = state[3];
        newState[4] = state[5];
        newState[5] = state[1];
        break;
    case 1:
        newState[0] = state[3];
        newState[1] = state[1];
        newState[2] = state[0];
        newState[3] = state[5];
        newState[4] = state[4];
        newState[5] = state[2];
        break;
    case 2:
        newState[0] = state[1];
        newState[1] = state[5];
        newState[2] = state[2];
        newState[3] = state[3];
        newState[4] = state[0];
        newState[5] = state[4];
        break;
    case 3:
        newState[0] = state[2];
        newState[1] = state[1];
        newState[2] = state[5];
        newState[3] = state[0];
        newState[4] = state[4];
        newState[5] = state[3];
        break;
    }
    return newState;
}

int main(int argc, char *argv[])
{
    // このコードは標準入力と標準出力を用いたサンプルコードです。
    // このコードは好きなように編集・削除してもらって構いません。
    // ---
    // This is a sample code to use stdin and stdout.
    // Edit and remove this code as you like.

    int dist[100][100][6];
    // char check[100][100][];
    unordered_set<int> check[100][100];

    // cout << "memok" << endl;
    memset(dist, 255, 60000 * sizeof(int));

    int q;
    cin >> n >> m >> q;

    for (int i = 0; i < q; i++)
    {
        int s, t, x;
        cin >> s >> t >> x;
        x--;
        dist[s][t][x] = 0;
    }

    vector<int> state{0, 1, 2, 3, 4, 5, 0, 0};
    check[0][0].insert(getStateNum(state));
    cout << getStateNum(state) << endl;
    // return 0;
    queue<vector<int>> qu;
    qu.push(state);

    int step = 1;
    dist[0][0][0] = step;
    while (!qu.empty())
    {
        step++;
        queue<vector<int>> nq;
        while (!qu.empty())
        {
            auto s = qu.front();
            qu.pop();

            for (int d = 0; d < 4; d++)
            {
                auto ns = roll(s, d);
                if (ns[6] < 0 || ns[6] >= n || ns[7] < 0 || ns[7] >= m)
                {
                    continue;
                }
                auto ins = check[ns[6]][ns[7]].insert(getStateNum(ns));

                if (!ins.second)
                {
                    continue;
                }

                if (dist[ns[6]][ns[7]][ns[0]] == 0)
                {
                    continue;
                }
                else
                {
                    if (dist[ns[6]][ns[7]][ns[0]] == -1)
                    {
                        dist[ns[6]][ns[7]][ns[0]] = step;
                    }
                    else
                    {
                        dist[ns[6]][ns[7]][ns[0]] = dist[ns[6]][ns[7]][ns[0]] > step ? step : dist[ns[6]][ns[7]][ns[0]];
                    }
                }
                nq.push(ns);
            }
        }
        qu = move(nq);
    }

    int res = INT_MAX;
    for (int i = 0; i < 6; i++)
    {
        if (dist[n - 1][m - 1][i] > 0)
        {
            res = min(res, dist[n - 1][m - 1][i]);
        }
    }
    if(res==INT_MAX){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout << res-1 << endl;
    }
    return 0;
}
