#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int s; cin >> s;
        vector<int> v;
        for (int j = 0; j < s; j++){
            int k; cin >> k;
            v.push_back(k);
        }

        int min = *v.rbegin();
        int c = 0;
        for (auto it = v.rbegin() + 1; it != v.rend(); it++){
            if (*it <= min){
                min = *it;
                continue;
            }
            c++;
        }
        cout << c << endl;
    }

    return 0;
};