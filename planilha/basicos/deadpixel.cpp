#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int width1 = max(x, a - 1 - x);
        int height1 = b;
        int area1 = width1*height1;

        int height2 = max(y, b - 1 - y);
        int width2 = a;
        int area2 = width2*height2;

        cout << max(area1, area2) << endl;

    };
};