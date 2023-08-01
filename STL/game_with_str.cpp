#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int player = 1;
    while (s.length() > 1){
        int pi = -1;
        for (int i = 0; i < s.length() - 1; i++){
            if (s[i] == s[i+1]){
                if (i == 0){
                    s = s.substr(2);
                    player = 2;
                } else if (i+1 == s.length() - 1){
                    s = s.substr(0, s.length() - 2);
                } else {
                    if (pi == -1){
                        pi = i;
                    } else if (pi != -1 && s[pi - 1] != s[pi + 2]){
                        pi = i;
                    }
                }
            }
        }
        if (pi == -1) break;
        s.erase(pi, 2);
        player = player == 1 ? 2 : 1;
    }
    cout << (player == 1 ? "Yes" : "No") << endl;
    return 0;
}
