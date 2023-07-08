#include <bits/stdc++.h>

using namespace std;
    
int main() {
    int t;cin>>t;

    while (t--){
        int n; cin>>n;
        vector<int> v(n);
        for (int i=0;i<n;i++) {
            cin>>v.at(i);
        }
        sort(v.begin(), v.end());
        vector<int> res;
        int i=0;int j=n-1;
        while (i < j){
            res.push_back(v.at(i++));
            res.push_back(v.at(j--));
            if (i==j) res.push_back(v.at(i));
        }
        reverse(res.begin(), res.end());
        for (auto e: res) cout << e << " ";
        cout << endl;
    }

    return 0;
}
