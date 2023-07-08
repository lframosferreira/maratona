#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int res = 1;
    while (n > 0)
    {
        res *= n;
        n--;
        
    }
    cout << res;
};