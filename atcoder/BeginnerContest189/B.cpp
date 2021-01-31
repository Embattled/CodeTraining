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

    // 简单的数据不要用浮点数
    // 容易导致某些测试例错误
    x *= 100;
    int nowal = 0;
    int drunk = -1;
    int getVal = true;
    
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
