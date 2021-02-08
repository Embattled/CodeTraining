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
#include <iomanip>
using namespace std;

int N,M,K;
int A[11];

// 空间留足够
// n和m 都是 1e5
double da[2<<17],db[2<<17];
bool out[1<<17];
main()
{
	cin>>N>>M>>K;
	for(int i=0;i<K;i++)
	{
		cin>>A[i];
		out[A[i]]=true;
	}

	// sa sb 起始是0
	double sa=0,sb=0;

    // i >= 0
	for(int i=N;i--;)
	{
        // 是回到起点的方块 db=1
		if(out[i])db[i]=1;
		else
		{
            // da 是 sa/M +1
            // da 是 从 N点 到达该点的平均步数
            // da[N-1] = 1
			// sa 是当前步数
			da[i]=sa/M+1;

            // db 是 sb/M
            // db[N-1] = 0
			db[i]=sb/M;
		}
        // sa加上 到达当前点的期望步数
		sa+=da[i];

        // sb加上 当前 db
		sb+=db[i];

        // 减去 当前最多到达的下一方块的 da
		sa-=da[i+M];

        // 减去 当前最多到达的下一方块的 db
		sb-=db[i+M];
	}



	double ans;
	// 如果没有归零
	// 答案是 da, 说明 da 是正常的期望
	if(K==0)ans=da[0];
	// db[0]<1-1e-8 说明终点可达
	else if(db[0]<1-1e-8)
	{
		// db[0] 是回到起点的概率
		// 
		ans=da[0]/(1-db[0]);
	}
	else
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<fixed<<setprecision(16)<<ans<<endl;
}
