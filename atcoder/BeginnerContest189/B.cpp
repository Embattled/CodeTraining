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

int main()
{
    int n;
    int x;
    cin >> n >> x;
    // vector<pair<int,int>> data;

    x *= 100;
    int nowal = 0;
    int drunk = -1;
    int getVal = true;
    // cout<<n<<" "<<x<<endl;
    for (int i = 0; i < n; i++)
    {
        int v, p;
        cin >> v >> p;
        if (nowal <= x)
        {
            if (v * p + nowal > x)
            {
                drunk = i + 1;
                // getVal = false;
            }
        }
        nowal += v * p;
    }
    cout << drunk << endl;

    return 0;
}
