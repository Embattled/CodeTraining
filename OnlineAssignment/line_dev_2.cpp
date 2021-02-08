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
#include <sstream>
#include <ctime>
using namespace std;

double speedmin = 10000 / 60;
int caldcost(int dist)
{
    if (dist < 100)
    {
        return 300;
    }
    else if (dist < 1000)
    {
        return 600;
    }
    else if (dist < 10000)
    {
        return 900;
    }
    return 1200;
}
void printDate(vector<string> &info)
{
    cout << info[0] << " " << info[1] << " ";
}

std::tm createtm(vector<string> &info)
{
    std::tm t;

    t.tm_year = stoi(info[0].substr(0, 4)) - 1900;
    t.tm_mon = stoi(info[0].substr(5, 2));

    int h = stoi(info[1].substr(0, 2));
    int d = stoi(info[0].substr(8, 2));
    if (h == 24)
    {
        d++;
        h = 0;
    }
    t.tm_mday = d;
    t.tm_hour = h;
    t.tm_min = stoi(info[1].substr(3, 2));

    t.tm_sec = 0;
    mktime(&t);
    return t;
}

class income
{
public:
    // 2020-03-04 09:33
    std::tm t;
    string data;
    string hm;
    int money;

    income(vector<string> &info, int m)
    {
        data = info[0];
        hm = info[1];
        t = createtm(info);
        money = m;
    };
};

class mtime
{
public:
    int h;
    int m;
    mtime(){
        h=0;
        m=0;
    }
    mtime(int h, int m)
    {
        this->h = h;
        this->m = m;
    };
    mtime(string t)
    {

        h = stoi(t.substr(0, 2));
        m = stoi(t.substr(3, 2));
    };
};

class cloTime
{
public:
    mtime s;
    mtime e;
    cloTime(string w)
    {
        s = mtime(w.substr(0, 5));
        e = mtime(w.substr(6));
    };
};

class restau
{
public:
    string id;
    mtime closet;
    pair<int, int> loc;
    vector<income> inlist;
    vector<cloTime> clolist;

    restau(){

    };
    restau(vector<string> &info)
    {
        int n = info.size();
        this->id = info[0];
        loc.first = stoi(info[1]);
        loc.second = stoi(info[2]);
        if(n>3)
        for (int i = 3; i < n; i++)
        {
            // clolist.push_back(cloTime(info[i]));
        }
    };
    ~restau(){

    };
    void order(vector<string> &info);
    int caldist(int x, int y)
    {
        return abs(x - loc.first) + abs(y - loc.second);
    }
    void addIncom(vector<string> &info, int money)
    {
        inlist.push_back(income(info, money));
    }
    int calsales(vector<string> &info);
};

class deliv
{
public:
    string id;

    // 1 = available
    // 0 = unavailable
    int status;
    int maxdt;
    vector<income> inlist;

    pair<int, int> loc;

    void setst();
    deliv()
    {
        status = 0;
        maxdt = 0;
    };
    void setmdt(int mdt)
    {
        maxdt = mdt;
    }
    void setav(vector<string> &info)
    {
        status = 1;
        id = info[3];
        loc.first = stoi(info[4]);
        loc.second = stoi(info[5]);
    };
    int setun()
    {
        if (status != 1)
        {
            return 0;
        }
        else
        {
            status = 0;
        }
        return 1;
    };
    int caldist(int x, int y)
    {
        return abs(x - loc.first) + abs(y - loc.second);
    }
    void addIncom(vector<string> &info, int money)
    {
        inlist.push_back(income(info, money));
    }
    int calwages(vector<string> &info);
};
unordered_map<string, deliv> dlist;
unordered_map<string, restau> rlist;

