#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>

#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

long long modpow(long long a,long long p, long long m){
    i64 modpow(i64 a, i64 p, i64 m)
    {
        if (p == 0)
            return 1 % m;
        i64 t = modpow(a, p / 2, m);
        t = t * t % m;
        if (p % 2)
            t = t * a % m;
        return t;
    }
}

int main()
{
    long long n, m;
    cin >> n >> m;

    cout << modpow(10, N, M * M) / M<<endl;
     return 0;
}
