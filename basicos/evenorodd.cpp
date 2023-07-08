#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        int k;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        if (a < b)
        {
            k = b - a;
            if (k % 2 == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else
        {
            k = a - b;
            if (k % 2 == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
    };


    return 0;
};