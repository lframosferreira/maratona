#include <bits/stdc++.h>

int main() {
    int t;cin>>t;

    while (t--){
        int n; cin>>n;
        vector<int> v(n);
        for (int i=0;i<n;i++) {
            cin>>v.at(i);
        }
        vector<vector<int>> absdiff(n, vector<int>(n));
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                absdiff.at(i).at(j) = abs(v.at(i) - v.at(j));
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << absdiff.at(i).at(j) << " ";
            }
            cout << endl;
        }
    }



    return 0;
}
