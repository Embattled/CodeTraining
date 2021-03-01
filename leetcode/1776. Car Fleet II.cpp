// 根据网上的解法优化得到的自己的解法
#define mp make_pair
#define fr first
#define sc second

double inft = 1e20;
class Solution
{
public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars)
    {
        int n = cars.size();
        vector<double> res(n, -1);
        stack<pair<double, pair<int, double>>> carsi;

        for (int i = n - 1; i >= 0; i--)
        {
            double sp = cars[i][0];
            double ss = cars[i][1];

            while (!carsi.empty())
            {
                auto sitn = carsi.top();

                double np = sitn.fr;
                double ns = sitn.sc.fr;
                double nt = sitn.sc.sc;

                // 速度不够
                if (ns >= ss)
                {
                    carsi.pop();
                    continue;
                }
                // 速度够撞上
                if (ns < ss)
                {

                    // 计算撞击的时间
                    double t = (np - sp) / (ss - ns);

                    // 能撞上但是等不到那个时候了
                    if (t >= nt)
                    {
                        carsi.pop();
                        continue;
                    }
                    else
                    {
                        // 保存撞击时间
                        res[i] = t;
                        // 保存原本的速度的持续时间
                        carsi.push(mp(sp, mp(ss, t)));

                        break;
                    }
                }
            }
            if (res[i] == -1)
            {
                carsi.push(mp(sp, mp(ss, inft)));
            }
        }
        return res;
    }
};

// 网上搜的解法1
const int N = 100005;
const double inf = 1e20, eps = 1e-8;
struct line
{
    double x, t;
    int y;
} l[N];
class Solution2
{
public:
    vector<double> getCollisionTimes(vector<vector<int>> &c)
    {
        int n = c.size(), l1 = -1;
        vector<double> ans(n, -1);

        // 反向查找
        for (int i = n - 1; i >= 0; --i)
        {
            // s 初始为 0  代表判定的时间
            double s = 0;

            // 定义了一个点 记录当前车的信息
            line p;
            p.x = c[i][0];
            p.y = c[i][1];

            // 如果 l1 为非负
            while (l1 >= 0)
            {
                // 如果 追得上 l[l1]
                if (p.y > l[l1].y)
                {
                    // 计算追上需要的时间
                    double t = (l[l1].x - p.x) / (p.y - l[l1].y);

                    // 这个时间如果大于 前车速度的持续时间的话 则不能成为判断依据 应该继续
                    if (t + eps <= l[l1].t)
                    {
                        p.x = c[i][0];
                        ans[i] = p.t = s + t;
                        l[l1].x += l[l1].y * t;
                        l[l1].t -= t;
                        l[++l1] = p;

                        // 跳出循环
                        break;
                    }
                }
                // 追不上这个车速的话
                // 加上该车速的持续时间
                s += l[l1].t;

                // 然后计算新的位置
                p.x += p.y * l[l1].t;

                // 往前继续判断
                --l1;
            }

            // 上一个追不到 -1
            if (l1 < 0)
            {
                // 初始位置
                p.x = c[i][0];

                // 持续到世界末日
                p.t = inf;

                // l[0]=p
                l[++l1] = p;

                // 结局
                ans[i] = -1;
            }
        }

        return ans;
    }
};


// 网上搜的解法2
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        vector<double> ans(cars.size(), -1.0);
        
        // 同理倒着搜索
        for (int i=cars.size()-1;i>=0;--i) {

            // 拿到位置和速度
            double p = cars[i][0];
            double s = cars[i][1];

            // 对于其后面的所有车
            for (int j=i-1;j>=0;--j) {

                // 后方的车速
                double ss = cars[j][1];
                // 追不上的话再往前也和该 car[i] 没关系了
                if (ss <= s) break;

                // 位置差
                double dp = p - cars[j][0];
                // 速度差
                double ds = ss - s;
                // 运行时间
                double t = dp/ds;

                // 直接更新 ans[j]

                if (ans[j] < 0 || t < ans[j]) ans[j] = t; 
                // 如果  t >= ans[j] 了
                // 代表追上 i 车的时间比追上 i+k 的时间还长
                // 说明 j 车追上 i 车的时候 i 车早就合体了
                // 再往前的车也就不需要对 i 车进行考虑了
                // 因为 距离 dp　的增长是不变的 , 而 i+k 车的 ds 肯定比 i 车的 ds 要大
                // 因为肯定会有 t < ans[j] 
                else break;
            }
        }
        
        return ans;
    }
};