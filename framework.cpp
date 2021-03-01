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
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define mp make_pair
#define fr first
#define sc second


int main(int argc, char const *argv[])
{
    ifstream i("input.txt");

    int a,b;
    i>>a>>b;

    fstream f("output.txt",ios::out);
    f<<a+b<<endl;

    return 0;
}
