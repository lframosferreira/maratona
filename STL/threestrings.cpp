#include <bits/stdc++.h>

using namespace std;

#include <string>

int main(){

    int n; cin >> n;
    string a, b, c;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        if (b == c){
            cout << "YES" << endl;
            continue;
        }
        int k = a.size();
        bool possible = true;
        for (int j = 0; j < k; j++){
            if (!(c.at(j) == a.at(j) || c.at(j) == b.at(j))){
                cout << "NO" << endl;
                possible = false;
                break;
            }
        }
        if (possible) cout << "YES" << endl;
    }

    return 0;
};