void restau::order(vector<string> &info)
{

    int cost = stoi(info[4]);
    int aimx = stoi(info[5]);
    int aimy = stoi(info[6]);

    int minDist = INT_MAX;
    string dil = "";

    for (auto &p : dlist)
    {
        deliv &dili = p.second;
        if (dili.status == 1)
        {

            int sumdist = dili.caldist(this->loc.first, this->loc.second) + this->caldist(aimx, aimy);

            // cout<<"speed:"<<speedmin<<endl;
            // cout<<"time"<<(sumdist / speedmin)<<endl;
            // cout<<"limit:"<<dili.maxdt<<endl;
            if (dili.maxdt != 0 && (sumdist / speedmin) > dili.maxdt)
                continue;

            // cout<<"Dist: "<<sumdist<<endl;
            if (sumdist < minDist)
            {
                dil = dili.id;
                minDist = sumdist;
            }
        }
    }
    if (dil != "")
    {
        int sala = caldcost(minDist);
        dlist[dil].status = 0;
        cout << info[0] << " " << info[1] << " " << dil << " " << sala << endl;
        dlist[dil].addIncom(info, sala);
        this->addIncom(info, cost - sala);
    }
    else
    {
        // cout<<"ERROR CLOSED TIME"<<endl;
        cout << info[0] << " " << info[1] << " "
             << "ERROR NO DELIVERY PERSON" << endl;
    }
}
int deliv::calwages(vector<string> &info)
{
    vector<string> a;
    a.push_back(info[4]);
    a.push_back(info[5]);
    vector<string> b;
    b.push_back(info[6]);
    b.push_back(info[7]);

    std::tm start_tm = createtm(a);
    std::tm end_tm = createtm(b);

    int sum = 0;
    for (auto &inc : this->inlist)
    {
        // cout<<asctime(&start_tm)<<endl;
        // cout<<asctime(&inc.t)<<endl;
        // cout<<asctime(&end_tm)<<endl;

        double s = difftime(mktime(&inc.t), mktime(&start_tm));
        // double s = difftime(mktime(&start_tm), mktime(&inc.t));

        double e = difftime(mktime(&end_tm), mktime(&inc.t));
        // cout<<s<<"  "<<e<<endl;

        if (s >= 0 && e > 0)
        {
            sum += inc.money;
        }
    }
    return sum;
}
int restau::calsales(vector<string> &info)
{
    vector<string> a;
    a.push_back(info[4]);
    a.push_back(info[5]);
    vector<string> b;
    b.push_back(info[6]);
    b.push_back(info[7]);

    std::tm start_tm = createtm(a);
    std::tm end_tm = createtm(b);

    int sum = 0;
    for (auto &inc : this->inlist)
    {
        // cout<<asctime(&start_tm)<<endl;
        // cout<<asctime(&inc.t)<<endl;
        // cout<<asctime(&end_tm)<<endl;

        double s = difftime(mktime(&inc.t), mktime(&start_tm));
        // double s = difftime(mktime(&start_tm), mktime(&inc.t));

        double e = difftime(mktime(&end_tm), mktime(&inc.t));
        // cout<<s<<"  "<<e<<endl;

        if (s >= 0 && e > 0)
        {
            sum += inc.money;
        }
    }
    return sum;
}
vector<string> sepCom(string line)
{
    vector<string> res;
    stringstream ist(line);
    do
    {
        std::string substr;
        ist >> substr;
        res.push_back(substr);
        // std::cout << substr << std::endl;
    } while (ist);
    return res;
}
void opCom(string line)
{
    auto info = sepCom(line);

    if (info[2] == "set_available")
    {
        dlist[info[3]].setav(info);
    }
    else if (info[2] == "set_unavailable")
    {
        if (!dlist[info[3]].setun())
        {
            printDate(info);
            cout << "ERROR CANNOT SET UNAVAILABLE" << endl;
        }
    }
    else if (info[2] == "set_max_delivery_time")
    {
        dlist[info[3]].setmdt(stoi(info[4]));
    }
    else if (info[2] == "order")
    {
        // cout<<"In order"<<endl;
        rlist[info[3]].order(info);
    }
    else if (info[2] == "calculate_sales")
    {
        int put = rlist[info[3]].calsales(info);
        printDate(info);
        cout << "SALES " << put << endl;
    }
    else if (info[2] == "calculate_wages")
    {
        int put = dlist[info[3]].calwages(info);
        printDate(info);
        cout << "WAGES " << put << endl;
    }
}
int main()
{
    // vector<string> testTm;
    // testTm.push_back("2020-03-04");
    // testTm.push_back("24:00");
    // tm t=createtm(testTm);
    // cout<<asctime(&t);
    // return 0;

    int m;
    cin >> m;
    string line;
    getline(cin, line);

    unordered_map<string, deliv> dlist;
    // cout<<"m:"<<m<<endl;
    for (int i = 0; i < m; i++)
    {
        getline(cin, line);
        auto info = sepCom(line);
        rlist[info[0]] = restau(info);
    }
    while (getline(cin, line))
    {
        // cout<<"in:"<<line<<endl;
        opCom(line);
    }

    return 0;
}
