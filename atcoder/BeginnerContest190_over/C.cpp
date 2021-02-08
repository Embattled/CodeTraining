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
    int n, m;

    cin >> n >> m;
    int dish[101] = {0};

    int a[101];
    int b[101];

    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
    }

    int k;
    cin >> k;

    int c[16], d[16];

    for (int i = 0; i < k; i++)
    {
        cin >> c[i] >> d[i];
    }

    int ans=0;
    for (int cond = 0; cond < 1 << k; cond++)
    {
        int dish[101] = {0};
        for (int  man = 0; man < k; man++)
        {
            if (cond&(1<<man))
            {
                dish[c[man]]++;
            }
            else
            {
                dish[d[man]]++;
            }
        }
        int res=0;
        for (int i = 0; i < m; i++)
        {
            if(dish[a[i]]&&dish[b[i]]){
                res++;
            }
        }
        ans=res>ans?res:ans;
    }
    cout<<ans<<endl;
    return 0;
}
