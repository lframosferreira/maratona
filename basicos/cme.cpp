#include <bits/stdc++.h>

using namespace std;

int main(){

    int q; cin >> q;
    int a, b, c;
    for (int i = 0; i < q; i++){
        int n; cin >> n;
        if (n == 2){
            cout << 2 << endl;
            continue;
        }
        if (n % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;

    }
    return 0;
};

