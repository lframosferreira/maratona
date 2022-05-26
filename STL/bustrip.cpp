#include <bits/stdc++.h>

using namespace std;

#include <string>

int main(){

    int k; cin >> k;
    vector<int> v;
    int s = 0;
    int c = 0;
    for (int i = 0; i < 12; i++) {
        int ai;
        cin >> ai;
        v.push_back(ai); 
    }
    sort(v.begin(), v.end());
    for (auto it = v.rbegin(); it != v.rend(); it++){
        if (s >= k) break;
        s+=*it;
        c++;
        
    }
    if (s < k) cout << -1 << endl;
    else cout << c << endl;
    return 0;
};