class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
        for (int i = 0; i < classes.size(); i++)
        {
            pq.push(make_pair((classes[i][0] + 1) * 1.0 / (classes[i][1] + 1) - classes[i][0] * 1.0 / classes[i][1], i));
        }
        for (int i = 0; i < extraStudents; i++)
        {

            auto p = pq.top();
            pq.pop();

            classes[p.second][0]++;
            classes[p.second][1]++;
            pq.push(make_pair((classes[p.second][0] + 1) * 1.0 / (classes[p.second][1] + 1) - classes[p.second][0] * 1.0 / classes[p.second][1], p.second));
        }
        double ans = 0;
        for (auto &it : classes)
        {
            ans += it[0] * 1.0 / it[1];
        }
        return ans / classes.size();
    }
};