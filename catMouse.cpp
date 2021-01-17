const int kMaxRound = 200;

class Solution
{
public:
	int n;
	int m;
	vector<string> grid;

	int cache[8][8][8][8][kMaxRound];

	vector<pair<int, int>> move1[8][8];
	vector<pair<int, int>> move2[8][8];

	vector<pair<int, int>> get_move(int x, int y, int max_len) {
		vector<pair<int, int>> result;
		result.push_back({x, y});
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				if (abs(dx) + abs(dy) == 1) {
					for (int len = 1; len <= max_len; ++len) {
						int new_x = x + dx * len;
						int new_y = y + dy * len;
						if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) {
							break;
						}
						if (grid[new_x][new_y] == '#') {
							break;
						}
						result.push_back({new_x, new_y});
					}
				}
			}
		}
		return result;
	}
	int calc1(int mx, int my, int cx, int cy, int round) {
		if (round >= kMaxRound) {
			return 0;
		}
		int& result = cache[mx][my][cx][cy][round];
		if (result != -1) {
			return result;
		}
		for (const pair<int, int>& p : move1[mx][my]) {
			int x = p.first;
			int y = p.second;
			if (x == cx && y == cy) {
				continue;
			}
			if (grid[x][y] == 'F') {
				return result = 1;
			}
			if (calc2(x, y, cx, cy, round + 1)) {
				return result = 1;
			}
		}
		return result = 0;
	}
	int calc2(int mx, int my, int cx, int cy, int round) {
		if (round >= kMaxRound) {
			return 0;
		}
		int& result = cache[mx][my][cx][cy][round];
		if (result != -1) {
			return result;
		}
		for (const pair<int, int>& p : move2[cx][cy]) {
			int x = p.first;
			int y = p.second;
			if (x == mx && y == my) {
				return result = 0;
			}
			if (grid[x][y] == 'F') {
				return result = 0;
			}
			if (!calc1(mx, my, x, y, round + 1)) {
				return result = 0;
			}
		}
		return result = 1;
	}
	bool canMouseWin(vector<string>& grid, int catJump, int mouseJump)
	{
		this->grid = grid;
		n = grid.size();
		m = grid[0].size();
		int cx, cy;
		int mx, my;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				if (grid[x][y] == 'C') {
					cx = x;
					cy = y;
					grid[x][y] = '.';
				} else if (grid[x][y] == 'M') {
					mx = x;
					my = y;
					grid[x][y] = '.';
				}
			}
		}
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				move1[x][y] = get_move(x, y, mouseJump);
				move2[x][y] = get_move(x, y, catJump);
			}
		}
		memset(cache, 255, sizeof(cache));
		return calc1(mx, my, cx, cy, 0);
	}
};