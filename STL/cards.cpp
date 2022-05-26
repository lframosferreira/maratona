#include <bits/stdc++.h>

using namespace std;

#define zero "zero"
#define one "one"

int main(){

    char c[5] = {'o', 'n', 'e', 'z', 'r'};
    int n; cin >> n;
    map<char, int> m;
    for (int i = 0; i < 5; i++){
        m.insert({c[i], 0});
    }
    char cs;
    for (int i = 0; i < n; i++){
        cin >> cs;
        m.at(cs)++;

    }

    string s = "";
    while (m.at('o') > 0 && m.at('n') > 0 && m.at('e') > 0){
        m.at('o')--; m.at('n')--; m.at('e')--;
        s += '1';
    }

    for (int i = 0; i < m.at('z'); i++){
        s += '0';
    }


    for (int i = 0; i < s.size(); i++){
        char q = s.at(i);
        if (i == s.size() - 1) cout << q;
        else cout << q << " ";
    }
    cout << endl;

    return 0;
};