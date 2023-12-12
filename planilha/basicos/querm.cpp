#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    int c = 1;
    while (cin >> n)
    {
        if (n == 0) break;

        int k;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (k == i + 1)
            {
                cout << "Teste " << c << endl;
                cout << k << endl;
                cout << endl;
                c++;
            }
        }
    };
};