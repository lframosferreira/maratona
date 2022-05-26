#include <bits/stdc++.h>

using namespace std;

#define MULT " x "
#define SUM " + "

/* NAO CONSEGUI */

int main()
{
    int n; cin >> n;
    string mult;
    for (int i = 0; i < n; i++)
    {
        vector<int> va;
        vector<int> vb;
        int a, b; cin >> a >> b;
        int div = 10;
        while (a >= 1 || a <= -1)
        {   
            if (a % div != 0) va.push_back(a % div);
            a -= a % div;
            div *= 10;
        }
        div = 10;
        while (b >= 1 || b <= -1)
        {
            if (b % div != 0) vb.push_back(b % div);
            b -= b % div;
            div *= 10;
        }

        string res = "";
        int c = 0;
        for (auto e1 : va)
        {
            for (auto e2 : vb)
            {   
                c++;
                res += to_string(e1) + MULT + to_string(e2);
                if (c != va.size()*vb.size()) res += SUM;
            }
            
        }
        cout << res << endl;

    };

    return 0;
};