#include <bits/stdc++.h>

using namespace std;

#include <string>

int main(){

    int n; cin >> n;
  
    int max; cin >> max;
    int k;
    for (int i = 0; i < n - 1; i++){
        cin >> k;
        if (k > max) max = k;
    }
    cout << max << endl;
    return 0;
};