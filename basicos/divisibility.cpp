#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int a, b;
    for (int i = 0;i < n; i++)
    {
        cin >> a >> b;
        if (a < b) cout << b - a << endl;
        else
        {
            int k = a / b;
            int resto = a % b;
            if (resto == 0) cout << 0 << endl;
            else cout << b*(k+1) - a << endl;
        }

    };
};