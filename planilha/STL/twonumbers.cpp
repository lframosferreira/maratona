#include <bits/stdc++.h>

using namespace std;

#include <string>

int max(vector<int> v){
    int m = v.at(0);
    for (int i = 1; i < v.size(); i++){
        if (v.at(i) > m) m = v.at(i);
    }
    return m;
}

int main(){

    int k;
    int na; cin >> na;
    vector<int> A;
    for (int i = 0; i < na; i++){  
        cin >> k;
        A.push_back(k);
    }
    int nb; cin >> nb;
    vector<int> B;
    for (int i = 0; i < nb; i++){
        cin >> k;
        B.push_back(k);
    }

    int maxA = max(A);
    int maxB = max(B);
    cout << maxA << " " << maxB << endl;

    return 0;
};