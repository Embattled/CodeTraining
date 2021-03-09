#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/* 
Problem Statement

2N
players, labeled 1 through 2N, will compete against each other in a single-elimination programming tournament.
The rating of Player i is Ai

. Any two players have different ratings, and a match between two players always results in the victory of the player with the higher rating.

The tournament looks like a perfect binary tree.
Formally, the tournament will proceed as follows:

    For each integer i=1,2,3,…,N

in this order, the following happens.

    For each integer j(1≤j≤2N−i)

, among the players who have never lost, the player with the (2j−1)-th smallest label and the player with the 2j

        -th smallest label play a match against each other.

Find the label of the player who will take second place, that is, lose in the final match.
Constraints

    1≤N≤16
    1≤Ai≤109
    Ai  are pairwise different.
    All values in input are integers.


*/


// int main(int argc, char const *argv[])
int main()
{
    int n;
    cin >> n;
    // int label[1 << n];
    pair<int, int> label[1 << n];

    for (int i = 0; i < (1 << n); i++)
    {
        cin >> label[i].first;
        label[i].second = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int range = 1 << (n - i);

        if (i != n)
            for (int j = 0; j < range; j++)
            {
                label[j] = label[2 * j].first > label[2 * j + 1].first ? label[2 * j] : label[2 * j + 1];
            }
    }
    cout << (label[0].first > label[1].first ? label[1].second + 1 : label[0].second + 1) << endl;
    
}
