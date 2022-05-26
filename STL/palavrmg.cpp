#include <bits/stdc++.h>

using namespace std;
#include <string>

int main(){

    int n; cin >>  n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        string aux = s;
        bool possible = true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int j = 0; j < s.size() - 1; j++){
            if (!(s.at(j) < s.at(j + 1))){
                possible = false;
                cout << aux << ": N" << endl;
                break;
            }
        }
        if (possible) cout << aux << ": O" << endl;
    }

    return 0;
};