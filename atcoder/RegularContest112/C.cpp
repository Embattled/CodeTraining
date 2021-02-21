#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define mp make_pair
#define fr first
#define sc second

int n, i;

// 两个 DP buffer
int dp[100005], f[100005];

// 存储树的孩子
vector<int> a[100005];

void dfs(int x) {

	f[x] = 1;
	int i, j;

	vector<int> vf, vs;
	for (i = 0; i < a[x].size(); i++) {
		dfs(a[x][i]);
		f[x] ^= f[a[x][i]];
		if (f[a[x][i]] == 0)
			vf.push_back(dp[a[x][i]]);
		else
			vs.push_back(dp[a[x][i]]);
	}
	sort(vf.begin(), vf.end(), greater<int>());
	sort(vs.begin(), vs.end(), greater<int>());
	i = j = 0;
	dp[x] = -1;
	int t = 0;
	while (i < vf.size() && vf[i] > 0) {
		if (t == 0)
			dp[x] += vf[i];
		else
			dp[x] -= vf[i];
		i++;
	}
	while (j < vs.size()) {
		if (t == 0)
			dp[x] += vs[j];
		else
			dp[x] -= vs[j];
		j++;
		t ^= 1;
	}
	while (i < vf.size()) {
		if (t == 0)
			dp[x] += vf[i];
		else
			dp[x] -= vf[i];
		i++;
	}
}

int main() {
	cin >> n;
	for (i = 2; i <= n; i++) {
		int x;
		cin >> x;
		// 存储孩子
		a[x].push_back(i);
	}

	// 根节点从1 开始
	dfs(1);
	// 直接输出 n-dp[1]/2 ????
	cout << (n - dp[1]) / 2 << endl;
	return 0;
}
