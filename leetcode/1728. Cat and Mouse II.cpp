/* 
A game is played by a cat and a mouse named Cat and Mouse.

The environment is represented by a grid of size rows x cols, where each element is a wall, floor, player (Cat, Mouse), or food.

    Players are represented by the characters 'C'(Cat),'M'(Mouse).
    Floors are represented by the character '.' and can be walked on.
    Walls are represented by the character '#' and cannot be walked on.
    Food is represented by the character 'F' and can be walked on.
    There is only one of each character 'C', 'M', and 'F' in grid.

Mouse and Cat play according to the following rules:

    Mouse moves first, then they take turns to move.
    During each turn, Cat and Mouse can jump in one of the four directions (left, right, up, down). They cannot jump over the wall nor outside of the grid.
    catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time, respectively. Cat and Mouse can jump less than the maximum length.
    Staying in the same position is allowed.
    Mouse can jump over Cat.

The game can end in 4 ways:

    If Cat occupies the same position as Mouse, Cat wins.
    If Cat reaches the food first, Cat wins.
    If Mouse reaches the food first, Mouse wins.
    If Mouse cannot get to the food within 1000 turns, Cat wins.

Given a rows x cols matrix grid and two integers catJump and mouseJump, return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.
*/


class Solution
{
public:
	int n;
	int m;
	vector<string> grid;
	const int kMaxRound = 200;
	int cache[8][8][8][8][kMaxRound];

	// 各自64个 vector<pair>
	// 代表从一点出发可以到达的下一点
	vector<pair<int, int>> movebuf[2][8][8];

	// 获得可移动点位
	vector<pair<int, int>> get_move(int x, int y, int max_len)
	{
		vector<pair<int, int>> result;
		result.push_back({x, y});

		int direction[]{1, 0, -1, 0, 1};
		for (int i = 0; i < 4; i++)
		{
			int dx = direction[i];
			int dy = direction[i + 1];

			for (int len = 1; len <= max_len; ++len)
			{
				int new_x = x + dx * len;
				int new_y = y + dy * len;
				if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
				{
					break;
				}
				if (grid[new_x][new_y] == '#')
				{
					break;
				}
				result.push_back({new_x, new_y});
			}
		}
		return result;
	}
	int cal(int mx, int my, int cx, int cy, int round, int catmouse)
	{
		if (round >= kMaxRound)
		{
			return 0;
		}
		int &result = cache[mx][my][cx][cy][round];
		if (result != -1)
		{
			return result;
		}
		int nmx, nmy, ncx, ncy, tx, ty;
		if (catmouse == 1)
		{
			tx = mx;
			ty = my;
			ncx = cx;
			ncy = cy;
		}
		else
		{
			tx = cx;
			ty = cy;
			nmx=mx;
			nmy=my;
		}

		for (const pair<int, int> &p : movebuf[catmouse][tx][ty])
		{
			int x = p.first;
			int y = p.second;

			if (catmouse == 1)
			{
				if (x == cx && y == cy)
				{
					continue;
				}
				nmx = x;
				nmy = y;
			}
			else
			{
				if (x == mx && y == my)
				{
					return result = 0;
				}
				ncx = x;
				ncy = y;
			}
			if (grid[x][y] == 'F')
			{
				return result = catmouse;
			}
			if (cal(nmx, nmy, ncx, ncy, round + 1, 1 - catmouse) == catmouse)
			{
				return result = catmouse;
			}
		}
		return result = 1 - catmouse;
	}
	bool canMouseWin(vector<string> &grid, int catJump, int mouseJump)
	{
		this->grid = grid;
		n = grid.size();
		m = grid[0].size();
		int cx, cy;
		int mx, my;
		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < m; ++y)
			{
				if (grid[x][y] == 'C')
				{
					cx = x;
					cy = y;
					grid[x][y] = '.';
				}
				else if (grid[x][y] == 'M')
				{
					mx = x;
					my = y;
					grid[x][y] = '.';
				}
			}
		}
		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < m; ++y)
			{
				// 1 mouse
				movebuf[1][x][y] = get_move(x, y, mouseJump);
				// 0 cat
				movebuf[0][x][y] = get_move(x, y, catJump);
			}
		}
		// 整个cache 置-1
		memset(cache, 255, sizeof(cache));
		return cal(mx, my, cx, cy, 0, 1);
	}
};
