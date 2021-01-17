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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> data;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        data[a[i]]++;
    }
    int nowNum = 0;
    while (k != 0&&nowNum<n)
    {
        if (data[nowNum] >= k)
        {
            nowNum++;
        }
        else
        {
            sum += nowNum * (k - data[nowNum]);
            k = data[nowNum];
            nowNum++;
        }
    }
    cout << sum << endl;
    return 0;
}
