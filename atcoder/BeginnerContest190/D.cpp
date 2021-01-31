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
    long long N;
    cin >> N;

    N *= 2;

    long long ans = 0;

    vector<long long> d;

    for (long long i = 1; i*i<N; i++)
    {
        if (N%i==0)
        {
            long long div=N/i;
            if ((i^div)&1)
            {
                ans+=2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}