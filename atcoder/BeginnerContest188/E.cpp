#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> price(n + 1);
    vector<int> maxprice(n + 1,-1E9);
    vector<vector<int>> roads(n + 1);

    int maxprofit = -1E9;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        roads[y].push_back(x);
    }
    
    for (int i = n; i >= 1; i--)
    {
        int m=max(price[i],maxprice[i]);
        for (int road : roads[i])
        {   
            maxprice[road]=max(maxprice[road],m);
        }
        // cout<<"Town:"<<i<<"  maxprice"<<maxprice[i]<<endl;
        maxprofit=max(maxprofit,maxprice[i]-price[i]);
    }
    cout<<maxprofit<<endl;

    return 0;
}
