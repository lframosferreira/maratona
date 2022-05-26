#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        bool isPrime = true;
        for (int j = 2; j < sqrt(k); j++)
        {
            if (k % j == 0) 
            {
                isPrime = false;
                break;
            }
        } 
        if (isPrime) cout << "Prime" << endl;
        else cout << "Not Prime" << endl;
    };
};